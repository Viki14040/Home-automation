# Home Automation System with NodeMCU ESP8266

This project demonstrates a home automation system using the NodeMCU ESP8266 microcontroller and Arduino IDE. The system includes an interactive web page for controlling various appliances connected to the NodeMCU.

## Project Overview

The project involves setting up a NodeMCU ESP8266 to control home appliances via an interactive web interface. The system uses the NodeMCU to connect to Wi-Fi and communicate with a web page that allows users to switch appliances on or off remotely.

## Components Used

- **Microcontroller:** NodeMCU ESP8266
- **Software:**
  - **Arduino IDE:** For programming the NodeMCU.
  - **Web Technologies:** HTML, CSS, and JavaScript for the interactive web page.

## Getting Started

### Prerequisites

- **Arduino IDE:** Download and install from [Arduino's website](https://www.arduino.cc/en/software).
- **NodeMCU ESP8266 Board Package:** Install the ESP8266 board package in Arduino IDE via the Board Manager.

### Setup Instructions

1. **Arduino IDE Setup:**
   - Open Arduino IDE and install the ESP8266 board package if not already installed.
   - Connect your NodeMCU ESP8266 to your computer via USB.
   - Open the provided Arduino sketch (`home_automation.ino`) in the Arduino IDE.

2. **Code Configuration:**
   - Update the `ssid` and `password` variables in the code with your Wi-Fi network credentials.
   - Upload the sketch to the NodeMCU ESP8266.

3. **Web Page Setup:**
   - The interactive web page code is included in the `web` directory of this repository.
   - The web page is served by the NodeMCU and can be accessed via the IP address assigned to the NodeMCU by your Wi-Fi network.

### Running the System

1. **Upload Code:**
   - Upload the Arduino sketch to the NodeMCU ESP8266 using the Arduino IDE.

2. **Access Web Interface:**
   - Once the NodeMCU is connected to Wi-Fi, open the Serial Monitor in Arduino IDE to get the assigned IP address.
   - Enter the IP address in a web browser to access the interactive web page.

3. **Control Appliances:**
   - Use the web page to control the connected appliances by toggling the on/off buttons.

## Code

The main code for the NodeMCU is located in the `src` directory:

- `Home_automation.ino` - The Arduino sketch that handles Wi-Fi connectivity and web server functionality.

The web page files are located in the `web` directory:

- `index.html` - The main HTML file for the web interface.
- `styles.css` - CSS file for styling the web page.
