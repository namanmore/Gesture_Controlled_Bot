#include <ros.h>
#include <std_msgs/Float64.h>
int dd[] = {true, true};
int i;
int pwm[] = { 2, 3} , dir[] = {4, 5};
int val = 200;
ros::NodeHandle  nh;
void subscribercb( const std_msgs::Float64& move_msg)
{
  if (move_msg.data > 10.0)
  {
    digitalWrite(13, HIGH);
    forward();
  }
  else if (move_msg.data < -10.0)
  {
    digitalWrite(13, LOW);
    back();
  }
  else
  {
    off();
  }
}
ros::Subscriber<std_msgs::Float64> sub1("move", &subscribercb );
void setup()
{
  for (i = 0; i < 2; i++)
  {
    pinMode(dir[i], OUTPUT);
    pinMode(pwm[i], OUTPUT);
  }

  nh.initNode();
  nh.subscribe(sub1);

}
void forward()
{

  for (i = 0; i < 2; i++)
  {
    digitalWrite(dir[i], dd[i]);
    analogWrite(pwm[i], val);
  }
}
void back()
{

  for (i = 0; i < 2; i++)
  {
    digitalWrite(dir[i], !dd[i]);
    analogWrite(pwm[i], val);
  }
}
void rotate_r()
{
  for (i = 0; i < 1; i++)
  {
    digitalWrite(dir[i], dd[i]);
    analogWrite(pwm[i], val);
  }
}
void rotate_l()
{
  for (i = 1; i < 2; i++)
  {
    digitalWrite(dir[i], dd[i]);
    analogWrite(pwm[i], val);
  }
}
void off()
{
  for (i = 0; i < 2; i++)
  {
    analogWrite(pwm[i], 0);
  }
}
void loop()
{
  ros::Subscriber<std_msgs::Float64> sub1("move", &subscribercb );
  nh.spinOnce();
}
