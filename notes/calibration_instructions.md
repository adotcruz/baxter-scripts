# Notes
In each new terminal you create, source the workspace's `devel/setup.bash` with `source_baxter`, then run `baxter.sh`

# Start Baxter, rviz, and the sensor
`run_baxter`, or `screen -c src/ein/ein_baxter.screenrc`
Start the sensor with `roslaunch occgrid_robot structure_sensor.launch`
Start rviz

# Launch 
`rosrun lcsr_tf_tools interactive_transform_publisher 0.095 -0.005 0.049 0 0 0 /left_gripper /structure_sensor_link rate=10`

Add interactive transform to rviz with topic "/interactive_transform_publisher/structure_sensor_link/update"

Point the camera towards a section of the arm.
Adjust interactive marker until cloud and model are well aligned from multiple are configurations. Then read out the transform with `rosrun tf tf_echo /ee_linkcamera_link` and set the values in `structure_sensor_baxter_tf.cpp` accordingly
