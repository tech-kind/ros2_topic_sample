cmake_minimum_required(VERSION 3.5)
project(simple_pubsub_cpp)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

include_directories(include)

ament_auto_add_executable(simple_publisher_node
  src/simple_publisher_main.cpp
  src/simple_publisher.cpp
)

ament_auto_add_executable(simple_subscription_node
  src/simple_subscription_main.cpp
  src/simple_subscription.cpp
)

install(TARGETS
  simple_publisher_node
  simple_subscription_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
