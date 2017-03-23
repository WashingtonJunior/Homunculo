Imports JARVIS_mgen

Public Class SliderVertical
    Implements ISlider

    Public Shadows Event Scroll(sender As Object, e As EventArgs) Implements ISlider.Scroll
    Public Event ButtonClick(sender As Object, e As EventArgs) Implements ISlider.ButtonClick
    Public Event MaxPulseChanged(sender As Object, e As EventArgs) Implements ISlider.MaxPulseChanged
    Public Event MinPulseChanged(sender As Object, e As EventArgs) Implements ISlider.MinPulseChanged
    Public Property PreviousValue As Integer Implements ISlider.PreviousValue
    Public Overloads Property Name As String Implements ISlider.Name

    Public Property Inverse As Boolean Implements ISlider.Inverse
        Get
            Return BarraDeslizante.RightToLeft = RightToLeft.Yes
        End Get
        Set(value As Boolean)
            If value Then
                BarraDeslizante.RightToLeft = RightToLeft.Yes
            Else
                BarraDeslizante.RightToLeft = RightToLeft.No
            End If
        End Set
    End Property

    Public Property MinPulse As Integer Implements ISlider.MinPulse
        Get
            Dim retorno As Integer = 0

            Integer.TryParse(txtMinPulse.Text, retorno)

            Return retorno
        End Get
        Set(value As Integer)
            Dim old As String = txtMinPulse.Text

            txtMinPulse.Text = value.ToString()

            If old <> txtMinPulse.Text Then
                RaiseEvent MinPulseChanged(Me, New EventArgs())
            End If
        End Set
    End Property

    Public Property MaxPulse As Integer Implements ISlider.MaxPulse
        Get
            Dim retorno As Integer = 0

            Integer.TryParse(txtMaxPulse.Text, retorno)

            Return retorno
        End Get
        Set(value As Integer)
            Dim old As String = txtMaxPulse.Text

            txtMaxPulse.Text = value.ToString()

            If old <> txtMaxPulse.Text Then
                RaiseEvent MaxPulseChanged(Me, New EventArgs())
            End If
        End Set
    End Property

    Public Property Selected As CheckState Implements ISlider.Selected
        Get
            Return Selection.CheckState
        End Get
        Set(value As CheckState)
            Selection.CheckState = value
        End Set
    End Property

    Public Property ServoID As String Implements ISlider.ServoID
        Get
            Return lblServoId.Text
        End Get
        Set(value As String)
            lblServoId.Text = value
        End Set
    End Property

    Private Sub BarraDeslizante_Scroll(sender As Object, e As EventArgs) Handles BarraDeslizante.Scroll
        Lbl.Text = ActualValue.ToString()
        RaiseEvent Scroll(Me, e)
        PreviousValue = ActualValue
    End Sub

    Private Sub Slider_Load(sender As Object, e As EventArgs) Handles Me.Load
        BarraDeslizante_Scroll(Me, e)
    End Sub

    Public Property ActualValue As Integer
        Get
            If Inverse Then
                Return BarraDeslizante.Maximum - BarraDeslizante.Value + BarraDeslizante.Minimum
            Else
                Return BarraDeslizante.Value
            End If
        End Get
        Set(value As Integer)
            If Inverse Then
                'BarraDeslizante.Value = BarraDeslizante.Maximum - BarraDeslizante.Value + BarraDeslizante.Minimum
                BarraDeslizante.Value = BarraDeslizante.Maximum - value + BarraDeslizante.Minimum
            Else
                BarraDeslizante.Value = value
            End If
        End Set
    End Property

    Public Property Value As Integer Implements ISlider.Value
        Get
            Return ActualValue
        End Get
        Set(value As Integer)
            If value >= BarraDeslizante.Minimum AndAlso value <= BarraDeslizante.Maximum Then
                PreviousValue = ActualValue
                ActualValue = value
                BarraDeslizante_Scroll(Me, New EventArgs())
            End If
        End Set
    End Property

    Private Sub btnAdd_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        RaiseEvent ButtonClick(Me, e)
    End Sub

    Private Sub MinPulse_TextChanged(sender As Object, e As EventArgs) Handles txtMinPulse.TextChanged
        RaiseEvent MinPulseChanged(Me, e)
    End Sub

    Private Sub MaxPulse_TextChanged(sender As Object, e As EventArgs) Handles txtMaxPulse.TextChanged
        RaiseEvent MaxPulseChanged(Me, e)
    End Sub
End Class
