# CASA0018_SmartScribble
1. [Introduction](#Introduction)
2. [Materials](#Materials)
3. [Quickstart](#Quickstart)
4. [Neural Network Training](#Neural-network-training)
5. [Arduino code](#Arduino-code)
6. [External Links](#External-links)

## Introduction
This repository contains the code to create a simple AI-powered pen attachment. The pen attachment is able to recognize the gestures of writing handwritten numerals from 0-7, with the help of a tiny Convolutional Neural Network model, optimized to run on the Arduino Nano BLE 33 Sense.

<img src="https://github.com/user-attachments/assets/f4df4c0d-b710-4045-9088-4c4e4efbf543" width="600" />

## Materials
You will need the following components to build this project:
- Arduino Nano BLE 33 Sense
- Adafruit Neopixel 8-strip
- Protoboard or stripboard
- Wire
- Male and female pin headers
- A 3D printer and filament
- An ink pen

## Quickstart
First, clone the repository using ```git clone https://github.com/ethmacc/CASA0018_SmartScribble_AI_pen_prototype```

If you want to run the project as-is, without any modifications, simply use the Arduino IDE's import zip library function to import the model and support code:

<img src="https://github.com/user-attachments/assets/0960ba3c-5a60-408b-81f8-99716b2f5ebb" width="600" />

The zip library to use should be ```ei-stylus_v2-arduino-1.0.6.zip``` found in the ```builds``` folder. This contains the int8 quantized version of the best performing model found from my training runs.

Once that is done, flash the main ```stylus_v2.ino``` Arduino script onto your Nano 33 BLE Sense. This can be found in the ```stylus_v2``` folder. The device does not 

## Neural Network Training

## Arduino code

## External Links
Edge Impulse project: https://studio.edgeimpulse.com/studio/661138
