# Automatic Temperature-Based Fan Speed Control System

## Project Overview

The Automatic Temperature-Based Fan Speed Control System is an Arduino UNO-based embedded system designed to automatically regulate the speed of a DC fan according to the surrounding temperature.

The temperature sensor continuously measures the ambient temperature and provides an analog signal to the Arduino UNO. The Arduino processes the sensor reading and generates a PWM control signal for the fan driver. As the temperature increases, the fan speed increases automatically. At lower temperatures, the fan speed is reduced or switched OFF.

This project demonstrates the practical application of temperature sensing, analog signal processing, PWM-based motor control, embedded C/C++ programming, and automation.

---

## Objectives

- Measure ambient temperature continuously.
- Automatically control DC fan speed according to temperature.
- Interface a temperature sensor with Arduino UNO.
- Generate PWM signals for fan-speed control.
- Implement automatic temperature-based cooling.
- Develop a simple and low-cost embedded-system prototype.
- Demonstrate practical applications of sensors and microcontrollers.

---

## Components Used

| Component | Purpose |
|---|---|
| Arduino UNO | Main microcontroller and control unit |
| Temperature Sensor | Measures ambient temperature |
| DC Fan | Provides cooling |
| Fan Driver | Controls the DC fan safely |
| Power Supply | Provides power to the system |
| Breadboard / PCB | Circuit assembly |
| Connecting Wires | Electrical connections |

---

## Pin Configuration

| Component | Arduino UNO Pin | Function |
|---|---:|---|
| Temperature Sensor Output | A0 | Analog temperature input |
| Fan Driver Control | D9 | PWM output |

> **Note:** The reference implementation uses an LM35-type temperature sensor connected to A0. The fan-control signal is generated from Arduino UNO pin D9 through an appropriate fan driver.

---

## Hardware Connections

### Temperature Sensor

text
Temperature Sensor
        |
        +---- VCC  → Arduino 5V
        |
        +---- GND  → Arduino GND
        |
        +---- OUT  → Arduino A0

Fan Control 
Arduino UNO D9
      |
      ↓
Fan Driver
      |
      ↓
DC Fan
      |
      ↓
External Power Supply

Important: A DC fan should be operated through an appropriate driver/transistor/MOSFET circuit rather than being powered directly from an Arduino GPIO pin.

Block Diagram

The block diagram represents the flow of information and control between the temperature sensor, Arduino UNO, fan driver, and DC fan.

Flowchart

The flowchart represents the control logic used by the Arduino to measure temperature and adjust the fan speed automatically.

Working Principle
The temperature sensor measures the surrounding temperature.
The sensor provides an analog signal to the Arduino UNO.
The Arduino reads the analog sensor value through pin A0.
The analog value is converted into voltage.
The voltage is converted into temperature using the programmed sensor relationship.
The measured temperature is compared with predefined temperature ranges.
The Arduino calculates an appropriate PWM value.
The PWM signal is provided to the fan driver through pin D9.
The fan driver controls the speed of the DC fan.
As the temperature increases, the fan speed increases.
As the temperature decreases, the fan speed decreases.
The process continuously repeats.
Temperature-Based Fan Control
Temperature Range
PWM Value
Fan Response
Below 25°C
0
OFF
25°C – 30°C
80
Low Speed
30°C – 35°C
150
Medium Speed
35°C – 40°C
220
High Speed
40°C and above
255
Maximum Speed
Control Logic
The system uses PWM-based speed control.
The Arduino generates an 8-bit PWM value between 0 and 255.
PWM = 0     → Fan OFF
PWM = 80    → Low Speed
PWM = 150   → Medium Speed
PWM = 220   → High Speed
PWM = 255   → Maximum Speed

Software Implementation
The project is programmed using Arduino-compatible Embedded C/C++.
Main Program
const int temperatureSensor = A0;
const int fanControl = 9;

