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
 * @file MockPathplanningTest.cpp
 *
 * @author: Eashwar Sathyamurthy
 *
 * @brief test cases (Google Test framework) for Robotsimulator class
 *
 * @version 1
 *
 * @date 2019-11-25
 *
 * This .cpp file mocks Pathplanning class methods to enable testing.
 *
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include "Robotsimulator.hpp"
#include <PathplanningMock.hpp>

using ::testing::_;
using ::testing::AtLeast;

class MockPathplanningTest : public ::testing::Test {
 public:
  Eigen::Vector2d angle { 3, 4 };
  Eigen::Vector2d path { 0, 0 };
  Eigen::Vector2d angle1;
};
/**
 *@brief Unit Test for testing AnglesForLinearPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles using google mock
 *
 */
TEST(MockPathplanningTest, TestingAnglesForLinearPathMethod) {
  PathplanningMock mock;
  Pathplanning path;
  std::unique_ptr<MockPathplanningTest> plan;
  Eigen::Vector2d angle { 0, 0 };
  EXPECT_CALL(mock, AnglesForLinearPath(plan->angle, plan->path)).Times(1);
  EXPECT_EQ(angle, path.AnglesForLinearPath(plan->angle, plan->path));
}

/**
 *@brief Unit Test for testing AnglesForCircularPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles using google mock
 *
 */
TEST(MockPathplanningTest, TestingAnglesForCircularPathMethod) {
  PathplanningMock mock;
  Pathplanning path;
  std::unique_ptr<MockPathplanningTest> plan;
  EXPECT_CALL(mock, AnglesForCircularPath(plan->angle)).Times(1);
  Eigen::Vector2d angle { 4, 4 };
  EXPECT_EQ(path.AnglesForCircularPath(plan->angle), angle);
}

/**
 *@brief Unit Test for testing AnglesForContinuousPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles using google mock
 *
 */
TEST(MockPathplanningTest, TestingAnglesForContinuousPathMethod) {
  PathplanningMock mock;
  Pathplanning path;
  std::unique_ptr<MockPathplanningTest> plan;
  EXPECT_CALL(mock, AnglesForContinuousPath(plan->angle)).Times(1);
  Eigen::Vector2d angle { 4, 5 };
  EXPECT_EQ(path.AnglesForCircularPath(plan->angle), angle);
}

