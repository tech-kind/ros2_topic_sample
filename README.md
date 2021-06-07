# ros2_topic_sample

Sample ROS2 programs for topics using Publisher and Subscription

# Requirement

* Ubuntu 20.04
* ROS2 foxy

# Usage

## Build

```bash
$ git clone https://github.com/tech-kind/ros2_topic_sample.git
$ cd ros2_topic_sample
$ colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release --catkin-skip-building-tests --symlink-install
```

## Launch

* cpp

``` bash
$ ros2 launch simple_pubsub_cpp simple_pubsub_cpp.launch.py
```

* python

``` bash
$ ros2 launch simple_pubsub_python simple_pubsub_python.launch.py
```
 
# Author
 
* tech-kind
 
# License
 
"ros2_topic_sample" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License), see LICENSE.
