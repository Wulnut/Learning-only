#!/usr/bin/env python  
 
 
import RPi.GPIO as GPIO
import time
import signal
import atexit
 
atexit.register(GPIO.cleanup)  
 
servopin1 = 4
servopin2 = 18

GPIO.setmode(GPIO.BCM)

GPIO.setup(servopin1, GPIO.OUT, initial=False)
GPIO.setup(servopin2, GPIO.OUT, initial=False)

p1 = GPIO.PWM(servopin1,50) #50HZ
p2 = GPIO.PWM(servopin2,50) #50HZ

p1.start(0)
p2.start(0)

time.sleep(2)
 
for i in range(0,181,10):
    p1.ChangeDutyCycle(2.5 + 10 * i / 180) 
    p2.ChangeDutyCycle(2.5 + 10 * i / 180) 
	
    time.sleep(0.02) 
	
    p1.ChangeDutyCycle(0)   
    p2.ChangeDutyCycle(0)  
  	
    time.sleep(0.2)
  
for i in range(181,0,-10):
    p1.ChangeDutyCycle(2.5 + 10 * i / 180)
    p2.ChangeDutyCycle(2.5 + 10 * i / 180)
	
    time.sleep(0.02)
	
    p1.ChangeDutyCycle(0)
    p2.ChangeDutyCycle(0)
    time.sleep(0.2)
