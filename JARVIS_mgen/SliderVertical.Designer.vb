<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class SliderVertical
    Inherits System.Windows.Forms.UserControl

    'UserControl overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.BarraDeslizante = New System.Windows.Forms.TrackBar()
        Me.Lbl = New System.Windows.Forms.Label()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.lblServoId = New System.Windows.Forms.Label()
        Me.Selection = New System.Windows.Forms.CheckBox()
        Me.txtMinPulse = New System.Windows.Forms.TextBox()
        Me.txtMaxPulse = New System.Windows.Forms.TextBox()
        CType(Me.BarraDeslizante, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'BarraDeslizante
        '
        Me.BarraDeslizante.Location = New System.Drawing.Point(3, 0)
        Me.BarraDeslizante.Maximum = 180
        Me.BarraDeslizante.Name = "BarraDeslizante"
        Me.BarraDeslizante.Orientation = System.Windows.Forms.Orientation.Vertical
        Me.BarraDeslizante.Size = New System.Drawing.Size(45, 121)
        Me.BarraDeslizante.TabIndex = 0
        Me.BarraDeslizante.Value = 90
        '
        'Lbl
        '
        Me.Lbl.Font = New System.Drawing.Font("Segoe UI", 11.0!)
        Me.Lbl.Location = New System.Drawing.Point(45, 61)
        Me.Lbl.Name = "Lbl"
        Me.Lbl.Size = New System.Drawing.Size(36, 22)
        Me.Lbl.TabIndex = 1
        Me.Lbl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'btnAdd
        '
        Me.btnAdd.Font = New System.Drawing.Font("Segoe UI", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnAdd.Location = New System.Drawing.Point(35, 86)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(34, 23)
        Me.btnAdd.TabIndex = 2
        Me.btnAdd.Text = ">>"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'lblServoId
        '
        Me.lblServoId.Location = New System.Drawing.Point(32, 61)
        Me.lblServoId.Name = "lblServoId"
        Me.lblServoId.Size = New System.Drawing.Size(16, 23)
        Me.lblServoId.TabIndex = 3
        Me.lblServoId.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Selection
        '
        Me.Selection.AutoSize = True
        Me.Selection.Checked = True
        Me.Selection.CheckState = System.Windows.Forms.CheckState.Indeterminate
        Me.Selection.Location = New System.Drawing.Point(54, 3)
        Me.Selection.Name = "Selection"
        Me.Selection.Size = New System.Drawing.Size(15, 14)
        Me.Selection.TabIndex = 4
        Me.Selection.ThreeState = True
        Me.Selection.UseVisualStyleBackColor = True
        '
        'txtMinPulse
        '
        Me.txtMinPulse.Font = New System.Drawing.Font("Segoe UI", 6.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtMinPulse.Location = New System.Drawing.Point(45, 19)
        Me.txtMinPulse.Name = "txtMinPulse"
        Me.txtMinPulse.Size = New System.Drawing.Size(25, 18)
        Me.txtMinPulse.TabIndex = 5
        '
        'txtMaxPulse
        '
        Me.txtMaxPulse.Font = New System.Drawing.Font("Segoe UI", 6.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.txtMaxPulse.Location = New System.Drawing.Point(45, 40)
        Me.txtMaxPulse.Name = "txtMaxPulse"
        Me.txtMaxPulse.Size = New System.Drawing.Size(25, 18)
        Me.txtMaxPulse.TabIndex = 6
        '
        'SliderVertical
        '
        Me.AutoSize = True
        Me.Controls.Add(Me.txtMaxPulse)
        Me.Controls.Add(Me.txtMinPulse)
        Me.Controls.Add(Me.Selection)
        Me.Controls.Add(Me.lblServoId)
        Me.Controls.Add(Me.btnAdd)
        Me.Controls.Add(Me.Lbl)
        Me.Controls.Add(Me.BarraDeslizante)
        Me.Font = New System.Drawing.Font("Segoe UI", 6.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Name = "SliderVertical"
        Me.Size = New System.Drawing.Size(84, 124)
        CType(Me.BarraDeslizante, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Protected WithEvents BarraDeslizante As TrackBar
    Protected WithEvents Lbl As Label
    Protected WithEvents btnAdd As Button
    Protected WithEvents lblServoId As Label
    Protected WithEvents Selection As CheckBox
    Protected WithEvents txtMinPulse As TextBox
    Protected WithEvents txtMaxPulse As TextBox
End Class
