#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define MAXDATA 128
#define MAXTOKEN 64
#define MAXQTTOKEN 16
//#define MAXSEQ 64

#define MAXSERVOS 32

struct list {
	char val[MAXTOKEN];
	struct list * next;
};

typedef struct list item;

item *current, *root, *tail;

item *listAdd(char *s);
item *listInsert(char *s, item *it);

//unsigned char seq[MAXSEQ];

const char ssid[] = "Warlock";  //  your network SSID (name)
const char pass[] = "bc25fcb38b";    // your network password

const char folder[] = "/jarvis/";

#define localPort 2390
//unsigned int localPort = 2390;      // local TCP port

WiFiServer server(localPort);
WiFiClient client;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //using the default address 0x40
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41); //using the default address 0x40

#define SERVOMIN  153 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  590 // this is the 'maximum' pulse length count (out of 4096)
#define PAUSE 50

short lastpulse[MAXSERVOS];
short servomin[MAXSERVOS];
short servomax[MAXSERVOS];
bool aceleracao = 0;
bool reconectar = 1;
bool reconectarMsg = 0;
bool laser = 0;
bool isBusy = 0;

char toExecute[MAXDATA];

IPAddress ip;

/*
void printWifiStatus();
int split(char* data, const char* separador, char retorno[MAXQTTOKEN][MAXTOKEN]);
int sendData(char data[MAXTOKEN], int qt);
int offServo(short servonum);
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);

  Serial.println("J.A.R.V.I.S. (ESP8266) Loaded!");
  Serial.println("[A-P][0-180]:speed, OFF, ~[0-9999], ![0-15], ACC");

  memset(toExecute, 0, MAXDATA);
  toExecute[0] = '\0';

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  pwm2.begin();
  pwm2.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //Reseting lastpulse and mempos for all servos
  for (byte i=0;i<MAXSERVOS;i++)
  {
    lastpulse[i]=-1;

    servomin[i] = SERVOMIN;
    servomax[i] = SERVOMAX;

//    Serial.print("Servo ");
//    Serial.println(i);
  }

  // attempt to connect to Wifi network:
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  WiFi.persistent(false);
  
  Serial.println("Connected to wifi");
  printWifiStatus();

  delay(5000);

  Serial.println("\nStarting TCP server...");
  server.begin();

  Serial.print("TCP Server started at port ");
  Serial.println(localPort);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  char data[MAXDATA];
  int numero;
  bool recebeu = 0;

  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13,data,MAXDATA);
    data[numero] = 0;
    recebeu = 1;

    Serial.print("Recebeu via Serial: ");
    Serial.println(data);
  }

  if (reconectar)
  {
  	if (reconectarMsg == 0)
  	{
  	  Serial.print("Aguardando cliente...");
  	  reconectarMsg = 1;
  	}
    client = server.available();

    if (client)
    {
      Serial.println("Novo cliente");
      reconectar = 0;
    }
  }
  
  if (client)
  {
    if (client.connected())
    {
      if (client.available())
      {
    		memset(data, 0, MAXDATA);
    		client.read((unsigned char*)data, MAXDATA); // read the packet into the buffer

        recebeu = 1;
        
        Serial.print("Recebeu via TCP: ");
        Serial.println(data);
      }
    }
    else
    {
      Serial.println("Conexao interrompida");
      reconectar = 1;
    }
  }

  if (strlen(toExecute) > 0)
  {
	  strcpy(data, toExecute);

	  memset(toExecute, 0, MAXDATA);
	  toExecute[0] = '\0';

	  recebeu = 1;
  }
  
  if (recebeu)
  {
  	char tokens[MAXQTTOKEN][MAXTOKEN];
  
  	Serial.print("SizeOf tokens: ");
  	Serial.println(sizeof(tokens));

  	Serial.print("data = '");
  	Serial.print(data);
  	Serial.println("'");

    int qttokens = split(data, "|", tokens);

  	Serial.print("qttokens = ");
  	Serial.println(qttokens);
  
  	for (int idx = 0; idx < qttokens; idx++)
  	{
  		listAdd(tokens[idx]);
  	}

    Serial.println("current = root");
    
  	current = root;
  
  	while (current)
  	{
  		Serial.print("current->val = '");
  		Serial.print(current->val);
  		Serial.println("'");
  
  		//delay(PAUSE);
  
  		char recebido[MAXTOKEN];
  
  		memset(recebido, 0, MAXTOKEN);
  
  		strcpy(recebido, current->val);
  
  		if (recebido[0]=='\0')
  			break;
  
  		if (strcmp(recebido, "RESET")==0)
  		{
  			reconectar = 1;
  			reconectarMsg = 0;
  			Serial.println("RESET");
  		}
  		else if (strcmp(recebido, "BUSY") == 0)
  		{
  			char resp[2];
  
  			byte qt = sprintf(resp, "%i", isBusy);
  
  			sendData(resp, qt);
  		}
  		else if (strcmp(recebido, "OFF")==0)
  		{
  			Serial.println("ALL OFF");
    
  			for (byte i=0;i<MAXSERVOS;i++)
  			{
  				offServo(i);
  			}
  		}
  		else if (recebido[0]=='~')
  		{
  			short tempo = getValue(recebido);
  			Serial.print("DELAY: ");
  			Serial.println(tempo);
  			delay(tempo);
  		}
  		else if (recebido[0] == '^')
  		{
        /*
  			isBusy = 1;
  			char arq[MAXDATAFILE];
  
  			memset(arq, 0, MAXDATAFILE);
  
  			strcpy(arq, folder);
  			strcat(arq, &recebido[1]);

  			Serial.print("Arquivo '");
  			Serial.print(arq);
  			Serial.println("'");
  			//Serial.println("':");
  
  			//char content[MAXDATA];
  
  			Serial.println("readSeqFile");
  			int tamx = readSeqFile(arq);
  			Serial.print(tamx);
  			Serial.print(", ");
  			Serial.print(strlen((const char*)seq));
  			Serial.println();
  			Serial.print("seq='");
  			Serial.print((const char*)seq);
  			Serial.println("'");
  			Serial.println();
  
  			if (tamx >= 0)
  			{
  				//strcat(toExecute, (const char*)seq);
  
  				char xtokens[MAXQTTOKEN][MAXTOKEN];
  
  				int xqttokens = split((char *)seq, "|", xtokens);
  
  				Serial.print("xqttokens = ");
  				Serial.println(xqttokens);
  
  				item *atual = current;
  
  				for (int idx = 0; idx < xqttokens; idx++)
  				{
  					Serial.print("Inserindo '");
  					Serial.print(xtokens[idx]);
  					Serial.println("'");
  
  					Serial.print(atual->val);
  					atual = listInsert(xtokens[idx], atual);
  					Serial.print(" -> ");
  					Serial.println(atual->val);
  
  					Serial.println("inseriu!");
  				}
  
  				listPrint();
  
  				//for (int c=MAXQTTOKEN-xqttokens;)
  				//strcpy(tokens[idx], (const char*)seq);
  
  				//Serial.print("NEW tokens[");
  				//Serial.print(idx);
  				//Serial.print("] = '");
  				//Serial.print(tokens[idx]);
  				//Serial.println("'");
  
  				//idx--;
  				//Serial.print("toExecute='");
  				//Serial.print(toExecute);
  				//Serial.print("' - ");
  				//Serial.print("size toExecute: ");
  				//Serial.println(strlen(toExecute));

          }
        }
        */
      }
  		else if (recebido[0]=='!')
  		{
  			byte servo = (byte)getValue(recebido);
  			Serial.print("OFF: ");
  			Serial.println(servo);
  			offServo(servo);
  		}
  		else if (recebido[0]=='(')
  		{
  			byte servonum = getValue(recebido);
  			short minvalue = getExtraValue(recebido);
          
  			Serial.print("Servo:");
  			Serial.print(servonum);
  			Serial.print(" - MIN:");
  			Serial.println(minvalue);
    
  			servomin[servonum] = minvalue;
  		}
  		else if (recebido[0]==')')
  		{
  			byte servonum = getValue(recebido);
  			short maxvalue = getExtraValue(recebido);
          
  			Serial.print("Servo:");
  			Serial.print(servonum);
  			Serial.print(" - MAX:");
  			Serial.println(maxvalue);
    
  			servomax[servonum] = maxvalue;
  		}
  		else if (strcmp(recebido, "ACC")==0)
  		{
  			Serial.print("ACC: ");
  			if (aceleracao==1)
  			{
  				aceleracao = 0;
  			}
  			else
  			{
  				aceleracao = 1;
  			}
  			Serial.println(aceleracao);
  		}
  		else if (recebido[0]=='*')
  		{
  			isBusy = 1;
  			Serial.println("Desmembrando:");
    
  			char cmds[MAXSERVOS][16];
    
  			for (byte i=0;i<MAXSERVOS;i++)
  			{
  				cmds[i][0] = '\0';
  			}
          
  			char* dado = strtok(recebido, "*;");
    
  			int cont = 0;
          
  			while (dado!=NULL)
  			{
  				strcpy(cmds[cont], dado);
    
  				Serial.print(cont);
  				Serial.print(" = ");
  				Serial.println(cmds[cont]);
  				cont++;
            
  				dado = strtok(NULL, ";:");
          
          yield();
  			}
          
  			//Serial.println(getValue(recebido));
  			//Serial.println(getExtraValue(recebido));
  			//Serial.println("Fim!");
  			playServos(cmds);
  		}
  		else
  		{
  			isBusy = 1;
  			playServo(recebido);
  		}
  
  		Serial.print("Vai de "); 
  		Serial.print(current->val);
  
  		item *nxt = current->next;
  
  		free(current);
  
  		current = nxt;
  		//current = current->next;
  
  		Serial.print(" para ");
  		Serial.println(current->val);

      yield();
      Serial.println("yield");
  	}
  
  	root = NULL;
  	isBusy = 0;
  }
}

