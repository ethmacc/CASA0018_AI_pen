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
### Setup
First, clone the repository using ```git clone https://github.com/ethmacc/CASA0018_SmartScribble_AI_pen_prototype```

If you want to run the project as-is, without any modifications, simply use the Arduino IDE's import zip library function to import the model and support code:

<img src="https://github.com/user-attachments/assets/0960ba3c-5a60-408b-81f8-99716b2f5ebb" width="600" />

The zip library to use should be ```ei-stylus_v2-arduino-1.0.6.zip``` found in the ```builds``` folder. This contains the int8 quantized version of the best performing model found from my training runs.

Once that is done, flash the main ```stylus_v2.ino``` Arduino script onto your Nano 33 BLE Sense. This can be found in the ```stylus_v2``` folder. 

### Circuit
Using the protoboard, the wire and the pin headers, construct a small shield module to fit under the Nano. The protoboard should be no larger than the 2d footprint of the Nano in order to fit in the enclosure. The suggested arrangement of the components on the protoboard is shown below:

<img src="https://github.com/user-attachments/assets/60d2f44e-1cf0-4388-90c7-5803dc49e286" width="600" />

The circuit diagram for the protoboard is also shown below, using fritzing:

<img src="https://github.com/user-attachments/assets/630205bd-90a1-436f-8b83-0ec88d52b4be" width="300" />

### Enclosure

### Usage
1. The device does not call the model to start running inference on your handwriting until you have moved it. This is due to a conditional in the code, which does not start the inference cycle if no movement is detected in the onboard inertial measurement unit (IMU)

<img src="https://github.com/user-attachments/assets/74adc9b1-2a31-4d87-82e7-8fb365f3c2a4" width="600" />

3. Once the inference cycle has started, use the indicators displayed on the LED strip at the end of the pen to time your writing. Orange lights filling up from the bottom of the LED strip to the top indicate the model is loading and you must get ready. Red indicates that you should start writing, you have 2 seconds to write a single numeral.

<img src="https://github.com/user-attachments/assets/72154b05-8926-45c0-9f26-3c4d8d40c28d" width="600" />

<img src="https://github.com/user-attachments/assets/94d621e3-3e33-4ed6-b1eb-4040ce9f35fe" width="600" />

4. Once inference is completed, the result will be displayed on the LED strip. A single blue light indicates that the thinks the numeral you have written is a 0, while green lights indicate that the number was recognized as more than 0. The number of green lights displays corresponds to the numeral that was recognized.

<img src="https://github.com/user-attachments/assets/5fbe3be8-6559-439e-9ca4-060c5f73f5da" width="600" />

## Neural Network Training

## Arduino code

## External Links
Edge Impulse project: https://studio.edgeimpulse.com/studio/661138
