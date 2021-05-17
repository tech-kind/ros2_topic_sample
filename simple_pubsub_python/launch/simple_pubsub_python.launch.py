import os
from ament_index_python.packages import get_package_share_directory
import launch
import launch_ros.actions

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('simple_pubsub_python'),
        'config',
        'simple_pubsub_python.param.yaml'
    )

    pub = launch_ros.actions.Node(
        package='simple_pubsub_python',
        executable='simple_publisher_node',
        name='simple_publisher_node1',
        parameters=[config],
        output='screen'
    )

    sub = launch_ros.actions.Node(
        package='simple_pubsub_python',
        executable='simple_subscription_node',
        name='simple_subscription_node1',
        parameters=[config],
        output='screen'
    )

    return launch.LaunchDescription([
        pub,
        sub
    ])
