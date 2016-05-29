Public Interface ISlider
    Event Scroll(sender As Object, e As EventArgs)
    Event ButtonClick(sender As Object, e As EventArgs)
    Event MaxPulseChanged(sender As Object, e As EventArgs)
    Event MinPulseChanged(sender As Object, e As EventArgs)
    Property PreviousValue As Integer

    Property Inverse As Boolean
    Property MinPulse As Integer
    Property MaxPulse As Integer
    Property Selected As CheckState
    Property ServoID As String
    Property Value As Integer
    Property Name As String
End Interface
