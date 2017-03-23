Imports System.ComponentModel

Public Class MainForm
    Dim serial As System.IO.Ports.SerialPort = Nothing
    Dim tcp As System.Net.Sockets.TcpClient = Nothing

    Public ReadOnly Property Pasta As String
        Get
            Dim pst As String = IO.Path.Combine(Application.StartupPath, "jarvis")

            Return pst
        End Get
    End Property

    Public ReadOnly Property pausaEntreEnvios As Integer
        Get
            Dim i As Integer = 0

            Integer.TryParse(txtPausaEntreEnvios.Text, i)

            Return i
        End Get
    End Property

    Private Sub MainForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        'serial.Close()
    End Sub

    Private Sub MainForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        CarregarMovimentos()

        'Enviar("Inicializado!")

        'serial = New IO.Ports.SerialPort("COM5", 9600)

        'serial.Open()
    End Sub

    Public Function CarregarPosiçõesString(ByVal arq As String) As String
        If arq.StartsWith("^") Then
            arq = arq.Substring(1)
        End If

        Dim posições() As String = CarregarPosições(arq)
        Dim paraenviar As New System.Text.StringBuilder()

        For Each pos As String In posições
            'Enviar(pos & "|")
            paraenviar.Append(pos)
            paraenviar.Append("|")
        Next

        If paraenviar.Length > 0 Then
            paraenviar = paraenviar.Remove(paraenviar.Length - 1, 1)
        End If

        Return paraenviar.ToString()
    End Function

    Public Sub Enviar(ByVal dados As String, Optional ByVal checarOcupado As Boolean = False)
        If checarOcupado Then
            Dim ocupado As String = ReceberDados("BUSY", 1)

            If ocupado <> "0" Then
                Do While ocupado <> "0"
                    ocupado = ReceberDados("BUSY", 1)
                Loop
            End If
        End If

        If dados.ToLower().Contains(".seq") Then
            Dim arqs() As String = dados.Split("|")

            For Each arq As String In arqs
                If arq.StartsWith("^") Then
                    dados = dados.Replace(arq, CarregarPosiçõesString(arq))
                End If
            Next

            Enviar(dados)
        Else
            EnviarDados(dados & "|")

            Threading.Thread.Sleep(pausaEntreEnvios)

            If Not (dados.StartsWith("(") Or dados.StartsWith(")") Or dados.Contains("|")) AndAlso dados.Contains(":") Then
                Dim stempo As String = dados.Substring(dados.IndexOf(":") + 1)
                'Stop
                'Dim pausa As Integer = 50 * Integer.Parse(stempo)
                'Threading.Thread.Sleep(pausa)
            End If
            If dados.StartsWith("~") Then
                Dim stempo As String = dados.Replace("~", "")

                Dim pausa As Integer = pausaEntreEnvios

                If Integer.TryParse(stempo, pausa) Then
                    pausa += pausaEntreEnvios
                End If

                Threading.Thread.Sleep(pausa)
            End If
        End If
    End Sub

    Public Function EnviarDados(ByVal dados As String) As Boolean
        Dim retorno As Boolean = False

        If tcp IsNot Nothing AndAlso tcp.Connected Then
            Dim bytes() As Byte = System.Text.ASCIIEncoding.ASCII.GetBytes(dados)

            Dim sr As System.Net.Sockets.NetworkStream = tcp.GetStream()

            If sr IsNot Nothing Then
                If tcp.Connected Then
                    Try
                        sr.Write(bytes, 0, bytes.Length)
                    Catch ex As Exception
                        If Not tcp.Connected Then
                            btnInicializar.PerformClick()
                        End If
                    End Try
                Else
                    btnInicializar.PerformClick()
                End If
            End If

            retorno = True
        End If

        Return retorno
    End Function

    Public Function ReceberDados(Optional ByVal cmd As String = "", Optional pauseAfterCmd As Integer = 0) As String
        If Not String.IsNullOrEmpty(cmd) Then
            EnviarDados(cmd)

            Threading.Thread.Sleep(pauseAfterCmd)
        End If

        Dim bytes(512) As Byte
        Dim s As String = ""

        Try
            tcp.GetStream().Read(bytes, 0, bytes.Length)

            If bytes IsNot Nothing Then
                s = System.Text.ASCIIEncoding.ASCII.GetString(bytes)

                s = s.Replace(Chr(0), "")
            End If
        Catch ex As Exception
            s = ex.Message
        End Try

        Return s
    End Function

    'Public Sub ReceberAsync()
    '    Dim origem As Net.IPEndPoint = udp.Client.LocalEndPoint

    '    Dim bytes() As Byte = udp.Receive(origem)

    '    Debug.Print("Recebeu!")
    'End Sub
    'Private Sub Ângulo_Scroll(sender As Object, e As EventArgs)
    '    serial.Write("K" & Ângulo.Value)
    '    Ângulo.CreateGraphics().DrawString(Ângulo.Value.ToString(), New Font("Verdana", 10), New SolidBrush(Color.Black), 0, 0)
    'End Sub

    Private Sub btnOff_Click(sender As Object, e As EventArgs) Handles btnOff.Click
        Enviar("OFF")
    End Sub

    Private Sub Servo_Scroll(sender As Object, e As EventArgs) Handles Servo1.Scroll, Servo2.Scroll, Servo3.Scroll, Servo4.Scroll, Servo5.Scroll, Servo6.Scroll, Servo7.Scroll, Servo8.Scroll, Servo9.Scroll, Servo10.Scroll, Servo16.Scroll, Servo13.Scroll, Servo15.Scroll, Servo12.Scroll, Servo11.Scroll, Servo14.Scroll
        'If serial IsNot Nothing AndAlso serial.IsOpen() Then
        'Stop
        Dim cmd As String = sender.ServoID & sender.Value.ToString()
        Debug.Print(cmd)

        'serial.Write(cmd)
        If chkAtivar.Checked Then
            Enviar(cmd)
        End If

        If sender.Selected = CheckState.Indeterminate Then
            For Each ctrl As Control In Me.Controls
                If TypeOf ctrl Is ISlider Then
                    Dim sl As ISlider = ctrl

                    If sl.Name <> sender.Name Then
                        If sl.Selected = CheckState.Checked OrElse sl.Selected = CheckState.Unchecked Then
                            'Dim dif As Integer = IIf(sl.Selected = CheckState.Checked, sender.Value - sender.PreviousValue, sender.PreviousValue - sender.Value)
                            Dim dif As Integer = 0

                            If sl.Selected = CheckState.Unchecked Then
                                dif = 180 - sender.Value
                            Else
                                dif = sl.Value + sender.Value - sender.PreviousValue

                                If dif = 0 OrElse dif = 180 Then
                                    sl.Value = sender.PreviousValue
                                End If
                            End If

                            'Debug.Print("Dif: " & dif.ToString())
                            'sl.Value += dif
                            sl.Value = dif
                        End If
                    End If
                End If
            Next
        End If
        'End If
    End Sub

    Private Sub Servo_ButtonClick(sender As Object, e As EventArgs) Handles Servo1.ButtonClick, Servo2.ButtonClick, Servo3.ButtonClick, Servo4.ButtonClick, Servo5.ButtonClick, Servo6.ButtonClick, Servo7.ButtonClick, Servo8.ButtonClick, Servo9.ButtonClick, Servo16.ButtonClick, Servo13.ButtonClick, Servo15.ButtonClick, Servo12.ButtonClick, Servo11.ButtonClick, Servo14.ButtonClick, Servo10.ButtonClick
        If lbPosições.SelectedIndex > -1 AndAlso (ModifierKeys AndAlso Keys.Shift = Keys.Shift) Then
            Dim sel As String = lbPosições.SelectedItem
            'Stop
            If Not sel.StartsWith("*") Then
                sel = "*" & sel
            End If
            sel &= ";" & sender.ServoID & sender.Value.ToString()

            lbPosições.Items(lbPosições.SelectedIndex) = sel
            'lbPosições.SelectedItem = sel
        Else
            lbPosições.Items.Add(sender.ServoID & sender.Value.ToString())
        End If
    End Sub

    Private Sub btnRegistrar_Click(sender As Object, e As EventArgs) Handles btnRegistrar.Click
        For Each ctrl As Control In Me.Controls
            If TypeOf ctrl Is Slider Then
                Dim sl As Slider = ctrl

                lbPosições.Items.Add(sl.ServoID & sl.Value)
                'lbPosições.Items.Add("WAIT300")
            End If
        Next
    End Sub

    Private Sub btnLimpar_Click(sender As Object, e As EventArgs) Handles btnLimpar.Click
        lbPosições.Items.Clear()
    End Sub

    Private Sub btnGravar_Click(sender As Object, e As EventArgs) Handles btnGravar.Click
        Dim nome As String = InputBox("Digite o nome do movimento:")
        Dim arq As String = IO.Path.Combine(Me.Pasta, nome & ".seq")

        Dim sw As New IO.StreamWriter(arq)

        For Each pos As String In lbPosições.Items
            sw.WriteLine(pos)
        Next
        sw.Close()

        CarregarMovimentos()
    End Sub

    Public Sub CarregarMovimentos()
        lbMovimentos.Items.Clear()

        Dim arqs() As String = IO.Directory.GetFiles(Me.Pasta, "*.seq")

        For Each arq As String In arqs
            lbMovimentos.Items.Add(IO.Path.GetFileName(arq))
        Next
    End Sub

    Public Sub ExecutarArquivo(ByVal nomearq As String)
        Dim linhas() As String = CarregarPosições(nomearq)

        For Each linha As String In linhas
            Enviar(linha)
        Next
    End Sub

    Private Sub btnExecutar_Click(sender As Object, e As EventArgs) Handles btnExecutar.Click
        If lbMovimentos.SelectedIndex >= 0 Then
            Dim nomearq As String = lbMovimentos.SelectedItem

            ExecutarArquivo(nomearq)
        End If
    End Sub

    Private Sub btnPausa_Click(sender As Object, e As EventArgs) Handles btnPausa.Click
        Dim valor As String = InputBox("Digite a pausa em milissegundos (de 1 até 9999):", "Inserir Pausa", "300")

        If Not String.IsNullOrEmpty(valor) Then
            lbPosições.Items.Add("~" & valor)
        End If
    End Sub

    Public Function CarregarPosições(ByVal nome As String) As String()
        Dim arq As String = IO.Path.Combine(Me.Pasta, nome.Replace("|", ""))

        Dim sr As New IO.StreamReader(arq)
        Dim chunk As String = sr.ReadToEnd()
        sr.Close()

        Dim linhas() As String = chunk.Split(New String() {vbCrLf}, StringSplitOptions.RemoveEmptyEntries)

        Return linhas
    End Function

    Private Sub btnAbrir_Click(sender As Object, e As EventArgs) Handles btnAbrir.Click
        If lbMovimentos.SelectedIndex >= 0 Then
            Dim nome As String = lbMovimentos.SelectedItem
            Dim linhas() As String = CarregarPosições(nome)

            lbPosições.Items.Clear()

            For Each pos As String In linhas
                lbPosições.Items.Add(pos)
            Next
        End If

        CarregarMovimentos()
    End Sub

    Private Sub lbPosições_SelectedIndexChanged(sender As Object, e As EventArgs) Handles lbPosições.SelectedIndexChanged

    End Sub

    Private Sub lbPosições_KeyDown(sender As Object, e As KeyEventArgs) Handles lbPosições.KeyDown
        If e.KeyCode = Keys.Delete Then
            If lbPosições.SelectedIndex >= 0 Then
                lbPosições.Items.RemoveAt(lbPosições.SelectedIndex)
            End If
        ElseIf e.KeyCode = Keys.F5 Then
            btnExecutarPosições.PerformClick()
        ElseIf e.KeyCode = Keys.F8 Then
            Dim idx As Integer = lbPosições.SelectedIndex
            Dim pos As String = lbPosições.Items(idx)

            Enviar(pos)

            lbPosições.ClearSelected()
            If (idx + 1) < lbPosições.Items.Count Then
                lbPosições.SelectedIndex = idx + 1
            Else
                lbPosições.SelectedIndex = 0
            End If
        End If
    End Sub

    Private Sub btnParaCima_Click(sender As Object, e As EventArgs) Handles btnParaCima.Click
        If lbPosições.SelectedIndex > 0 Then
            Dim idx As Integer = lbPosições.SelectedIndex

            Dim antes As String = lbPosições.Items(idx - 1)
            Dim atual As String = lbPosições.Items(idx)

            lbPosições.Items(idx - 1) = atual
            lbPosições.Items(idx) = antes

            lbPosições.SelectedIndex = idx - 1
        End If
    End Sub

    Private Sub btnParaBaixo_Click(sender As Object, e As EventArgs) Handles btnParaBaixo.Click
        If lbPosições.SelectedIndex < lbPosições.Items.Count - 1 Then
            Dim idx As Integer = lbPosições.SelectedIndex

            Dim próximo As String = lbPosições.Items(idx + 1)
            Dim atual As String = lbPosições.Items(idx)

            lbPosições.Items(idx + 1) = atual
            lbPosições.Items(idx) = próximo

            lbPosições.SelectedIndex = idx + 1
        End If

    End Sub

    Private Sub btnExecutarPosições_Click(sender As Object, e As EventArgs) Handles btnExecutarPosições.Click
        Dim qt As Integer = 1

        If Not Integer.TryParse(txtQtExecutar.Text, qt) Then
            qt = 1
        End If

        If lbPosições.SelectedIndices.Count = 1 Then
            For k As Integer = 1 To qt
                lbPosições.Focus()
                For i As Integer = 0 To lbPosições.Items.Count - 1
                    lbPosições.ClearSelected()
                    lbPosições.SelectedIndex = i
                    Application.DoEvents()

                    Dim pos As String = lbPosições.SelectedItem

                    Enviar(pos)
                Next
            Next
        Else
            For Each idx As Integer In lbPosições.SelectedIndices
                Dim pos As String = lbPosições.Items(idx)

                Enviar(pos)
            Next
        End If
    End Sub

    Private Sub btnDesligar_Click(sender As Object, e As EventArgs) Handles btnDesligar.Click
        Dim valor As String = InputBox("Digite o número do servo-motor:", "Inserir Desligamento", "")

        If Not String.IsNullOrEmpty(valor) Then
            lbPosições.Items.Add("!" & valor)
        End If

    End Sub

    Private Sub lbPosições_MouseDoubleClick(sender As Object, e As MouseEventArgs) Handles lbPosições.MouseDoubleClick
        Dim novovalor As String = InputBox("Digite o novo valor:", "Alterar", lbPosições.SelectedItem)

        If Not String.IsNullOrEmpty(novovalor) Then
            lbPosições.Items(lbPosições.SelectedIndex) = novovalor
        End If
    End Sub

    Private Sub btnMovParaSliders_Click(sender As Object, e As EventArgs) Handles btnMovParaSliders.Click
        If lbMovimentos.SelectedIndex >= 0 Then
            Dim nomearq As String = lbMovimentos.SelectedItem

            Dim arq As String = IO.Path.Combine(Me.Pasta, nomearq)

            Dim sr As New IO.StreamReader(arq)
            Dim chunk As String = sr.ReadToEnd()
            sr.Close()

            Dim linhas() As String = chunk.Split(New String() {vbCrLf}, StringSplitOptions.RemoveEmptyEntries)

            For Each linha As String In linhas
                For Each ctrl As Control In Me.Controls
                    If TypeOf ctrl Is Slider Then
                        Dim sl As Slider = ctrl

                        If sl.ServoID = linha(0) Then
                            sl.Value = Integer.Parse(linha.Substring(1))
                        End If
                    End If
                Next
            Next
        End If

    End Sub

    Private Sub btnReferenciar_Click(sender As Object, e As EventArgs) Handles btnReferenciar.Click
        If lbMovimentos.SelectedIndex >= 0 Then
            Dim nome As String = lbMovimentos.SelectedItem

            lbPosições.Items.Add("^" & nome)
        End If
    End Sub

    Private Sub Servo_MaxPulseChanged(sender As Object, e As EventArgs) Handles Servo1.MaxPulseChanged, Servo2.MaxPulseChanged, Servo3.MaxPulseChanged, Servo4.MaxPulseChanged, Servo5.MaxPulseChanged, Servo6.MaxPulseChanged, Servo7.MaxPulseChanged, Servo8.MaxPulseChanged, Servo9.MaxPulseChanged, Servo10.MaxPulseChanged, Servo16.MaxPulseChanged, Servo15.MaxPulseChanged, Servo12.MaxPulseChanged, Servo11.MaxPulseChanged, Servo14.MaxPulseChanged, Servo13.MaxPulseChanged
        Dim sl As ISlider = sender
        Dim cmd As String = ")" & sl.ServoID & ":" & sl.MaxPulse.ToString()

        Enviar(cmd)
        Debug.Print(cmd)
    End Sub

    Private Sub Servo_MinPulseChanged(sender As Object, e As EventArgs) Handles Servo1.MinPulseChanged, Servo2.MinPulseChanged, Servo3.MinPulseChanged, Servo4.MinPulseChanged, Servo5.MinPulseChanged, Servo6.MinPulseChanged, Servo7.MinPulseChanged, Servo8.MinPulseChanged, Servo9.MinPulseChanged, Servo10.MinPulseChanged, Servo16.MinPulseChanged, Servo15.MinPulseChanged, Servo12.MinPulseChanged, Servo11.MinPulseChanged, Servo14.MinPulseChanged, Servo13.MinPulseChanged
        Dim sl As ISlider = sender
        Dim cmd As String = "(" & sl.ServoID & ":" & sl.MinPulse.ToString()

        Enviar(cmd)
        Debug.Print(cmd)
    End Sub

    Private Sub btnInicializar_Click(sender As Object, e As EventArgs) Handles btnInicializar.Click

        'udp = New System.Net.Sockets.UdpClient(txtEndereço.Text, Integer.Parse(txtPorta.Text))
        If tcp Is Nothing OrElse Not tcp.Connected Then
            Try
                tcp = New System.Net.Sockets.TcpClient(txtEndereço.Text, Integer.Parse(txtPorta.Text))
            Catch ex As Exception
                MessageBox.Show(ex.Message)
            End Try
        End If

        If tcp IsNot Nothing AndAlso Not tcp.Connected Then
            Try
                tcp.Connect(txtEndereço.Text, Integer.Parse(txtPorta.Text))
            Catch ex As Exception
                MessageBox.Show("Não foi possível conectar: " & ex.Message)
            End Try
        End If

        If tcp IsNot Nothing AndAlso tcp.Connected Then
            Dim init() As String = CarregarPosições("init.seq")

            For Each pos As String In init
                If pos.Contains("(") OrElse pos.Contains(")") Then
                    Dim minmax As String = pos.Substring(0, 1)
                    Dim idServo As String = pos.Substring(1, 1)
                    Dim valor As String = pos.Substring(3)

                    For Each c As Control In Me.Controls
                        If TypeOf c Is ISlider Then
                            Dim sl As ISlider = c

                            If sl.ServoID = idServo Then
                                If minmax = "(" Then
                                    sl.MinPulse = valor
                                Else
                                    sl.MaxPulse = valor
                                End If
                                Exit For
                            End If
                        End If
                    Next
                End If
            Next


            'For Each c As Control In Me.Controls
            '    If TypeOf c Is ISlider Then
            '        Dim sl As ISlider = c

            '        sl.MinPulse = 153
            '        sl.MaxPulse = 590
            '    End If
            'Next

            ''Servo1.MinPulse = 158
            ''Servo1.MaxPulse = 430

            ''Servo3.MinPulse = 153
            ''Servo3.MaxPulse = 630

            'Servo4.MinPulse = 143
            'Servo4.MaxPulse = 500

            ''Servo5.MinPulse = 261
            ''Servo5.MaxPulse = 530

            ''Servo7.MinPulse = 142
            ''Servo7.MaxPulse = 578

            'Servo8.MinPulse = 143
            'Servo8.MaxPulse = 500

            ''Servo9.MinPulse = 150
            ''Servo9.MaxPulse = 590

            ''Servo10.MinPulse = 147
            ''Servo10.MaxPulse = 583

            'Servo13.MaxPulse = 535
            'Servo15.MaxPulse = 535

            'Servo14.MinPulse = 171
            'Servo14.MaxPulse = 545

            'Servo16.MinPulse = 147
            'Servo16.MaxPulse = 590
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs)
        Dim inicial As String = "inicial.seq"
        Dim andar As String = "andar.seq"
        Dim virardir As String = "virardir.seq"
        Dim viraresq As String = "viraresq.seq"

        Dim maxpassos As Integer = 20
        Dim qtpassos As Integer = 0
        Dim distmínima As Integer = 30
        Dim qtviradas As Integer = 6

        ExecutarArquivo(inicial)

        Do While qtpassos < maxpassos
            Dim iDist As Integer = GetDistance(ReceberDados("DISTANCE", 50))
            Debug.Print("Distância antes do loop: " & iDist.ToString())

            If iDist <= distmínima Then
                For iv As Integer = 1 To qtviradas
                    ExecutarArquivo(inicial)
                    ExecutarArquivo(virardir)
                Next
            Else
                ExecutarArquivo(andar)
            End If

            qtpassos += 1
        Loop

    End Sub

    Public Function GetDistance(ByVal s As String) As Integer
        Dim i As Integer = 999

        Integer.TryParse(s, i)

        If i = -1 Then
            i = 999
        End If

        Return i
    End Function

    Private Sub btnExecutarTudo_Click(sender As Object, e As EventArgs) Handles btnExecutarTudo.Click
        Dim qt As Integer = 1

        If Not Integer.TryParse(txtQtExecutar.Text, qt) Then
            qt = 1
        End If

        Dim paraenvio As New System.Text.StringBuilder()

        For k As Integer = 1 To qt
            lbPosições.Focus()
            For i As Integer = 0 To lbPosições.Items.Count - 1
                lbPosições.ClearSelected()
                lbPosições.SelectedIndex = i
                Application.DoEvents()

                Dim pos As String = lbPosições.SelectedItem

                paraenvio.Append(pos)
                paraenvio.Append("|")
            Next
        Next

        Enviar(paraenvio.ToString())
    End Sub

    Private Sub MainForm_Closing(sender As Object, e As CancelEventArgs) Handles Me.Closing
        Enviar("RESET")
    End Sub

End Class
