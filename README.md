# LockBot
An Arduino based smart lock system with only one button as input.

Many smart lock systems found in the market, requires complex mechanism and expensive input devices like RFID, camera, fingerprint sensor, keypad, etc. 
In this project we will learn how to built a smart lock system with only one button as input. While it is simple and easy to build, combined with some Robotics principles, this smart lock is secure and strong enough for most of our daily needs. 

![goal](https://github.com/judhi/lockbot/blob/master/LockBot-Goal.png?raw=true)

Inspired by Morse Code by Samuel Morse (1841), user must enter the secret code consists of several short and long presses in particular sequence. Upon successful attempt, the microcontroller will turn a servo motor that will move the latch to unlock a door.

Here we take short press and long press to represent 0 and 1 respectively. Everytime the use presses the button, the value will be compared with the pre-defined secret code. In this example the secret code is defined as 6-digit binary 001011, so to unlock the door we must press the button six times with the following sequence: short press, short press, long press, short press, long press, long press. Arduino will capture each key press value and compare it with the corresponding secret code index, if the value matches, Arduino will move to the next index of the secret code to compare with next input value. But if the input value is wrong, the index will reset to 0 and the comparison will restart from the beginning again.

![state-machine](https://github.com/judhi/lockbot/blob/master/LockBot-state-machine.png)

To use your own code, please modify SecretCode variable value on line 13 of the Arduino sketch.

## Parts list
* Arduino Uno/Nano/Mega, etc.
* Push button
* 180 degree servo motor
* breadboard or proto PCB
* wires

Optional:
* Capacitive touch sensor
* IR obstacle sensor

## Schematic
![schematic](https://github.com/judhi/lockbot/blob/master/LockBot-schematic.png)

## Fritzing diagram
![fritzing](https://github.com/judhi/lockbot/blob/master/LockBot-fritzing.png)

## Sketch
Download sketch [here](https://github.com/judhi/lockbot/blob/master/LockBot_Arduino.ino) 

## Links of 3D printed door locks
* [Motorized 3D printed door lock by Mayur Singh](https://www.myminifactory.com/object/3d-print-motorized-door-lock-6905)
* [Door lock Arduino by LetsPrintYT](https://www.thingiverse.com/thing:4565903)
