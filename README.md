# 🌾 Agriculture Sensor Integration Project ![Under Construction](https://img.shields.io/badge/status-under%20construction-orange)

This project demonstrates the integration of various sensors commonly used in agriculture applications on a STM32 microcontroller platform.

## Overview
**🚧 Note: This project is currently under construction.**
The project aims to read data from the following sensors:

- 🌡️ DS18B20 Temperature Sensor
- 🌦️ BME280 Environmental Sensor (Temperature, Humidity, Pressure)
- 💡 Light Sensor
- 💧 Soil Moisture Sensor

Each sensor communicates using different protocols, including OneWire, I2C, and analog voltage.

## Requirements

- STM32 microcontroller board with ARM Cortex-M3 CPU
- STM32CubeIDE for development
- Libraries and drivers for each sensor
- Hardware setup for sensor integration

## Getting Started

1. Clone this repository.
2. Open the project in STM32CubeIDE.
3. Configure your project settings and build the firmware.
4. Install necessary libraries and drivers for each sensor.
5. Connect the sensors to the STM32 board according to the hardware setup.
6. Flash the firmware to the STM32 board using STM32CubeIDE.
7. Monitor the sensor data through the serial interface or any other suitable method.

## Project Structure

- **Hardware**: This folder contains files and documentation related to the hardware setup, such as schematics, datasheets, and connection diagrams.

- **Software**: This folder contains the source code, header files, STM32Cube HAL library, and additional sensor libraries required for the project.

    - **Src**: Contains the source files for the project.
    - **Inc**: Contains the header files for the project.
    - **Drivers**: Contains the STM32Cube HAL library.
    - **Libraries**: Contains additional libraries for sensor integration.

- **Documentation**: Contains documentation files related to the project.


## Contributing

Contributions to improve the project are welcome! Please feel free to fork the repository, make changes, and submit a pull request.

## 📜 License
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
 
