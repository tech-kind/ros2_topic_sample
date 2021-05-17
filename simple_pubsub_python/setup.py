from setuptools import setup

package_name = 'simple_pubsub_python'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Hayakawa Ken',
    maintainer_email='ken_hayakawa@tech-kind.biz',
    description='Example of simple publisher and subscription',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'simple_publisher_node = ' + package_name + '.simple_publisher:main',
            'simple_subscription_node = ' + package_name + '.simple_subscription:main'
        ],
    },
)
