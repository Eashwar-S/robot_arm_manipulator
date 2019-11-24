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
 * @brief test cases (Google Test framework) for Robotsimulator class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .cpp file has test cases definitions for the class methods
 * of Robotsimulator class
 *
 */
#include <gtest/gtest.h>
#include <iostream>
#include "Robotsimulator.hpp"

/**
 *@remark This test checks drawOuterCircle() method returns same value
 *given by the tester
 *
 */
TEST(Robotsimulator, drawOuterCircleMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawOuterCircle(0, 0, 0));
}

/**
 *@remark This test checks drawInnerCircle() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawInnerCircleMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawInnerCircle(0, 0, 0));
}

/**
 *@remark This test checks drawLinkBtnJoints() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawLinkBtnJointsMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawLinkBtnJoints(0.0, 0.0, 0.0, 0.0));
}

/**
 *@remark This test checks drawJoint() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawJointMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawJoint(0, 0));
}

/**
 *@remark This test checks drawEndEffector() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawEndEffectorMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawEndEffector(0.0, 0.0));
}

/**
 *@remark This test checks drawTarget() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawTargetMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawTarget(0.0, 0.0));
}

/**
 *@remark This test checks drawPathCircle() method returns same value
 *given by the tester
 *
 */

TEST(Robotsimulator, drawPathCircleMethodTesting) {
  EXPECT_EQ(1, Robotsimulator::drawPathCircle());
}
