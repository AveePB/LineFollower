# TSR (Traffic Signs Recognition)
TSR is a technology by which a vehicle is able to recognize the traffic signs put on the road, such as speed limits, stop signs and other warnings. The system then provides this information to the driver, typically through the display.

## Table of contents
- [Introduction](#introduction)
- [Installation](#installation)
- [How does TSR work?](#how-does-tsr-work)
- [Application of TSR](#application-of-tsr)
- [License](#license)
- [Literature](#literature)

## Introduction
<p align="center">
    <img src="./assets/img/arduino-ide.png" alt="FreeRTOS logo" width="12%"/>
    <img src="./assets/img/freertos.png" alt="FreeRTOS logo" width="30%"/>
    <img src="./assets/img/yolo.png" alt="Yolo logo" width="25%"/>
</p>

This is one of student projects, that is supposed to help acquire knowledge of AI, embedded systems and 3D printing. We have used many frameworks including FreeRTOS and Yolo. This project is supposed to learn more about autonomous vehicles and its design. The goal is to equip line follower with TSR and maximize its reactions to the traffic signs.

## Installation

### Clone repository
...

### Upload code to arduino
...

### Set up raspberry pi
...

## How does TSR work?
...

### Camera input
...

### Sign detection 
...

### Sign classification
<img src="./assets/img/traffic-signs.png" width=600/>

Objects detected by the camera are assigned one of the lables:
 - **B-20**: Stop sign,
 - **B-33**: Start of speed limit,
 - **B-34**: End of speed limit,
 - **D-6**: Zebra crossing in a few meters,
 - **None**: Object was not recognized as one of the traffic signs. 


## Application of TSR

### Line follower
...

### Assembly
...

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Literature
List of sources:
- <a href="https://freertos.org/Documentation/02-Kernel/07-Books-and-manual/01-RTOS_book">FreeRTOS Documentation</a>,
- <a href="https://docs.ultralytics.com/">Yolo Documentation</a>
