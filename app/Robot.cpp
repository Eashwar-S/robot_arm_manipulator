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
 * @file Robot.cpp
 *
 * @author Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Robot class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This program implements the methods of the
 * Robot class from Robot.hpp header file
 *
 */

#include "Robot.hpp"

/**
 * @brief constructor to set initial values
 *
 * @param j1 is a 2d float vector for initializing joint1
 *
 * @param j2 is a 2d float vector for initializing joint2
 *
 * @param eEffector is a 2d float vector for initializing endEffector
 *   vector
 *
 * @return none
 *
 */

Robot::Robot(Eigen::Vector2f j1, Eigen::Vector2f j2,
             Eigen::Vector2f eEffector) {
  joint1 = j1;
  joint2 = j2;
  endEffector = eEffector;
}

/**
 * @brief method to check the target position is within workspace or not
 *
 * @param x variable represents x-coordinate of target position
 *
 * @param y variable represents y-coordinate of target position
 *
 * @return boolean - true for inside and false for outside the workspace
 *
 */

bool Robot::isInWorkspace(double x, double y) {
  /// Assumes that for the robot, link length 1 >= link length2
  double link1 = sqrt(
      pow((joint1[0] - joint2[0]), 2) + pow((joint1[1] - joint2[1]), 2));
  double link2 = sqrt(
      pow((joint2[0] - endEffector[0]), 2)
      + pow((joint2[1] - endEffector[1]), 2));
  double targetdist = sqrt(pow((joint1[0] - x), 2) + pow((joint1[1] - y), 2));

  double furthestReachdistance = link1 + link2;
  double lowestReachdistance = link1 - link2;

  return targetdist <= furthestReachdistance
      && targetdist >= lowestReachdistance;
}

/**
 * @brief method to check whether robot has reached target
 *
 * @param x variable represents x-coordinate of target position
 *
 * @param y variable represents y-coordinate of target position
 *
 * @return boolean - true for inside and false if target is reached
 *
 */

bool Robot::targetReached(double x, double y) {
  double distance = sqrt(
      pow((x - endEffector[0]), 2) + pow((y - endEffector[1]), 2));
  return distance <= 0.1;
}

