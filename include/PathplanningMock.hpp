#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "IPathplanning.hpp"

class PathplanningMock : public virtual IPathplanning {
 public:
  MOCK_METHOD1(AnglesForCircularPath, Eigen::Vector2d&(Eigen::Vector2d&));
  MOCK_METHOD1(AnglesForContinuousPath, Eigen::Vector2d&(Eigen::Vector2d&));
  MOCK_METHOD2(AnglesForLinearPath, Eigen::Vector2d&(Eigen::Vector2d& , Eigen::Vector2d&));
};
