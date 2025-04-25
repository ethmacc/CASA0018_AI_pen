# CASA0018_SmartScribble
1. [Introduction](#Introduction)
2. [Materials](#Materials)
3. [Quickstart](#Quickstart)
4. [Neural Network Training](#Neural-network-training)
5. [Future work](#Limitations-and-future-work)
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
### Software Setup
First, clone the repository using ```git clone https://github.com/ethmacc/CASA0018_SmartScribble_AI_pen_prototype```

If you want to run the project as-is, without any modifications, simply use the Arduino IDE's import zip library function to import the model and support code:

<img src="https://github.com/user-attachments/assets/0960ba3c-5a60-408b-81f8-99716b2f5ebb" width="600" />

The zip library to use should be ```ei-stylus_v2-arduino-1.0.6.zip``` found in the ```builds``` folder. This contains the int8 quantized version of the best performing model found from my training runs.

Once that is done, flash the main ```stylus_v2.ino``` Arduino script onto your Nano 33 BLE Sense. This can be found in the ```stylus_v2``` folder. 

### Circuit
Using the protoboard, the wire and the pin headers, construct a small shield module to fit under the Nano. The protoboard should be no larger than the 2d footprint of the Nano in order to fit in the enclosure. The suggested arrangement of the components on the protoboard is shown below:

<img src="https://github.com/user-attachments/assets/60d2f44e-1cf0-4388-90c7-5803dc49e286" width="600" />

The circuit diagram for the protoboard is also shown below, using fritzing:

<img src="https://github.com/user-attachments/assets/630205bd-90a1-436f-8b83-0ec88d52b4be" height="600" />

### Enclosure
3D models and print files are available in the ```enclosure``` folder. These should include everything needed to print and construct the enclosure attachment, which can then be fitted on to the end of your ink pen.

<img src="https://github.com/user-attachments/assets/d8c9f073-aed9-4296-b22c-d35cc7e72144" width="600" />

The protoboard shield and Nano should fit in snugly into the enclosure a shown:

<img src="https://github.com/user-attachments/assets/321c5bcd-7565-4180-8fb0-e5611cb777d8" width="600" />

### Usage
1. The device does not call the model to start running inference on your handwriting until you have moved it. This is due to a conditional in the code, which does not start the inference cycle if no movement is detected in the onboard inertial measurement unit (IMU)

<img src="https://github.com/user-attachments/assets/74adc9b1-2a31-4d87-82e7-8fb365f3c2a4" width="600" />

3. Once the inference cycle has started, use the indicators displayed on the LED strip at the end of the pen to time your writing. Orange lights filling up from the bottom of the LED strip to the top indicate the model is loading and you must get ready. Red indicates that you should start writing, you have 2 seconds to write a single numeral.

<img src="https://github.com/user-attachments/assets/72154b05-8926-45c0-9f26-3c4d8d40c28d" width="600" />

<img src="https://github.com/user-attachments/assets/94d621e3-3e33-4ed6-b1eb-4040ce9f35fe" width="600" />

4. Once inference is completed, the result will be displayed on the LED strip. A single blue light indicates that the thinks the numeral you have written is a 0, while green lights indicate that the number was recognized as more than 0. The number of green lights displays corresponds to the numeral that was recognized.

<img src="https://github.com/user-attachments/assets/5fbe3be8-6559-439e-9ca4-060c5f73f5da" width="600" />

## Neural Network Training
If you want to make changes to the neural network and/or conduct your own training, please head over to the Edge Impulse project page in the external links section below. Once there, you should be able to create an account and clone the project to begin your own training. The Edge Impulse dashboard is simple and easy to use, but some further reading to edge AI and deep learning is recommended if you do not already posses the prerequisite background knowledge:

<img src="https://github.com/user-attachments/assets/bd421f54-0407-40d7-a3e9-6efdce062962" width="600" />

As mentioned, the model architecture is that of a Convolutional Neural Network (CNN), consisting of 3 convolution layers and 2 dense layers, with reshape, flatten and dropout layers in between:

<img src="https://github.com/user-attachments/assets/1e013fb8-a72f-4050-bbc2-0dfbe4084151" width="600" />

You can find the record of the experiments run to determined the best hyperparameters and model architecture in the EON Tuner section of the Edge Impulse project page.

## Limitations and future work
The model was trained using a free account on Edge Impulse and therefore compute time was limited. You may find that your mileage may vary if you already have or decide to purchase a subscription from Edge Impulse. At present, the model is limited to classifying only the 8 classes of the numerals 0-7. It has also been trained solely on one person's handwriting data, and therefore may not be as accurate as it could be. In particular, the numerals 0 & 6 and 1 & 4 are easily confused, likely due to the similar pen strokes required to draw these characters.

Additionally, in terms of hardware, it is probably worth investigating if the electronics can be miniaturised by using a custom PCB. The prototype device also currently runs off a 5V powerbank, and it would be much better if the power supply could be integrated into the pen itself to improve ergonomics and appearance.

## External Links
Edge Impulse project: https://studio.edgeimpulse.com/studio/661138

Edge Impulse help and documentation: https://docs.edgeimpulse.com/docs

Suggested further reading:
- AI at the Edge by Situnayake and Plunkett
- TinyML by Situnayake and Warden
- Deep Learning by Courville, Goodfellow and Yoshua Bengio
