/*
 * GridMapLoader.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Peter Fankhauser
 *	 Institute: ETH Zurich, ANYbotics
 *
 */

#include "openbot/map/grid_map/grid_map_loader/GridMapLoader.hpp"

#include "glog/logging.h"

using namespace grid_map;

namespace grid_map_loader {

GridMapLoader::GridMapLoader()
{
  readParameters();
}

GridMapLoader::~GridMapLoader()
{
}

bool GridMapLoader::readParameters()
{
  // nodeHandle_.param("bag_topic", bagTopic_, std::string("/grid_map"));
  // nodeHandle_.param("publish_topic", publishTopic_, bagTopic_);
  // nodeHandle_.param("file_path", filePath_, std::string());
  // double durationInSec;
  // nodeHandle_.param("duration", durationInSec, 5.0);
  // duration_.fromSec(durationInSec);
  // TODO(duyongquan)
  return true;
}

bool GridMapLoader::load()
{

  LOG(INFO) << "Loading grid map from path " << filePath_ << ".";
  // return GridMapRosConverter::loadFromBag(filePath_, bagTopic_, map_);
  // TODO(duyongquan)
}

} /* namespace */
