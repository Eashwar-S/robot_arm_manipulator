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
 * @author Part1: Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief test cases (Google Test framework) for Robotsimulator class
 *
 * @version 1
 *
 * @date 2019-10-12
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
  PathplanningMock path;
  Pathplanning path1;
  Robotsimulator simulate = Robotsimulator(path);
  Eigen::Vector2d angle{3,4};
  Eigen::Vector2d angle1;
};

TEST_F(MockPathplanningTest, TestingAnglesForCircularPathMethod) {
  EXPECT_CALL(path, AnglesForCircularPath(angle)).Times(AtLeast(1));
  Eigen::Vector2d angle{4,4};

}