byte getServoNum(char c)
{
  byte ret = c;
  
  if (c >= 97) //Segunda controladora, de a (97) até p (112) ou de Q até Z (para os dez primeiros servos da segunda controladora)
  {
    ret -= 97;
    ret += 16;
  }
  else
  {
    if (c >= 65) // Primeira controladora, de A (65) até P (80)
    {
      ret -= 65;
    }
  }

  return ret;
}

short getValue(char *data)
{
    char ndata[MAXTOKEN];
    short j=0;
    
    for (short i=1;i<MAXTOKEN;i++)
    {
      if (data[i]==':')
      {
        ndata[j]='\0';
        break;        
      }
      else
      {
        ndata[j]=data[i];
      }
      j++;
    }
    short nvalor = (short)ndata[0];
    short valor = -1;
    
    if (nvalor>=65)
    {
//      valor = nvalor-65;
      valor = getServoNum(nvalor);
    }
    else
    {
      valor = (short)atoi(ndata);  
    }

    return valor;
}

int getExtraValue(char *data)
{
    char ndata[MAXTOKEN];
    int j=0;
    bool achou=0;
    
    for (int i=1;i<MAXTOKEN;i++)
    {
      if (data[i]==':')
      {
        j=0;
        ndata[j]='\0';
        achou = 1;
      }
      else
      {
        ndata[j]=data[i];
        j++;
        if (j<MAXTOKEN)
          ndata[j]='\0';
      }
    }

    int valor = atoi(ndata);

    if (!achou)
      valor = 0;
      
    return valor;
}

