import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/stywestern/ros2_ws_python/install/my_robot_controller'
