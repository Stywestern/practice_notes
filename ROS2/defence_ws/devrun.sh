#!/bin/bash

colcon build --packages-select turret_control --symlink-install &&
. install/setup.bash &&
ros2 run turret_control turret_node