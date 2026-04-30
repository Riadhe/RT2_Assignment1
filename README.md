# Research Track 2 - Assignment 1

**Author:** Riadh Bahri (ID: 8335614)  
**Course:** Research Track 2 | Master in Robotics Engineering, University of Genoa  
**Language Used:** C++  

## 📝 Project Description
This repository contains the first assignment for the Research Track 2 course. The objective of this project is to implement a Navigation Server and a User Interface (UI) Client using **ROS 2 Components** (`rclcpp_components`). 

By utilizing components, both the server and the client are loaded into the same executable (Component Container), which allows them to communicate efficiently using **Intra-Process Communication**, significantly reducing latency and overhead.

### Repository Structure
The workspace consists of three main packages:
1. `assignment1_interfaces`: Contains the custom ROS 2 Action definitions (`Navigate.action`).
2. `assignment1_rt2`: The core package containing the C++ implementation of the `NavServerComponent` and `UiClientComponent`.
3. `bme_gazebo_sensors`: The simulation environment containing the robot and the Gazebo world.

---

## Prerequisites & Installation

To test this project, clone the repository into a ROS 2 workspace (tested on ROS 2 Jazzy) and build it:
```bash
# Create a workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone the repository
git clone [https://github.com/Riadhe/RT2_Assignment1.git](https://github.com/Riadhe/RT2_Assignment1.git) .

# Build the workspace
cd ~/ros2_ws
colcon build

# Source the workspace
source install/setup.bash

```
### How to Run the Code
To execute the simulation and load the components into the container, follow these steps using three separate terminals.

Terminal 1: Launch the Simulation
First, start the Gazebo world and spawn the robot:

```Bash


source /opt/ros/jazzy/setup.bash
source install/setup.bash

# Start the simulation environment
ros2 launch bme_gazebo_sensors world.launch.py

# In the same or a new terminal, spawn the robot
ros2 launch bme_gazebo_sensors spawn_robot.launch.py
```

Terminal 2: Start the Component Container
Initialize the ROS 2 component container that will host our nodes:

```bash

source /opt/ros/jazzy/setup.bash
source install/setup.bash

ros2 run rclcpp_components component_container
Terminal 3: Load the Server and Client Components
Load the components dynamically into the running container. They will automatically connect and enable intra-process communication.

```bash

source /opt/ros/jazzy/setup.bash
source install/setup.bash

# 1. Load the Navigation Server Component
ros2 component load /ComponentManager assignment1_rt2 assignment1_rt2::NavServerComponent

# 2. Load the UI Client Component
ros2 component load /ComponentManager assignment1_rt2 assignment1_rt2::UiClientComponent
(Note: Alternatively, you can use the provided launch file to start both components automatically: ros2 launch assignment1_rt2 assignment1.launch.py)
```
### How to Interact with the Robot
Once the UiClientComponent is loaded in Terminal 3, it will prompt you for input:

Enter the target coordinates as three floating-point numbers (x y z). For example: 5.0 2.0 0.0.

The robot will start moving towards the goal, and you will see real-time distance feedback.

To cancel the current goal while the robot is moving, type c and press Enter. The robot will stop immediately.


---