int playServo(char *data)
{
    byte servonum = getServoNum(data[0]);
    //int servonum = (int)data[0];

    //servonum -= 65;

    int angulo = getValue(data);
    int velocidade = getExtraValue(data);
    
    //int angulo = atoi(data);

    Serial.print(servonum);
    Serial.print(": ");
    Serial.print(angulo);
    Serial.print(" :: ");
    Serial.println(velocidade);

    moveServo(servonum, angulo, velocidade);
}

int playServos(char data[MAXSERVOS][16])
{
    short servonums[MAXSERVOS];
    short angulos[MAXSERVOS];
    short velocidade = 0;

    for (short i=0;i<MAXSERVOS;i++)
    {
      servonums[i] = -1;
      
      if ((short)data[i][0]==0)
        break;
        
      short pri = (short)data[i][0];

      if (pri>=65)
      {
        servonums[i] = getServoNum(pri);
        //servonums[i] = pri - 65;
      }
      else
      {
        velocidade = (short)atoi(data[i]);
        break;
      }
      
      angulos[i] = getValue(data[i]);
    }

    moveServos(servonums, angulos, velocidade);
}

int moveServo(int servonum, int pos, int velocidade)
{
    int pulso = -1;

    if (velocidade<=0)
      velocidade = 1;

    int pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);
	  int plold = lastpulse[servonum];
    int dif = pulselength-plold;

    /*
    Serial.print("plold/pulselength: ");
    Serial.print(plold);
    Serial.print("/");
    Serial.println(pulselength);
    */
    
    int incr = dif / velocidade;
    pulso = plold;

    if (velocidade>1)
    {
      for (int v=velocidade; v>0; v--)
      {
        if (aceleracao==1)
        {
          incr = dif / v;
          pulso = plold + incr;
        }
        else
        {
          pulso += incr;
        }

        /*
        Serial.print(v);
        Serial.print("->");
        Serial.print(pulso);
        Serial.print(" (incr: ");
        Serial.print(incr);
        Serial.println(")");
        */
        
		//if (pulso > pulselength)
		//	pulso = pulselength;

        setPWM(servonum, 0, pulso);
  
        delay(PAUSE);
      }
    }
    setPWM(servonum, 0, pulselength);

    lastpulse[servonum] = pulselength;
    
    return pulselength;
}


