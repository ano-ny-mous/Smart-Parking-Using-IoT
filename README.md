# Smart Parking Using IoT

## Introduction

This project demonstrates a **parking sensor system** using an ESP8266 module and an ultrasonic distance sensor. The system displays parking slot availability and detects obstacles, while also integrating with the Blynk app for remote monitoring and control.

## Components

- ESP8266 WiFi module
- HC-SR04 Ultrasonic Distance Sensor
- LEDs (3)
- Jumper Wires

## Images

<img src="https://github.com/ano-ny-mous/Smart-Parking-Using-IoT/assets/91519560/021dbc18-9a4c-46e3-91a9-8e5a51fd2657" alt="Screenshot 1" width="250" >

<img src="https://github.com/ano-ny-mous/Smart-Parking-Using-IoT/assets/91519560/d38ea0f0-e6f4-456e-9e33-2c5433c660b2" alt="Screenshot 2" width="230"/>

<img src="https://github.com/ano-ny-mous/Smart-Parking-Using-IoT/assets/91519560/9b9020a2-f627-4ee3-a605-0eb2a99f7746" alt="Screenshot 3" width="500"/>

## Video

https://github.com/ano-ny-mous/Smart-Parking-Using-IoT/assets/91519560/25850451-fefc-49b1-be53-f1d29630a894

## Parking Status Distances

**Free Parking**: Distance > 50 cm    
**Occupied Parking**: 10 cm < Distance <= 50 cm    
**Obstacle Detected**: Distance <= 10 cm      

## Installation

1. Set up the Arduino IDE on your computer if not already done.
2. Connect the components as shown in the wiring diagram.
3. Open the provided Arduino sketch (`parking_sensor_blynk.ino`) in the Arduino IDE.
4. Modify the code's WiFi credentials (`ssid` and `password`) to match your network settings.
5. Replace `"xxxxxxxxxxxxx"` with your actual Blynk authorization token.
6. Upload the sketch to your ESP8266 module.

## Usage

1. Power on the ESP8266 module and the circuit.
2. The system will start measuring distances and updating parking availability information on the Blynk app.
3. Monitor the parking slot status and obstacle detection remotely using the Blynk app.

## Blynk App Configuration

1. Download and install the Blynk app from your preferred app store.
2. Create a new Blynk project.
3. Add the required widgets (LEDs) to the project and assign appropriate virtual pins.
4. Obtain the authorization token for your Blynk project.
5. Replace `"xxxxxxxxxxxxx"` in the code with the obtained authorization token.


## License

This project is licensed under the [MIT License](LICENSE).
