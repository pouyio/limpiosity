# Introduction
**Limpiosity** is a robot, a spanish robot. It is based in both open software & hardware such as [Arduino](http://www.arduino.cc/). It is only made for educational and learning purpose. This page will only contain the *libraries* made to control some parts, for further information like construction materials and electronic circuits, visit [Limpiosity's site](http://limpiosity.qubic.es).

![limpiosity](limpiosity.jpg)

# Installation
## Pre-requisites
You must have installed [Arduino's IDE](http://arduino.cc/en/Main/Software).

## How to
1. Copy `code/libraries` folder to your arduino installation path, on windows `C:\Program Files (x86)\Arduino`. Or use arduino's IDE `Tools>Import library`.
2. Upload `code/transmission.ino` to your arduino uno board, the remote.
3. Upload `code/main_loop.ino` to your arduino mega board.
4. Switch everything on and enjoy!

# Other libraries

+ [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire.pdf) (Remote control)


# Hardware used

+ Arduino mega (Limpiosity's brain)
+ Arduino uno (Remote)
+ Lots of sensors to make some noise and movement, check them out in [here](http://www.vicenteortiz.me/limpiosity)

# Pins
### Motors
+ left motor =  5
+ left motor =  4
+ right motor =  6
+ right motor =  7

### Ultrasounds
+ left ultrasounds
  + echo azul = 40
  + triger verde = 42
+ mid ultrasounds
  + echo azul = 44
  + triger verde = 46
+ right ultrasounds
  + echo azul = 48
  + echo verde = 50

### Buzzer
10

### LCD
11,12,22 to 36

### LEDs
51,13,9,8

### Wireless connection
data 45

# Authors

+ David Martinez
+ Manu Rubio
+ Vicente Ortiz
