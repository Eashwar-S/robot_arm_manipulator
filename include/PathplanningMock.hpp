#ifndef INCLUDE_PATHPLANNINGMOCK_H_
#define INCLUDE_PATHPLANNINGMOCK_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <Eigen/Dense>
#include "IPathplanning.hpp"

/**
 *
 * @brief declaration of Pathplanning mock methods
 *
 */

class PathplanningMock : public IPathplanning {
 public:
  /// Mocks AnglesForCircularPath methos in Pathplanning class
  MOCK_METHOD1(AnglesForCircularPath, Eigen::Vector2d&(Eigen::Vector2d&));
  /// Mocks AnglesForContinuousPath methos in Pathplanning class
  MOCK_METHOD1(AnglesForContinuousPath, Eigen::Vector2d&(Eigen::Vector2d&));
  /// Mocks AnglesForLinearPath methos in Pathplanning class
  MOCK_METHOD2(AnglesForLinearPath, Eigen::Vector2d&(Eigen::Vector2d& , Eigen::Vector2d&));
};
#endif /* INCLUDE_PATHPLANNINGMOCK_H_ */