void moveServos(short servonums[], short poss[], short velocidade)
{
    short incrs[MAXSERVOS];

    for (short i=0; i<MAXSERVOS; i++)
    {
      incrs[i] = 0;
    }
    
    short pulso = -1;

    if (velocidade<=0)
      velocidade = 1;

    if (velocidade>1)
    {
      for (short v=velocidade; v>0; v--)
      {
    		bool pausar = 1;

        for (short k=0;k<MAXSERVOS;k++)
        {
          short servonum = servonums[k];

          if (servonum==-1)
            break;
            
          short pos = poss[k];
        
          short pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);
    		  short plold = lastpulse[servonum];
    
    		  if (pulselength == plold)
    		  {
    			  pausar = 0;
    		  	  break;
    		  }

    		  short dif = pulselength-plold;

          Serial.print(servonum);
          Serial.print("pulselength, plold, pulso -> ");
		      Serial.print(pulselength);
          Serial.print(", ");
          Serial.print(plold);
          Serial.print(", ");
          
          short incr;
          
          if (incrs[k]==0)
          {
  			    incr = dif / velocidade;

            incrs[k] = incr;
          }
          else
          {
            incr = incrs[k];
          }
          
          pulso = plold;

          if (aceleracao==1)
          {
            incr = dif / v;
            pulso = plold + incr;
          }
          else
          {
            pulso += incr;
          }

          Serial.print(pulso);
          Serial.print(" (incr: ");
          Serial.print(incr);
          Serial.println(")");

          short npos = -1;
          
          if (lastpulse[servonum]==-1) // Nao tem posicao anterior
          {
            setPWM(servonum, 0, pulselength);
            npos = map(pulselength, servomin[servonum], servomax[servonum], 0, 180);
			
      			lastpulse[servonum] = pulselength;
    		  }
          else
          {
            setPWM(servonum, 0, pulso);
            npos = map(pulso, servomin[servonum], servomax[servonum], 0, 180);
			
      			lastpulse[servonum] = pulso;
    		  }

          //Serial.print(" [");
          //Serial.print(npos);
          //Serial.println(" graus]");
        }
    		if (pausar)
    			delay(PAUSE);
      }
    }

    for (short k=0;k<MAXSERVOS;k++)
    {
      short servonum = servonums[k];
      if (servonum==-1)
        break;
        
      short pos = poss[k];
      short pulselength = map(pos, 0, 180, servomin[servonum], servomax[servonum]);

      Serial.print("Final ");
      Serial.print(servonum);
      Serial.print(": ");
      Serial.println(pulselength);
      
      setPWM(servonum, 0, pulselength);

      lastpulse[servonum] = pulselength;
    }
}

int offServo(short servonum)
{
    setPWM(servonum, 0, 0);

    lastpulse[servonum] = -1;

    return 0;
}

