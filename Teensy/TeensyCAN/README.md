# CAN on Teensy 4.1

## Introduction
The code is for receiving the CAN data from our Formula Student car using Teensy 4.1 microcontroller. Various important parameters of the vehicle like RPM, engine temperature, battery voltage etc. are received from the ECU using the CAN bus protocol. This data is displayed on the HMI display thus assisting the driver to monitor these parameters.

## Components Used
* Teensy 4.1
* [CAN transceiver module SN65HVD230](https://www.flyrobo.in/wcmcu-230-can-bus-module-based-on-sn65hvd230?tracking=ads&tracking=4a9a9a&gad_source=1&gclid=CjwKCAjwv-2pBhB-EiwAtsQZFPmPjKZXjk2410JTJHOUsrV57TmEio5sGlzgG16o-yQkD0aV_cc-QhoCQbcQAvD_BwE)


## Connections
The CAN bus signals from ECU is in form of CANH (CAN High) and CANL (CAN Low). The CAN transceiver module has CANH and CANL pins which are connected to the C1 connector in the harness that contains CANH and CANL signals from ECU and the CTX and CRX pins of the module are connected to Teensy as following: 
| Pin on Teensy 4.1   | CAN module pin |
|---------------------|----------------|
| CRX1 23 (A9)        | CTX            |
| CTX1 22 (A8)        | CRX            |
