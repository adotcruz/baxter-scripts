#!/usr/bin/env python
# license removed from brevity

import rospy
from std_msgs.msg import String


def talker(count):
	pub = rospy.Publisher('/ein/left/forth_commands', String, queue_size=1)
	rospy.init_node('stalker', anonymous=True)
	rate = rospy.Rate(1)
	while not rospy.is_shutdown():
		# if(count == 0):
		# 	string = "currentPose .410000 setEEPosePX .407000 setEEPosePY moveEeToPoseWord"
		# 	count = 1
		# if(count == 1):
		# 	string = "goHome"
		# 	count = 0
		string = "currentPose .410000 setEEPosePX .407000 setEEPosePY moveEeToPoseWord"
		count+=1
		if(count == 4):
			count = 0
			string = "goHome"
		rospy.loginfo(string)
		rospy.loginfo(count)
		pub.publish(string)
		rate.sleep()


if __name__ == '__main__':
	try:
		count = 0
		talker(count)
		print(count)
	except rospy.ROSInterruptException:
		pass