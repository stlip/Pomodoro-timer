My first project on GitHub!
This project is Arduino based Pomodoro timer that helps to manage time.It has 30/7 minutes of work/rest time.

HARDWARE
The pic of my hardware is uploaded in this 'project'
I used 4 digits 7 segments display(3461AS-1) and it doesn't have module for Arduino.Therfore i had to connect each pin separetely.
Display Digits (1-4):  D10, D11, D12, D13
Display Segments (A-DP): D2, D3, D4, D5, D6, D7, D8, D9
Also i used analog pins for buttons and buzzer, because all digitals were busy(i recommend to connect buttons to digital pin by connecting it from breadbord)
Button(Start/Pause): A0
Button(Reset): A1
Active buzzer: A2

SOFTWARE
code is uploaded in pomodoro.ino file.

NOTICE: If you use Arduino IDE, you should install SevSeg library by Dean Reading

It was really useful project that i made,because i need that too.It helps to manage your time and focus deeply.The main benefit is that it doesn't require Wi-Fi and since it is a standalone device and not a phone app, it helps me stay away from distractions and temptations like social media. 

Hope it will help someone!
