#include <ros/ros.h>
#include "loam_velodyne/LaserMapping.h"


/** Main node entry point. */
int main (int argc, char **argv)
{
    ROS_INFO("-1");
    ros::init(argc, argv, "laserMapping");
    ROS_INFO("0");
    ros::NodeHandle node;
    ROS_INFO("1");
    ros::NodeHandle privateNode("~");
    ROS_INFO("2");

    // pcl::PointCloud<pcl::PointXYZI>::Ptr _laserCloudCornerLast(new pcl::PointCloud<pcl::PointXYZI>());

    ROS_INFO("3");

    loam::LaserMapping laserMapping(0.1);

    ROS_INFO("4");

    if (laserMapping.setup(node, privateNode))
    {
        // initialization successful
        laserMapping.spin();
    }

    return 0;
}
