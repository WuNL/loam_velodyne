//
// Created by wunl on 18-8-23.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/voxel_grid.h>

int
main (int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/wunl/workspace/data/tutorials/region_growing_rgb_tutorial.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from test_pcd.pcd with the following fields: "
              << std::endl;
//    for (size_t i = 0; i < cloud->points.size (); ++i)
//        std::cout << "    " << cloud->points[i].x
//                  << " "    << cloud->points[i].y
//                  << " "    << cloud->points[i].z << std::endl;


    pcl::VoxelGrid<pcl::PointXYZ> downSizeFilter;
    downSizeFilter.setInputCloud(cloud);
    downSizeFilter.setLeafSize (0.01f, 0.01f, 0.01f);
    downSizeFilter.filter (*cloud_filtered);



    //... populate cloud
    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
    viewer.showCloud (cloud_filtered);
    while (!viewer.wasStopped ())
    {
    }

    return (0);
}