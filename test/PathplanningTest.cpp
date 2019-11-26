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
 * @file PathplanningTest.cpp
 *
 * @author Part1: Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief test cases (Google Test framework) for Pathplanning class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .cpp file has test cases definitions for the class methods
 * of Pathplanning class
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Pathplanning.hpp"
/**
 *@brief Unit Test for testing AnglesForLinearPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles
 *
 */
Pathplanning plan;
TEST(Pathplanning, AnglesForLinearPathMethodTesting) {
  Eigen::Vector2d angles;
  angles(0) = 0;
  angles(1) = 0;
  Eigen::Vector2d path(0, 0);
  Eigen::Vector2d angles1;
  angles1(0) = 0;
  angles1(1) = 0;
  EXPECT_EQ(angles1, plan.AnglesForLinearPath(angles, path));
}

/**
 *@brief Unit Test for testing AnglesForContinuousPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles
 *
 */

TEST(Pathplanning, AnglesForContinuousPathMethodTesting) {
  Eigen::Vector2d angles(1, 1);
  Eigen::Vector2d angles1(2, 2);
  EXPECT_EQ(angles1, plan.AnglesForContinuousPath(angles));
}

/**
 *@brief Unit Test for testing AnglesForCircularPath method
 *
 *This test checks if the return value of the method is same
 *the Eigen::Vector2d angles
 *
 */

TEST(Pathplanning, AnglesForCircularPathMethodTesting) {
  Eigen::Vector2d angles(1, 1);
  Eigen::Vector2d angles1(2, 1);
  EXPECT_EQ(angles1, plan.AnglesForCircularPath(angles));
}
