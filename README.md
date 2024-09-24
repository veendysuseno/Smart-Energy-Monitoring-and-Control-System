# Smart Energy Monitoring and Control System

This project is a smart energy monitoring and control system using an ESP8266 microcontroller, HX711 Load Cell, DHT11 sensor, Servo motor, and Blynk for real-time monitoring and notifications. The system is capable of measuring temperature, humidity, and weight, providing remote control functionality and notifications through a mobile application.

## Features
- **Real-time temperature and humidity monitoring** using DHT11.
- **Weight measurement** using HX711 Load Cell.
- **Servo control** based on weight data (e.g., for managing food or material quantity).
- **Remote control and notifications** via Blynk app.
- **Temperature control**: Automated fan/AC system activation based on temperature conditions.
- **Notifications** for important events such as high/low temperature and low food/material weight.

## Hardware Used
- **ESP8266**: Wi-Fi-enabled microcontroller for real-time data monitoring and control.
- **HX711**: Load cell amplifier for weight measurement.
- **DHT11**: Temperature and humidity sensor.
- **Servo Motor**: For automated control of components based on the measured weight.
- **Blynk App**: For real-time monitoring, control, and notifications on mobile devices.

## Software Requirements
- **Arduino IDE**: For writing and uploading code to the ESP8266.
- **Blynk Library**: For integration with the Blynk IoT platform.
- **HX711 Library**: For handling weight data from the load cell.
- **DHT Library**: For reading temperature and humidity data.
- **Servo Library**: To control the servo motor.

## Installation

1. **Clone or download** this repository.
    ```bash
    git clone https://github.com/your-username/project-name.git
    cd project-name
    ```

2. **Install required libraries** in the Arduino IDE:
   - Blynk
   - HX711
   - DHT
   - Servo

3. **Configure Wi-Fi and Blynk:**
   - Open the Arduino sketch.
   - Replace the following placeholders with your Blynk authentication token and Wi-Fi credentials:
     ```cpp
     char auth[] = "Your Blynk Auth Token";
     char ssid[] = "Your WiFi SSID";
     char pass[] = "Your WiFi Password";
     ```

4. **Upload the code** to your ESP8266 using the Arduino IDE.

## Usage

1. **Connect the hardware**:
    - Connect the HX711, DHT11, servo motor, and other components as per the circuit design.
   
2. **Monitor and control via Blynk**:
    - Open the Blynk app on your mobile device.
    - Add widgets for temperature, humidity, weight, and buttons for remote control.
    - View real-time data and receive notifications for any threshold events.

3. **Real-time data logging**:
    - Temperature and humidity will be displayed on the Blynk app.
    - The servo will operate based on weight thresholds (e.g., open/close actions based on food quantity).
    - Notifications will be sent if critical conditions are detected.

## Circuit Diagram

(Provide a circuit diagram if available, or describe the connections.)

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for details.

## Author
**Veendy-Suseno** - Developer, Embedded Systems and IoT Enthusiast

Feel free to reach out for any questions or improvements!
