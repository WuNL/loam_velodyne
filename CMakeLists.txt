cmake_minimum_required(VERSION 2.8.3)
project(loam_velodyne)

find_package(catkin REQUIRED COMPONENTS
        pcl_conversions
        pcl_ros
        geometry_msgs
        nav_msgs
        sensor_msgs
        roscpp
        rospy
        std_msgs
        tf)

find_package(Eigen3 REQUIRED)
#find_package(PCL 1.2 REQUIRED)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
        #${PCL_INCLUDE_DIRS}
)

catkin_package(
        CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
        DEPENDS EIGEN3
        INCLUDE_DIRS include
        LIBRARIES loam
)




add_subdirectory(src/lib)

add_executable(multiScanRegistration src/multi_scan_registration_node.cpp)
target_link_libraries(multiScanRegistration ${catkin_LIBRARIES} loam)



add_executable(laserOdometry src/laser_odometry_node.cpp)
target_link_libraries(laserOdometry ${catkin_LIBRARIES} loam)

add_executable(laserMapping src/laser_mapping_node.cpp)
target_link_libraries(laserMapping ${catkin_LIBRARIES} loam)

add_executable(transformMaintenance src/transform_maintenance_node.cpp)
target_link_libraries(transformMaintenance ${catkin_LIBRARIES} loam)