void setPWM(int canal, int liga, int desliga)
{
    if (canal<=15)
    {
      pwm.setPWM(canal, liga, desliga);
      /*
      Serial.print("pwm CH ");
      Serial.print(canal);
      Serial.print(", ");
      Serial.print(liga);
      Serial.print(", ");
      Serial.println(desliga);
      */
    }
    else
    {
      pwm2.setPWM(canal-16, liga, desliga); 
      /*
      Serial.print("pwm2 CH ");
      Serial.print(canal-16);
      Serial.print(", ");
      Serial.print(liga);
      Serial.print(", ");
      Serial.println(desliga);      
      */
    }
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

int getFeedback(int pino)
{
    int mean;
    int result;
    int test;
    boolean done;
    int reading[20];
     
    for (int j=0; j<20; j++){
      reading[j] = analogRead(pino);    //get raw data from servo potentiometer
      delay(3);
    }                                // sort the readings low to high in array                                
    done = false;              // clear sorting flag             
    while(done != true){       // simple swap sort, sorts numbers from lowest to highest
    done = true;
    for (int j=0; j<20; j++){
      if (reading[j] > reading[j + 1]){     // sorting numbers here
        test = reading[j + 1];
        reading [j+1] = reading[j] ;
        reading[j] = test;
        done = false;
       }
     }
   }
    mean = 0;
    for (int k=6; k<14; k++){        //discard the 6 highest and 6 lowest readings
      mean += reading[k];
    }
    result = mean/8;                  //average useful readings
    return(result);
}

int split(char* data, const char* separador, char retorno[MAXQTTOKEN][MAXTOKEN])
{
    char* dado = strtok(data, separador);

    int cont = 0;
                  
    while (dado!=NULL)
    {
  		for (int i = 0; i < MAXTOKEN; i++)
  		{
  			retorno[cont][i] = '\0';
  		}
  		
  		Serial.print("dado = '");
  		Serial.print(dado);
  		Serial.print("' size = ");
  		Serial.println(strlen(dado));
  		//Serial.print("] = ");
  		//Serial.println(retorno[cont]);
  
  		strcpy(retorno[cont], dado);
  
  		Serial.print("retorno[");
  		Serial.print(cont);
  		Serial.print("] = ");
  		Serial.println(retorno[cont]);
  		cont++;
        
  		if (cont > MAXQTTOKEN)
  			break;
  
  		dado = strtok(NULL, separador);

      yield();
    }

    return cont;
}

/*
void clearStr(char* data, int qt)
{
  for (int i=0; i<qt; i++)
  {
    data[i] = '\0';
  }
}

void clearStr(char data[MAXDATA][MAXDATA], int qt)
{
  for (int i=0; i<qt; i++)
  {
    data[i][0] = '\0';
  }
}
*/

int sendData(char data[MAXTOKEN], int qt)
{
  Serial.print("Enviando '");
  Serial.print(data);
  Serial.println("'");
  //Serial.print("' para '");
  //Serial.print(Udp.remoteIP());
  //Serial.print("':");
  //Serial.println(Udp.remotePort());

  int ret = client.write((uint8_t*)data, qt);

  /*
  for (int i=0; i++; i<MAXDATA)
  {
    char c = data[i];
    Udp.write(c);

    if (c=='\0')
      break;
  }
  */
  
  //int ret = Udp.endPacket();

  Serial.print("Retorno: ");
  Serial.println(ret);
}

item *listAdd(char *s)
{
	item *novo = (item *)malloc(sizeof(item));

	strcpy(novo->val, s);
	novo->next = NULL;

	if (root == NULL)
		root = novo;
	else
		tail->next = novo;

	tail = novo;

	return novo;
}

item *listInsert(char *s, item *it)
{
	item *novo = (item *)malloc(sizeof(item));

	if (novo == NULL)
	{
		Serial.println("malloc error!!!");
	}
	else
	{
		strcpy(novo->val, s);
		novo->next = it->next;

		it->next = novo;
	}

	return novo;
}

void listPrint()
{
	item *atual = root;

	Serial.println("-- BOL --");
	while (atual)
	{
		Serial.println(atual->val);
		atual = atual->next;

    yield();
	}
	Serial.println("-- EOL --");
}
