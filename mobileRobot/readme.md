# Implementation of Obstacle avoidance for a mobile robot

https://github.com/user-attachments/assets/53b7515f-c440-43fb-8bcd-b5191fc617b6

# Instructions

## Maestro installation and configuration
1) Install maestro 3.0.2 from 'https://github.com/INTO-CPS-Association/maestro/releases`
2) (From Co-simulation/cosimulation_execution.sh) Ensure that _$maestro-path_ in `maestro_path=$maestro-path # Change path accordingly` is updated with the path to your maestro installation.


## ROS2/Gazebo Installation (Ubuntu 22.04)
1) Install ROS2 Humble `https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html`
2) Install Gazebo
```bash
sudo apt install ros-humble-gazebo-*
```
## Running the co-simulation
1) (from _turtlebot_ws_) 
   ```bash
   source install/setup.bash
   ```
2) (from _turtlebot_ws_) 
   ```bash
   ros2 launch MobileRobot OA_launch.py
   ```
3) (from _Co-simulation_)
   ```bash
   ./cosimulation_execution.sh
   ```
 4) Co-simulation parameters such as step-size can be changed from _coe.json_ and _multimodel_normq.json_
   
## Models
![OA_1SM](https://github.com/user-attachments/assets/6cf163a0-3786-43c5-9f76-f2b8e5a92fa1)

![OA_Mapping](https://github.com/user-attachments/assets/ee6ec365-7dbc-41df-95f8-1629b219e5ee)


## Results

![MobileRobotOA_Results](https://github.com/user-attachments/assets/771e0ea4-cad8-4634-84c4-6623c8c40924)
