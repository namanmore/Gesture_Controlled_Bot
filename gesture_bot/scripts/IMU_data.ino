#include <ros.h>
#include <std_msgs/Float64.h>
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
unsigned long timer = 0;
int i;
ros::NodeHandle  nh;
std_msgs::Float64 x_axis;
std_msgs::Float64 z_axis;

ros::Publisher pub1("IMU", &x_axis);
void setup()
{
  Wire.begin();
  byte status = mpu.begin();
  while (status != 0) { }
  delay(1000);
  mpu.calcOffsets();
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(pub1);
}


void loop()
{
  mpu.update();
  x_axis.data = mpu.getAngleX();
  z_axis.data = mpu.getAngleZ();
  if ((millis() - timer) > 10)
  {
    timer = millis();
  }
  pub1.publish(&x_axis);
  nh.spinOnce();

}
