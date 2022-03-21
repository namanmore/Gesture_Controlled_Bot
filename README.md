# Gesture_Controlled_Bot

## Introduction    

This ROS Package contains scripts that will receive yaw data from the imu and publish data to move a differential drive base.  


## Dependencies  

* Python  
* Arduino IDE
* ROS
* Rosserial Arduino Library

The package was developend in <b>ROS Noetic</b>


## Using MPU 6050 IMU 
<p align="center">
  <img src="https://github.com/namanmore/test/blob/main/Images_README/imu.jpeg" />
</p>

On and Arduino Uno, the connections are:  
* Vcc -> 5V
* Gnd -> Gnd
* SCL -> A5
* SDA -> A4 

If a different Microcontroller is used, check the I2C pins of the board


## Running the code  
* Clone the repository in your local ROS workspace
```
 git clone https://github.com/namanmore/Gesture_Controlled_Bot.git
```
* Source the workspace, then 
```
roscore
```
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
If the microcontroller is connected on a different port then change ```ACM0/ACM1``` 
```
rosrun rosserial_python serial_node.py /dev/ttyACM1
```
```
rosrun gesture_bot IMU.py
```

