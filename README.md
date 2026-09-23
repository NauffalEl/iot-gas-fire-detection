# IoT Gas & Fire Detection System

An IoT-based early warning system for detecting gas leaks and fire using NodeMCU ESP8266.

## Overview

This project integrates gas and flame sensors with NodeMCU ESP8266 to monitor hazardous conditions and provide early warnings through visual, audio, and Telegram notifications.

## Features

- Gas leak detection using MQ-2
- Fire detection using flame sensor
- Real-time LCD monitoring
- Buzzer alarm
- LED visual alarm
- Telegram Bot notifications
- WiFi connectivity

## Hardware

- NodeMCU ESP8266
- MQ-2 Gas Sensor
- Flame Sensor
- LCD I2C 16x2
- Buzzer
- LED
- Resistor
- Breadboard
- Jumper Wires

## Technologies

- Arduino IDE
- C/C++
- ESP8266
- IoT
- Telegram Bot API

## System Workflow

1. NodeMCU connects to WiFi.
2. MQ-2 and flame sensors continuously read environmental conditions.
3. Sensor data is displayed on the LCD.
4. Gas or fire detection activates the buzzer and LED.
5. Warning messages are sent to the user through Telegram.

## Testing

The MQ-2 test detected gas at distances below 6 cm with a response of approximately 2 seconds.

The flame sensor detected fire up to 20 cm with a response time of 1–2 seconds. :contentReference[oaicite:1]{index=1} :contentReference[oaicite:2]{index=2}

## Result

The system successfully integrated gas and fire detection with NodeMCU ESP8266 and Telegram-based real-time notifications. :contentReference[oaicite:3]{index=3}

## Project Type

Academic Project — Internet of Things
