# Research Track 2 - Assignment 1

**Author:** Riadh Bahri  
**Student ID** 8335614   

## Project Description

This repository contains the implementation of the first assignment . The objective is to develop an action-based navigation stack that allows a simulated robot to move around in environment.

This project implements:
1. **A User Interface (Action Client):** A node that allows the user to set a target pose `(x, y, theta)` for the robot, or cancel the ongoing target.
2. **An Action Server:** A node that receives the target and implements the robot navigation logic to reach it.
3. **Component-Based Execution:** Both the User Interface (Action Client) and the Action Server are implemented as **libraries (plugins)**. They are executed dynamically within the **same container** using `rclcpp_components`.

---

##  Repository Structure and Modules

The workspace is divided into three packages to keep the architecture organized:

### 1. `assignment1_interfaces`
* This package defines the custom communication protocol. It contains the custom ROS 2 Action definition (`Navigate.action`) specifying the Goal (`x`, `y`, `theta`), the Result, and the continuous Feedback (e.g., the remaining distance to the target).

### 2. `assignment1_rt2`
*  This is the core package containing the C++ source code for the assignment. It implements the two required plugins:
  * `NavServerComponent`: The Action Server plugin. It computes the required velocities to drive the robot towards the requested `(x, y, theta)` target based on odometry, and publishes commands to the robot.
  * `UiClientComponent`: The Action Client plugin. It handles user input from the terminal, sends the goal to the server, prints real-time feedback, and processes the cancellation command (e.g., typing 'c + enter') to stop the robot.

### 3. `bme_gazebo_sensors`
*  This is the simulation package provided in class. It launches the Gazebo world and spawns the robot model so we can visualize and test the navigation stack.
---

## Prerequisites & Installation

To test this project, clone the repository into a ROS 2 workspace (tested on ROS 2 Jazzy) and build it:
```bash
# Create a workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone the repository
git clone https://github.com/Riadhe/RT2_Assignment1.git 

# Build the workspace
cd ~/ros2_ws
colcon build

# Source the workspace
source install/setup.bash

```
## How to Run the Code
To execute the simulation and load the components into the container, follow these steps using three separate terminals.

Terminal 1: Launch the Simulation
First, start the Gazebo world and the spawned robot:

```Bash
source install/setup.bash
ros2 launch bme_gazebo_sensors spawn_robot.launch.py
```

Terminal 2: Start the Component Container
Initialize the ROS 2 component container that will host our nodes:

```bash
source install/setup.bash
ros2 run rclcpp_components component_container
```

Terminal 3: Load the Server and Client Components
Load the components dynamically into the running container. They will automatically connect and enable intra-process communication.
```bash
ros2 component load /ComponentManager assignment1_rt2 assignment1_rt2::NavServerComponent
ros2 component load /ComponentManager assignment1_rt2 assignment1_rt2::UiClientComponent
```

## How to Interact with the Robot

Once the `UiClientComponent` is loaded from Terminal 3, **go back to Terminal 2** (where the component container is running). It will prompt you for input:

* Enter the target coordinates as three floating-point numbers `(x y theta)`. For example: `5.0 2.0 0.0`.
* The robot will start moving towards the goal, and you will see real-time distance feedback.
* To cancel the current goal while the robot is moving, type `c` and press Enter. The robot will stop immediately.

---
