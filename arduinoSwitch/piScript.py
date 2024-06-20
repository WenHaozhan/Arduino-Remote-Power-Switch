#!/usr/bin/python
import serial
import time 
import platform

serialPath = ''
if platform.system() == 'Linux' :
	serialPath = '/dev/ttyACM0'
elif platform.system() == 'Windows' :
	serialPath = 'COM3'

if __name__ == '__main__':
	ser = serial.Serial(serialPath, 9600, timeout=1)
	time.sleep(1)
	ser.flushInput()
	ser.write("ON".encode('ascii'))
	#time.sleep(1)
	#line = ser.readline().decode('utf-8').rstrip()
	#print(line)
	