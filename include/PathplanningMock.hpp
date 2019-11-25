/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file PathplanningMock.hpp
 *
 * @author Eashwar Sathyamurthy(Navigator)
 *
 * @brief hpp file used for declaring mock methods
 *
 * @version 1
 *
 * @date 2019-11-25
 *
 *
 */
#ifndef INCLUDE_PATHPLANNINGMOCK_HPP_
#define INCLUDE_PATHPLANNINGMOCK_HPP_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <iostream>
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
  MOCK_METHOD2(AnglesForLinearPath,
               Eigen::Vector2d&(Eigen::Vector2d& , Eigen::Vector2d&));
};
#endif  // INCLUDE_PATHPLANNINGMOCK_HPP_
