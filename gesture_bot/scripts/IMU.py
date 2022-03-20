#!/usr/bin/env python3
import rospy
import time
from std_msgs.msg import Float64

pub = rospy.Publisher('move', Float64, queue_size=10)

def var(data):
    global a
    a=data.data
def talker():
    rospy.init_node('talker', anonymous=True)
    rospy.Subscriber('IMU',Float64,var)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        pub.publish(a)
        print(a)
        rate.sleep()
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
