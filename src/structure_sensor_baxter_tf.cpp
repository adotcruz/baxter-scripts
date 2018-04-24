#include <ros/ros.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <cstdio>
#include <tf2/LinearMath/Quaternion.h>

int main(int argc, char **argv)
{
  ros::init(argc,argv, "structure_sensor_baxter_static_tf_broadcaster");

  std::string sensor_side;
  ros::NodeHandle nh;
  if (!nh.getParam("/sensor_side", sensor_side))
  {
    ROS_ERROR_STREAM("Could not find param /sensor_side.");
    return 1;
  }

  static tf2_ros::StaticTransformBroadcaster static_broadcaster;
  geometry_msgs::TransformStamped static_transformStamped;

  static_transformStamped.header.stamp = ros::Time::now();
  // TODO: Parameterize right and left
  static_transformStamped.header.frame_id = sensor_side + "_gripper";
  // TODO: structure_sensor = rosparam
  static_transformStamped.child_frame_id = "structure_sensor_link";
  
  /*
  Calibration EE Pose:
  R: 0.725866 -0.630611 0.116333 -0.001222 0.999998 0.001162 -0.001101 createEEPose
  L: 0.605159 0.498464 0.418729 0.038558 0.764707 -0.642813 0.022978 createEEPose

  RJoints: -0.073292 -0.419934 0.758610 0.919676 -0.711514 1.285107 -0.245967 createArmPose
  LJoints: 0.471209 -0.398145 -1.180408 1.016187 -0.317516 1.903336 0.253681 createArmPose


  Translation: [0.029, -0.048, -0.053]
  Rotation: in Quaternion [0.712, 0.007, 0.702, -0.015]

  Translation: [0.029, -0.049, -0.071]
  Rotation: in Quaternion [0.711, 0.040, 0.701, -0.040]

  Translation: [0.076, -0.040, -0.070]
  Rotation: in Quaternion [0.697, 0.020, 0.716, -0.035]
  */


  static_transformStamped.transform.translation.x = 0.029;
  static_transformStamped.transform.translation.y = -0.048;
  static_transformStamped.transform.translation.z = -0.053;
  
  static_transformStamped.transform.rotation.x = 0.712;
  static_transformStamped.transform.rotation.y = 0.007;
  static_transformStamped.transform.rotation.z = 0.702;
  static_transformStamped.transform.rotation.w = -0.015;
  static_broadcaster.sendTransform(static_transformStamped);

  ros::spin();
  return 0;
};