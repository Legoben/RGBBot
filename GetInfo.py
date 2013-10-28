from urllib2 import urlopen
from time import sleep
import serial


def connectToArduino():
    #Sets up Serial on 9600
    tser = serial.Serial("/dev/tty.usbmodemfa131", 9600)
    return tser
    


def changeColor(color, ser):
    #Checks what color was recieved, then sends that color to Arduino
    
    if color == 'red':
        ser.write("r")
        print 'Change Color to RED'
    elif color == 'blue':
        ser.write("b")
        print 'Change Color to BLUE'
    elif color == 'green':
        ser.write("g")
        print 'Change Color to GREEN'
    else:
        print 'Color invalid!'

currentcolor = 'n'
ser = connectToArduino()

#Constantly pull from text file to see if the color has changed.
#If it has changed, run changeColor
while(True):
    thiscolor = urlopen("http://lab.helloben.co/RGBBot/file.txt") #Replace with URL of where file is located. It is on my server, in this case.
    c = str(thiscolor.read())
    
    if currentcolor != c:
        changeColor(c, ser)
        currentcolor = c
    else:
        print "Color ("+ currentcolor +") did not change... Skipping."
    
    #sleep(0.75) #Change to lower/higher to change strain on the server
