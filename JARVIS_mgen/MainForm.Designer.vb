<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MainForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btnOff = New System.Windows.Forms.Button()
        Me.lbPosições = New System.Windows.Forms.ListBox()
        Me.btnRegistrar = New System.Windows.Forms.Button()
        Me.btnGravar = New System.Windows.Forms.Button()
        Me.lbMovimentos = New System.Windows.Forms.ListBox()
        Me.btnLimpar = New System.Windows.Forms.Button()
        Me.btnExecutar = New System.Windows.Forms.Button()
        Me.txtEndereço = New System.Windows.Forms.TextBox()
        Me.txtPorta = New System.Windows.Forms.TextBox()
        Me.btnPausa = New System.Windows.Forms.Button()
        Me.btnAbrir = New System.Windows.Forms.Button()
        Me.btnParaCima = New System.Windows.Forms.Button()
        Me.btnParaBaixo = New System.Windows.Forms.Button()
        Me.btnExecutarPosições = New System.Windows.Forms.Button()
        Me.btnDesligar = New System.Windows.Forms.Button()
        Me.chkAtivar = New System.Windows.Forms.CheckBox()
        Me.btnMovParaSliders = New System.Windows.Forms.Button()
        Me.txtQtExecutar = New System.Windows.Forms.TextBox()
        Me.btnReferenciar = New System.Windows.Forms.Button()
        Me.btnInicializar = New System.Windows.Forms.Button()
        Me.txtVelocidade = New System.Windows.Forms.TextBox()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.btnExecutarTudo = New System.Windows.Forms.Button()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.pbHead = New System.Windows.Forms.PictureBox()
        Me.Servo8 = New JARVIS_mgen.SliderVertical()
        Me.Servo4 = New JARVIS_mgen.Slider()
        Me.SliderVertical1 = New JARVIS_mgen.SliderVertical()
        Me.Servo12 = New JARVIS_mgen.Slider()
        Me.Servo11 = New JARVIS_mgen.Slider()
        Me.Servo14 = New JARVIS_mgen.Slider()
        Me.Servo13 = New JARVIS_mgen.Slider()
        Me.Servo16 = New JARVIS_mgen.SliderVertical()
        Me.Servo15 = New JARVIS_mgen.SliderVertical()
        Me.Servo7 = New JARVIS_mgen.SliderVertical()
        Me.Servo6 = New JARVIS_mgen.SliderVertical()
        Me.Servo5 = New JARVIS_mgen.Slider()
        Me.Servo3 = New JARVIS_mgen.SliderVertical()
        Me.Servo2 = New JARVIS_mgen.SliderVertical()
        Me.Servo1 = New JARVIS_mgen.Slider()
        Me.txtPausaEntreEnvios = New System.Windows.Forms.TextBox()
        Me.btnConvertHexToBinary = New System.Windows.Forms.Button()
        Me.Servo9 = New JARVIS_mgen.Slider()
        Me.Servo10 = New JARVIS_mgen.Slider()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pbHead, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'btnOff
        '
        Me.btnOff.Location = New System.Drawing.Point(328, 9)
        Me.btnOff.Name = "btnOff"
        Me.btnOff.Size = New System.Drawing.Size(138, 35)
        Me.btnOff.TabIndex = 1
        Me.btnOff.Text = "OFF"
        Me.btnOff.UseVisualStyleBackColor = True
        '
        'lbPosições
        '
        Me.lbPosições.FormattingEnabled = True
        Me.lbPosições.Location = New System.Drawing.Point(804, 54)
        Me.lbPosições.Name = "lbPosições"
        Me.lbPosições.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended
        Me.lbPosições.Size = New System.Drawing.Size(108, 290)
        Me.lbPosições.TabIndex = 13
        '
        'btnRegistrar
        '
        Me.btnRegistrar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnRegistrar.Location = New System.Drawing.Point(804, 426)
        Me.btnRegistrar.Name = "btnRegistrar"
        Me.btnRegistrar.Size = New System.Drawing.Size(108, 70)
        Me.btnRegistrar.TabIndex = 14
        Me.btnRegistrar.Text = "Inserir Todos"
        Me.btnRegistrar.UseVisualStyleBackColor = True
        '
        'btnGravar
        '
        Me.btnGravar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnGravar.Location = New System.Drawing.Point(918, 303)
        Me.btnGravar.Name = "btnGravar"
        Me.btnGravar.Size = New System.Drawing.Size(70, 41)
        Me.btnGravar.TabIndex = 15
        Me.btnGravar.Text = ">>"
        Me.btnGravar.UseVisualStyleBackColor = True
        '
        'lbMovimentos
        '
        Me.lbMovimentos.FormattingEnabled = True
        Me.lbMovimentos.Location = New System.Drawing.Point(1003, 56)
        Me.lbMovimentos.Name = "lbMovimentos"
        Me.lbMovimentos.Size = New System.Drawing.Size(253, 290)
        Me.lbMovimentos.TabIndex = 16
        '
        'btnLimpar
        '
        Me.btnLimpar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnLimpar.Location = New System.Drawing.Point(804, 16)
        Me.btnLimpar.Name = "btnLimpar"
        Me.btnLimpar.Size = New System.Drawing.Size(108, 32)
        Me.btnLimpar.TabIndex = 17
        Me.btnLimpar.Text = "Limpar"
        Me.btnLimpar.UseVisualStyleBackColor = True
        '
        'btnExecutar
        '
        Me.btnExecutar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnExecutar.Location = New System.Drawing.Point(1003, 352)
        Me.btnExecutar.Name = "btnExecutar"
        Me.btnExecutar.Size = New System.Drawing.Size(253, 50)
        Me.btnExecutar.TabIndex = 18
        Me.btnExecutar.Text = "Executar"
        Me.btnExecutar.UseVisualStyleBackColor = True
        '
        'txtEndereço
        '
        Me.txtEndereço.Location = New System.Drawing.Point(12, 12)
        Me.txtEndereço.Name = "txtEndereço"
        Me.txtEndereço.Size = New System.Drawing.Size(106, 20)
        Me.txtEndereço.TabIndex = 19
        Me.txtEndereço.Text = "192.168.0.104"
        '
        'txtPorta
        '
        Me.txtPorta.Location = New System.Drawing.Point(124, 12)
        Me.txtPorta.Name = "txtPorta"
        Me.txtPorta.Size = New System.Drawing.Size(61, 20)
        Me.txtPorta.TabIndex = 20
        Me.txtPorta.Text = "2390"
        '
        'btnPausa
        '
        Me.btnPausa.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnPausa.Location = New System.Drawing.Point(804, 350)
        Me.btnPausa.Name = "btnPausa"
        Me.btnPausa.Size = New System.Drawing.Size(108, 32)
        Me.btnPausa.TabIndex = 21
        Me.btnPausa.Text = "Pausa"
        Me.btnPausa.UseVisualStyleBackColor = True
        '
        'btnAbrir
        '
        Me.btnAbrir.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnAbrir.Location = New System.Drawing.Point(918, 258)
        Me.btnAbrir.Name = "btnAbrir"
        Me.btnAbrir.Size = New System.Drawing.Size(70, 39)
        Me.btnAbrir.TabIndex = 28
        Me.btnAbrir.Text = "<<"
        Me.btnAbrir.UseVisualStyleBackColor = True
        '
        'btnParaCima
        '
        Me.btnParaCima.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnParaCima.Location = New System.Drawing.Point(918, 54)
        Me.btnParaCima.Name = "btnParaCima"
        Me.btnParaCima.Size = New System.Drawing.Size(79, 62)
        Me.btnParaCima.TabIndex = 29
        Me.btnParaCima.Text = "P/ Cima"
        Me.btnParaCima.UseVisualStyleBackColor = True
        '
        'btnParaBaixo
        '
        Me.btnParaBaixo.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnParaBaixo.Location = New System.Drawing.Point(918, 122)
        Me.btnParaBaixo.Name = "btnParaBaixo"
        Me.btnParaBaixo.Size = New System.Drawing.Size(79, 62)
        Me.btnParaBaixo.TabIndex = 30
        Me.btnParaBaixo.Text = "P/ Baixo"
        Me.btnParaBaixo.UseVisualStyleBackColor = True
        '
        'btnExecutarPosições
        '
        Me.btnExecutarPosições.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnExecutarPosições.Location = New System.Drawing.Point(804, 502)
        Me.btnExecutarPosições.Name = "btnExecutarPosições"
        Me.btnExecutarPosições.Size = New System.Drawing.Size(108, 50)
        Me.btnExecutarPosições.TabIndex = 31
        Me.btnExecutarPosições.Text = "Executar"
        Me.btnExecutarPosições.UseVisualStyleBackColor = True
        '
        'btnDesligar
        '
        Me.btnDesligar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnDesligar.Location = New System.Drawing.Point(804, 388)
        Me.btnDesligar.Name = "btnDesligar"
        Me.btnDesligar.Size = New System.Drawing.Size(108, 32)
        Me.btnDesligar.TabIndex = 32
        Me.btnDesligar.Text = "Desligar"
        Me.btnDesligar.UseVisualStyleBackColor = True
        '
        'chkAtivar
        '
        Me.chkAtivar.AutoSize = True
        Me.chkAtivar.Location = New System.Drawing.Point(472, 29)
        Me.chkAtivar.Name = "chkAtivar"
        Me.chkAtivar.Size = New System.Drawing.Size(53, 17)
        Me.chkAtivar.TabIndex = 33
        Me.chkAtivar.Text = "Ativar"
        Me.chkAtivar.UseVisualStyleBackColor = True
        '
        'btnMovParaSliders
        '
        Me.btnMovParaSliders.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnMovParaSliders.Location = New System.Drawing.Point(1003, 406)
        Me.btnMovParaSliders.Name = "btnMovParaSliders"
        Me.btnMovParaSliders.Size = New System.Drawing.Size(108, 42)
        Me.btnMovParaSliders.TabIndex = 34
        Me.btnMovParaSliders.Text = "<<"
        Me.btnMovParaSliders.UseVisualStyleBackColor = True
        '
        'txtQtExecutar
        '
        Me.txtQtExecutar.Location = New System.Drawing.Point(804, 558)
        Me.txtQtExecutar.Name = "txtQtExecutar"
        Me.txtQtExecutar.Size = New System.Drawing.Size(68, 20)
        Me.txtQtExecutar.TabIndex = 35
        Me.txtQtExecutar.Text = "1"
        '
        'btnReferenciar
        '
        Me.btnReferenciar.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnReferenciar.Location = New System.Drawing.Point(918, 213)
        Me.btnReferenciar.Name = "btnReferenciar"
        Me.btnReferenciar.Size = New System.Drawing.Size(70, 39)
        Me.btnReferenciar.TabIndex = 36
        Me.btnReferenciar.Text = "<-"
        Me.btnReferenciar.UseVisualStyleBackColor = True
        '
        'btnInicializar
        '
        Me.btnInicializar.Location = New System.Drawing.Point(191, 9)
        Me.btnInicializar.Name = "btnInicializar"
        Me.btnInicializar.Size = New System.Drawing.Size(131, 35)
        Me.btnInicializar.TabIndex = 37
        Me.btnInicializar.Text = "INICIALIZAR"
        Me.btnInicializar.UseVisualStyleBackColor = True
        '
        'txtVelocidade
        '
        Me.txtVelocidade.Location = New System.Drawing.Point(627, 9)
        Me.txtVelocidade.Name = "txtVelocidade"
        Me.txtVelocidade.Size = New System.Drawing.Size(86, 20)
        Me.txtVelocidade.TabIndex = 38
        Me.txtVelocidade.Text = "32"
        '
        'Button1
        '
        Me.Button1.Enabled = False
        Me.Button1.Location = New System.Drawing.Point(797, 649)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(78, 49)
        Me.Button1.TabIndex = 41
        Me.Button1.Text = "Button1"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'btnExecutarTudo
        '
        Me.btnExecutarTudo.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnExecutarTudo.Location = New System.Drawing.Point(804, 583)
        Me.btnExecutarTudo.Name = "btnExecutarTudo"
        Me.btnExecutarTudo.Size = New System.Drawing.Size(213, 50)
        Me.btnExecutarTudo.TabIndex = 42
        Me.btnExecutarTudo.Text = "Executar (TUDO)"
        Me.btnExecutarTudo.UseVisualStyleBackColor = True
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = Global.JARVIS_mgen.My.Resources.Resources.Jarvis14
        Me.PictureBox1.Location = New System.Drawing.Point(185, 105)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(433, 619)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 2
        Me.PictureBox1.TabStop = False
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(730, 59)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(60, 56)
        Me.Button2.TabIndex = 44
        Me.Button2.Text = "Button2"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'pbHead
        '
        Me.pbHead.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.pbHead.Location = New System.Drawing.Point(1107, 569)
        Me.pbHead.Name = "pbHead"
        Me.pbHead.Size = New System.Drawing.Size(128, 64)
        Me.pbHead.TabIndex = 45
        Me.pbHead.TabStop = False
        '
        'Servo8
        '
        Me.Servo8.ActualValue = 90
        Me.Servo8.AutoSize = True
        Me.Servo8.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo8.Inverse = False
        Me.Servo8.Location = New System.Drawing.Point(429, 60)
        Me.Servo8.MaxPulse = 0
        Me.Servo8.MinPulse = 0
        Me.Servo8.Name = "Servo8"
        Me.Servo8.PreviousValue = 90
        Me.Servo8.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo8.ServoID = "H"
        Me.Servo8.Size = New System.Drawing.Size(84, 124)
        Me.Servo8.TabIndex = 43
        Me.Servo8.Tag = ""
        Me.Servo8.Value = 90
        '
        'Servo4
        '
        Me.Servo4.AutoSize = True
        Me.Servo4.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo4.Inverse = True
        Me.Servo4.Location = New System.Drawing.Point(202, 96)
        Me.Servo4.MaxPulse = 0
        Me.Servo4.MinPulse = 0
        Me.Servo4.Name = "Servo4"
        Me.Servo4.PreviousValue = 90
        Me.Servo4.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo4.ServoID = "D"
        Me.Servo4.Size = New System.Drawing.Size(167, 61)
        Me.Servo4.TabIndex = 40
        Me.Servo4.Tag = ""
        Me.Servo4.Value = 90
        '
        'SliderVertical1
        '
        Me.SliderVertical1.ActualValue = 90
        Me.SliderVertical1.AutoSize = True
        Me.SliderVertical1.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.SliderVertical1.Inverse = False
        Me.SliderVertical1.Location = New System.Drawing.Point(930, 369)
        Me.SliderVertical1.MaxPulse = 0
        Me.SliderVertical1.MinPulse = 0
        Me.SliderVertical1.Name = "SliderVertical1"
        Me.SliderVertical1.PreviousValue = 90
        Me.SliderVertical1.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.SliderVertical1.ServoID = ""
        Me.SliderVertical1.Size = New System.Drawing.Size(87, 127)
        Me.SliderVertical1.TabIndex = 39
        Me.SliderVertical1.Value = 90
        '
        'Servo12
        '
        Me.Servo12.AutoSize = True
        Me.Servo12.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo12.Inverse = False
        Me.Servo12.Location = New System.Drawing.Point(624, 303)
        Me.Servo12.MaxPulse = 0
        Me.Servo12.MinPulse = 0
        Me.Servo12.Name = "Servo12"
        Me.Servo12.PreviousValue = 90
        Me.Servo12.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo12.ServoID = "M"
        Me.Servo12.Size = New System.Drawing.Size(167, 75)
        Me.Servo12.TabIndex = 27
        Me.Servo12.Tag = ""
        Me.Servo12.Value = 90
        '
        'Servo11
        '
        Me.Servo11.AutoSize = True
        Me.Servo11.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo11.Inverse = False
        Me.Servo11.Location = New System.Drawing.Point(12, 303)
        Me.Servo11.MaxPulse = 0
        Me.Servo11.MinPulse = 0
        Me.Servo11.Name = "Servo11"
        Me.Servo11.PreviousValue = 90
        Me.Servo11.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo11.ServoID = "P"
        Me.Servo11.Size = New System.Drawing.Size(167, 75)
        Me.Servo11.TabIndex = 26
        Me.Servo11.Tag = ""
        Me.Servo11.Value = 90
        '
        'Servo14
        '
        Me.Servo14.AutoSize = True
        Me.Servo14.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo14.Inverse = False
        Me.Servo14.Location = New System.Drawing.Point(624, 213)
        Me.Servo14.MaxPulse = 0
        Me.Servo14.MinPulse = 0
        Me.Servo14.Name = "Servo14"
        Me.Servo14.PreviousValue = 90
        Me.Servo14.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo14.ServoID = "L"
        Me.Servo14.Size = New System.Drawing.Size(167, 75)
        Me.Servo14.TabIndex = 25
        Me.Servo14.Tag = ""
        Me.Servo14.Value = 90
        '
        'Servo13
        '
        Me.Servo13.AutoSize = True
        Me.Servo13.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo13.Inverse = False
        Me.Servo13.Location = New System.Drawing.Point(12, 213)
        Me.Servo13.MaxPulse = 0
        Me.Servo13.MinPulse = 0
        Me.Servo13.Name = "Servo13"
        Me.Servo13.PreviousValue = 90
        Me.Servo13.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo13.ServoID = "O"
        Me.Servo13.Size = New System.Drawing.Size(167, 75)
        Me.Servo13.TabIndex = 24
        Me.Servo13.Tag = ""
        Me.Servo13.Value = 90
        '
        'Servo16
        '
        Me.Servo16.ActualValue = 90
        Me.Servo16.AutoSize = True
        Me.Servo16.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo16.Inverse = False
        Me.Servo16.Location = New System.Drawing.Point(624, 83)
        Me.Servo16.MaxPulse = 0
        Me.Servo16.MinPulse = 0
        Me.Servo16.Name = "Servo16"
        Me.Servo16.PreviousValue = 90
        Me.Servo16.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo16.ServoID = "N"
        Me.Servo16.Size = New System.Drawing.Size(84, 124)
        Me.Servo16.TabIndex = 23
        Me.Servo16.Tag = ""
        Me.Servo16.Value = 90
        '
        'Servo15
        '
        Me.Servo15.ActualValue = 90
        Me.Servo15.AutoSize = True
        Me.Servo15.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo15.Inverse = False
        Me.Servo15.Location = New System.Drawing.Point(95, 83)
        Me.Servo15.MaxPulse = 0
        Me.Servo15.MinPulse = 0
        Me.Servo15.Name = "Servo15"
        Me.Servo15.PreviousValue = 90
        Me.Servo15.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo15.ServoID = "K"
        Me.Servo15.Size = New System.Drawing.Size(84, 124)
        Me.Servo15.TabIndex = 22
        Me.Servo15.Tag = ""
        Me.Servo15.Value = 90
        '
        'Servo7
        '
        Me.Servo7.ActualValue = 90
        Me.Servo7.AutoSize = True
        Me.Servo7.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo7.Inverse = False
        Me.Servo7.Location = New System.Drawing.Point(624, 388)
        Me.Servo7.MaxPulse = 0
        Me.Servo7.MinPulse = 0
        Me.Servo7.Name = "Servo7"
        Me.Servo7.PreviousValue = 90
        Me.Servo7.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo7.ServoID = "G"
        Me.Servo7.Size = New System.Drawing.Size(87, 124)
        Me.Servo7.TabIndex = 9
        Me.Servo7.Tag = ""
        Me.Servo7.Value = 90
        '
        'Servo6
        '
        Me.Servo6.ActualValue = 90
        Me.Servo6.AutoSize = True
        Me.Servo6.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo6.Inverse = False
        Me.Servo6.Location = New System.Drawing.Point(624, 519)
        Me.Servo6.MaxPulse = 0
        Me.Servo6.MinPulse = 0
        Me.Servo6.Name = "Servo6"
        Me.Servo6.PreviousValue = 90
        Me.Servo6.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo6.ServoID = "F"
        Me.Servo6.Size = New System.Drawing.Size(87, 124)
        Me.Servo6.TabIndex = 8
        Me.Servo6.Tag = ""
        Me.Servo6.Value = 90
        '
        'Servo5
        '
        Me.Servo5.AutoSize = True
        Me.Servo5.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo5.Inverse = True
        Me.Servo5.Location = New System.Drawing.Point(624, 649)
        Me.Servo5.MaxPulse = 0
        Me.Servo5.MinPulse = 0
        Me.Servo5.Name = "Servo5"
        Me.Servo5.PreviousValue = 90
        Me.Servo5.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo5.ServoID = "E"
        Me.Servo5.Size = New System.Drawing.Size(167, 75)
        Me.Servo5.TabIndex = 7
        Me.Servo5.Tag = ""
        Me.Servo5.Value = 90
        '
        'Servo3
        '
        Me.Servo3.ActualValue = 90
        Me.Servo3.AutoSize = True
        Me.Servo3.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo3.Inverse = True
        Me.Servo3.Location = New System.Drawing.Point(92, 388)
        Me.Servo3.MaxPulse = 0
        Me.Servo3.MinPulse = 0
        Me.Servo3.Name = "Servo3"
        Me.Servo3.PreviousValue = 90
        Me.Servo3.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo3.ServoID = "C"
        Me.Servo3.Size = New System.Drawing.Size(87, 124)
        Me.Servo3.TabIndex = 5
        Me.Servo3.Tag = ""
        Me.Servo3.Value = 90
        '
        'Servo2
        '
        Me.Servo2.ActualValue = 90
        Me.Servo2.AutoSize = True
        Me.Servo2.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo2.Inverse = True
        Me.Servo2.Location = New System.Drawing.Point(92, 519)
        Me.Servo2.MaxPulse = 0
        Me.Servo2.MinPulse = 0
        Me.Servo2.Name = "Servo2"
        Me.Servo2.PreviousValue = 90
        Me.Servo2.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo2.ServoID = "B"
        Me.Servo2.Size = New System.Drawing.Size(87, 124)
        Me.Servo2.TabIndex = 4
        Me.Servo2.Tag = ""
        Me.Servo2.Value = 90
        '
        'Servo1
        '
        Me.Servo1.AutoSize = True
        Me.Servo1.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo1.Inverse = True
        Me.Servo1.Location = New System.Drawing.Point(12, 649)
        Me.Servo1.MaxPulse = 0
        Me.Servo1.MinPulse = 0
        Me.Servo1.Name = "Servo1"
        Me.Servo1.PreviousValue = 90
        Me.Servo1.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo1.ServoID = "A"
        Me.Servo1.Size = New System.Drawing.Size(167, 75)
        Me.Servo1.TabIndex = 3
        Me.Servo1.Tag = ""
        Me.Servo1.Value = 90
        '
        'txtPausaEntreEnvios
        '
        Me.txtPausaEntreEnvios.Location = New System.Drawing.Point(627, 35)
        Me.txtPausaEntreEnvios.Name = "txtPausaEntreEnvios"
        Me.txtPausaEntreEnvios.Size = New System.Drawing.Size(86, 20)
        Me.txtPausaEntreEnvios.TabIndex = 46
        Me.txtPausaEntreEnvios.Text = "100"
        '
        'btnConvertHexToBinary
        '
        Me.btnConvertHexToBinary.Location = New System.Drawing.Point(1003, 510)
        Me.btnConvertHexToBinary.Name = "btnConvertHexToBinary"
        Me.btnConvertHexToBinary.Size = New System.Drawing.Size(252, 48)
        Me.btnConvertHexToBinary.TabIndex = 47
        Me.btnConvertHexToBinary.Text = "Converter arquivo do LCD Assistant"
        Me.btnConvertHexToBinary.UseVisualStyleBackColor = True
        '
        'Servo9
        '
        Me.Servo9.AutoSize = True
        Me.Servo9.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo9.Inverse = True
        Me.Servo9.Location = New System.Drawing.Point(881, 649)
        Me.Servo9.MaxPulse = 0
        Me.Servo9.MinPulse = 0
        Me.Servo9.Name = "Servo9"
        Me.Servo9.PreviousValue = 90
        Me.Servo9.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo9.ServoID = "I"
        Me.Servo9.Size = New System.Drawing.Size(167, 75)
        Me.Servo9.TabIndex = 48
        Me.Servo9.Tag = ""
        Me.Servo9.Value = 90
        '
        'Servo10
        '
        Me.Servo10.AutoSize = True
        Me.Servo10.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Servo10.Inverse = True
        Me.Servo10.Location = New System.Drawing.Point(1054, 644)
        Me.Servo10.MaxPulse = 0
        Me.Servo10.MinPulse = 0
        Me.Servo10.Name = "Servo10"
        Me.Servo10.PreviousValue = 90
        Me.Servo10.Selected = System.Windows.Forms.CheckState.Indeterminate
        Me.Servo10.ServoID = "J"
        Me.Servo10.Size = New System.Drawing.Size(167, 75)
        Me.Servo10.TabIndex = 49
        Me.Servo10.Tag = ""
        Me.Servo10.Value = 90
        '
        'MainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1268, 731)
        Me.Controls.Add(Me.Servo10)
        Me.Controls.Add(Me.Servo9)
        Me.Controls.Add(Me.btnConvertHexToBinary)
        Me.Controls.Add(Me.txtPausaEntreEnvios)
        Me.Controls.Add(Me.pbHead)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Servo8)
        Me.Controls.Add(Me.btnExecutarTudo)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Servo4)
        Me.Controls.Add(Me.SliderVertical1)
        Me.Controls.Add(Me.txtVelocidade)
        Me.Controls.Add(Me.btnInicializar)
        Me.Controls.Add(Me.btnReferenciar)
        Me.Controls.Add(Me.txtQtExecutar)
        Me.Controls.Add(Me.btnMovParaSliders)
        Me.Controls.Add(Me.chkAtivar)
        Me.Controls.Add(Me.btnDesligar)
        Me.Controls.Add(Me.btnExecutarPosições)
        Me.Controls.Add(Me.btnParaBaixo)
        Me.Controls.Add(Me.btnParaCima)
        Me.Controls.Add(Me.btnAbrir)
        Me.Controls.Add(Me.Servo12)
        Me.Controls.Add(Me.Servo11)
        Me.Controls.Add(Me.Servo14)
        Me.Controls.Add(Me.Servo13)
        Me.Controls.Add(Me.Servo16)
        Me.Controls.Add(Me.Servo15)
        Me.Controls.Add(Me.btnPausa)
        Me.Controls.Add(Me.txtPorta)
        Me.Controls.Add(Me.txtEndereço)
        Me.Controls.Add(Me.btnExecutar)
        Me.Controls.Add(Me.btnLimpar)
        Me.Controls.Add(Me.lbMovimentos)
        Me.Controls.Add(Me.btnGravar)
        Me.Controls.Add(Me.btnRegistrar)
        Me.Controls.Add(Me.lbPosições)
        Me.Controls.Add(Me.Servo7)
        Me.Controls.Add(Me.Servo6)
        Me.Controls.Add(Me.Servo5)
        Me.Controls.Add(Me.Servo3)
        Me.Controls.Add(Me.Servo2)
        Me.Controls.Add(Me.Servo1)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.btnOff)
        Me.Name = "MainForm"
        Me.Text = "JARVIS mgen"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pbHead, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnOff As Button
    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents Servo1 As Slider
    Friend WithEvents Servo2 As SliderVertical
    Friend WithEvents Servo3 As SliderVertical
    Friend WithEvents Servo5 As Slider
    Friend WithEvents Servo6 As SliderVertical
    Friend WithEvents Servo7 As SliderVertical
    Friend WithEvents lbPosições As ListBox
    Friend WithEvents btnRegistrar As Button
    Friend WithEvents btnGravar As Button
    Friend WithEvents lbMovimentos As ListBox
    Friend WithEvents btnLimpar As Button
    Friend WithEvents btnExecutar As Button
    Friend WithEvents txtEndereço As TextBox
    Friend WithEvents txtPorta As TextBox
    Friend WithEvents btnPausa As Button
    Friend WithEvents Servo15 As SliderVertical
    Friend WithEvents Servo16 As SliderVertical
    Friend WithEvents Servo13 As Slider
    Friend WithEvents Servo14 As Slider
    Friend WithEvents Servo11 As Slider
    Friend WithEvents Servo12 As Slider
    Friend WithEvents btnAbrir As Button
    Friend WithEvents btnParaCima As Button
    Friend WithEvents btnParaBaixo As Button
    Friend WithEvents btnExecutarPosições As Button
    Friend WithEvents btnDesligar As Button
    Friend WithEvents chkAtivar As CheckBox
    Friend WithEvents btnMovParaSliders As Button
    Friend WithEvents txtQtExecutar As TextBox
    Friend WithEvents btnReferenciar As Button
    Friend WithEvents btnInicializar As Button
    Friend WithEvents txtVelocidade As TextBox
    Friend WithEvents SliderVertical1 As SliderVertical
    Friend WithEvents Servo4 As Slider
    Friend WithEvents Button1 As Button
    Friend WithEvents btnExecutarTudo As Button
    Friend WithEvents Servo8 As SliderVertical
    Friend WithEvents Button2 As Button
    Friend WithEvents pbHead As PictureBox
    Friend WithEvents txtPausaEntreEnvios As TextBox
    Friend WithEvents btnConvertHexToBinary As Button
    Friend WithEvents Servo9 As Slider
    Friend WithEvents Servo10 As Slider
End Class