void setup() {

  pinMode(fanControl, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(temperatureSensor);

  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Reference calculation for an LM35-type sensor
  float temperature = voltage * 100.0;

  int fanSpeed;

  if (temperature < 25) {
    fanSpeed = 0;
  }
  else if (temperature < 30) {
    fanSpeed = 80;
  }
  else if (temperature < 35) {
    fanSpeed = 150;
  }
  else if (temperature < 40) {
    fanSpeed = 220;
  }
  else {
    fanSpeed = 255;
  }

  analogWrite(fanControl, fanSpeed);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Fan PWM: ");
  Serial.println(fanSpeed);

  delay(1000);
}

How to Run
Open code/Temperature_fan_control.ino in Arduino IDE.
Connect the temperature sensor output to Arduino A0.
Connect the fan-driver control input to Arduino D9.
Provide an appropriate power supply to the circuit.
Select Arduino UNO as the board.
Select the correct COM port.
Upload the program to the Arduino UNO.
Open the Serial Monitor.
Set the baud rate to 9600 baud.
Change the temperature around the sensor.
Observe the temperature reading and corresponding PWM value.
Observe the change in fan speed.
Testing
The prototype can be tested by gradually changing the temperature around the sensor and observing the corresponding fan-speed response.
Expected Behaviour
Test Condition
Expected Result
Temperature below 25°C
Fan OFF
Temperature between 25°C and 30°C
Low fan speed
Temperature between 30°C and 35°C
Medium fan speed
Temperature between 35°C and 40°C
High fan speed
Temperature above 40°C
Maximum fan speed
Temperature decreases
Fan speed decreases
Results
The prototype demonstrates automatic temperature-dependent fan-speed regulation.
The Arduino UNO continuously monitors the temperature and generates a corresponding PWM control signal. The fan speed changes according to the predefined temperature ranges.
The project successfully demonstrates:
Temperature sensing
Analog sensor interfacing
Arduino-based processing
PWM generation
DC fan-speed control
Automatic temperature regulation
Embedded-system implementation
Project Gallery
Project Front View
�
Electronics
�
Fan Setup
�
Applications
Electronic equipment cooling
Computer and hardware cooling
Laboratory equipment cooling
Small enclosure temperature management
Automatic ventilation systems
Embedded-system educational projects
Temperature-controlled cooling systems
Limitations
Temperature accuracy depends on the sensor characteristics and calibration.
Fan performance depends on the fan and driver circuit used.
A single temperature sensor measures temperature at only one location.
The prototype is intended primarily for educational and demonstration purposes.
The temperature-control thresholds are software-defined and can be modified according to the application.
Future Scope
The system can be further improved by implementing:
LCD/OLED display for real-time temperature monitoring
Multiple temperature sensors
IoT-based remote monitoring
Mobile application integration
Cloud-based temperature data logging
Automatic fault detection
More precise closed-loop fan control
PID-based temperature control
Wireless monitoring
Energy-efficient fan-speed optimization
Key Features
Automatic temperature monitoring
Automatic fan-speed regulation
Arduino UNO-based control
PWM-based fan control
Continuous temperature feedback
Multiple temperature-based speed levels
Low-cost implementation
Simple embedded-system architecture
Technologies Used
Arduino UNO
Embedded C/C++
Arduino IDE
Temperature sensing
Analog signal processing
PWM
DC motor/fan control
Basic electronics
Embedded systems
Automation
Learning Outcomes
Through this project, the following concepts were explored:
Arduino programming
Temperature sensor interfacing
Analog-to-digital conversion
Sensor signal processing
PWM generation
DC fan control
Embedded-system design
Hardware integration
Circuit troubleshooting
Testing and validation

Repository Structure

Automatic-Temperature-based-Fan-Speed-Control-System/
│
├── code/
│   └── Temperature_fan_control.ino
│
├── diagrams/
│   ├── block_diagram.jpg
│   └── flow_chart.jpg
│
├── images/
│   ├── electronics1.jpg
│   ├── fan_setup.jpg
│   └── project_front1.png
│
└── README.md

**Author**
**Gaurav Paste**
**Electronics & Telecommunication Engineering**

Project Domain
Embedded Systems | Electronics | Automation | Temperature Control

Conclusion
The Automatic Temperature-Based Fan Speed Control System provides a simple and practical method for automatic cooling based on ambient temperature.
By combining a temperature sensor, Arduino UNO, PWM control, fan driver, and DC fan, the system automatically adjusts cooling according to temperature conditions.
This project demonstrates the practical integration of sensors, microcontrollers, PWM control, and automation in an embedded-system application.
