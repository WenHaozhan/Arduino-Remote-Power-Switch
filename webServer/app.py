from flask import Flask
from flask import render_template 
import serial
import time 
import platform

serialPath = ''
if platform.system() == 'Linux' :
	serialPath = '/dev/ttyACM0'
elif platform.system() == 'Windows' :
	serialPath = 'COM3'


def openSwitch():
	ser = serial.Serial(serialPath, 9600, timeout=1)
	time.sleep(1)
	ser.flushInput()
	ser.write("ON".encode('ascii'))

app = Flask(__name__)

@app.route("/")
def index():
	return render_template('index.html')

@app.route("/turnOn", methods=['POST'])
def turnOn():
	openSwitch()
	return "Done"
