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
 * @file RobotTest.cpp
 *
 * @author Part1: Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief test cases (Google Test framework) for Robot class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .cpp file has test cases definitions for the class methods
 * of Robot class
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Robot.hpp"

/**
 *@brief Unit Test for testing isInWorkspace(double,double)
 * and rotateRobot(double,double) method
 *
 *This test checks if the return value of the isInWorkspace(double,double)
 *method is true or false
 *This test checks if the return value of the targetReached(double,double)
 *method returns true or false to see if the target is reached or not.
 *
 */

TEST(Robot, testisInWorkspaceMethod) {
  Eigen::Vector2f j1(1, 1);
  Eigen::Vector2f j2(1, 1);
  Eigen::Vector2f eEffector(2.0, 2.0);
  Robot robot(j1, j2, eEffector);
  EXPECT_EQ(true, robot.isInWorkspace(1.0, 1.0));
}

/**
 *@brief Unit Test for testing isInWorkspace(double,double)
 * and rotateRobot(double,double) method
 *
 *This test checks if the return value of the targetReached(double,double)
 *method returns true or false to see if the target is reached or not.
 *
 */

TEST(Robot, testtargetReachedMethod) {
  Eigen::Vector2f j1(1, 1);
  Eigen::Vector2f j2(1, 1);
  Eigen::Vector2f eEffector(2.0, 2.0);
  Robot robot(j1, j2, eEffector);
  EXPECT_EQ(true, robot.targetReached(2.0, 2.0));
}
