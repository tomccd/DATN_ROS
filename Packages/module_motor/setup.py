from setuptools import find_packages, setup

package_name = 'module_motor'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tomccd',
    maintainer_email='hoangusb5g@outlook.com.vn',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "node_dc_motor=module_motor.node_dc_motor:main",
            "node_dc_servo=module_motor.node_dc_servo:main"
        ],
    },
)
