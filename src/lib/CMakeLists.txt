SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#find_package(PCL REQUIRED)
#link_directories(${PCL_LIBRARY_DIRS})
#add_definitions(${PCL_DEFINITIONS})
#link_libraries(${PCL_LIBRARIES})
message("-----------------")
message(${PCL_LIBRARIES})
message("-----------------")

link_libraries(${PCL_LIBRARIES})

add_library(loam
        math_utils.h
        ScanRegistration.cpp
        MultiScanRegistration.cpp
        LaserOdometry.cpp
        LaserMapping.cpp
        TransformMaintenance.cpp)
target_link_libraries(loam ${catkin_LIBRARIES})
