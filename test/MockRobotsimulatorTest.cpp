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
  Pathplanning path;
  std::unique_ptr<PathplanningMock> plan(new PathplanningMock);
  std::unique_ptr<MockPathplanningTest> mock;
  EXPECT_CALL(*plan, AnglesForLinearPath(mock->angle, mock->path)).Times(1);
  Eigen::Vector2d angle { 0, 0 };
  EXPECT_EQ(path.AnglesForLinearPath(mock->angle, mock->path), angle);
}

/**
 *@brief Unit Test for testing AnglesForCircularPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles using google mock
 *
 */
TEST(MockPathplanningTest, TestingAnglesForCircularPathMethod) {
  Pathplanning path;
  std::unique_ptr<PathplanningMock> plan(new PathplanningMock);
  std::unique_ptr<MockPathplanningTest> mock;
  EXPECT_CALL(*plan, AnglesForCircularPath(mock->angle, mock->path)).Times(1);
  Eigen::Vector2d angle { 4, 4 };
  EXPECT_EQ(path.AnglesForCircularPath(mock->angle, mock->path), angle);
}

/**
 *@brief Unit Test for testing AnglesForContinuousPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles using google mock
 *
 */
TEST(MockPathplanningTest, TestingAnglesForContinuousPathMethod) {
  Pathplanning path;
  std::unique_ptr<PathplanningMock> plan(new PathplanningMock);
  std::unique_ptr<MockPathplanningTest> mock;
  EXPECT_CALL(*plan, AnglesForContinuousPath(mock->angle, mock->path)).Times(1);
  Eigen::Vector2d angle { 4, 5 };
  EXPECT_EQ(path.AnglesForContinuousPath(mock->angle, mock->path), angle);
}
