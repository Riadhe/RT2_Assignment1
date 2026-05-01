from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    # Create the Container that will host both Components
    container = ComposableNodeContainer(
        name='assignment1_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            # First Component: Navigation Server
            ComposableNode(
                package='assignment1_rt2',
                plugin='assignment1_rt2::NavServerComponent',
                name='nav_server'
            ),
            # Second Component: UI Client
            ComposableNode(
                package='assignment1_rt2',
                plugin='assignment1_rt2::UiClientComponent',
                name='ui_client'
            )
        ],
        output='screen',
        emulate_tty=True # Allowing the terminal to read standard input (std::cin)
    )

    return LaunchDescription([container])
