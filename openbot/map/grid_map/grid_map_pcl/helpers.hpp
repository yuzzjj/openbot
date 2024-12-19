/*
 * helpers.hpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Edo Jelavic
 *      Institute: ETH Zurich, Robotic Systems Lab
 */

#pragma once

#include <pcl/common/common.h>
#include <chrono>
#include <string>

namespace grid_map {

class GridMapPclLoader;
class GridMap;

namespace grid_map_pcl {

// TODO(duyongquan)
// void setVerbosityLevelToDebugIfFlagSet(const ros::NodeHandle& nh);

// TODO(duyongquan)
// std::string getParameterPath(const ros::NodeHandle& nh);
// TODO(duyongquan)
// std::string getOutputBagPath(const ros::NodeHandle& nh);

// TODO(duyongquan)
// std::string getPcdFilePath(const ros::NodeHandle& nh);

// TODO(duyongquan)
// std::string getMapFrame(const ros::NodeHandle& nh);

// TODO(duyongquan)
// std::string getMapRosbagTopic(const ros::NodeHandle& nh);

// TODO(duyongquan)
// std::string getMapLayerName(const ros::NodeHandle& nh);

// TODO(duyongquan)
// void saveGridMap(const grid_map::GridMap& gridMap, const ros::NodeHandle& nh, const std::string& mapTopic);

inline void printTimeElapsedToRosInfoStream(const std::chrono::system_clock::time_point& start, const std::string& prefix);

// TODO(duyongquan)
// void processPointcloud(grid_map::GridMapPclLoader* gridMapPclLoader, const ros::NodeHandle& nh);

using Point = ::pcl::PointXYZ;
using Pointcloud = ::pcl::PointCloud<Point>;
enum class XYZ : int { X, Y, Z };

Eigen::Affine3f getRigidBodyTransform(const Eigen::Vector3d& translation, const Eigen::Vector3d& intrinsicRpy);
Eigen::Matrix3f getRotationMatrix(double angle, XYZ axis);

// processing point clouds
Eigen::Vector3d calculateMeanOfPointPositions(Pointcloud::ConstPtr inputCloud);
Pointcloud::Ptr transformCloud(Pointcloud::ConstPtr inputCloud, const Eigen::Affine3f& transformMatrix);
Pointcloud::Ptr loadPointcloudFromPcd(const std::string& filename);

} /* namespace grid_map_pcl*/

} /* namespace grid_map */
