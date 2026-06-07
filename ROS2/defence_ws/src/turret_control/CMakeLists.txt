cmake_minimum_required(VERSION 3.8)
project(turret_control)

# 1. Default settings for C++
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 2. Find Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 3. Interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/RotateTurret.action"
)

# 4. Executable
add_executable(turret_node src/turret_node.cpp)

# 5. Link Dependencies
target_include_directories(turret_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(turret_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(turret_node
  "rclcpp"
  "rclcpp_action"
  "std_msgs"
  "std_srvs"
)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(turret_node "${cpp_typesupport_target}")

# 6. Install Rules
install(TARGETS turret_node
  DESTINATION lib/${PROJECT_NAME})

# 7. Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
