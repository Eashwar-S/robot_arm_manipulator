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
 * @file Robot.hpp
 *
 * @author Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)//
 *
 * @brief declaration for Robot class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of the robot arm mainpulator.
 *
 */
#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_

#include <math.h>
#include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <string>

/**
 *
 * @brief declaration of Robot class
 *
 */

class Robot {
 public:
  /**
   * @brief constructor to set initial values
   *
   * @param length1 variable for initializing the member linkLength1
   *
   * @param length2 variable for initializing the member linkLength2
   *
   * @return none
   *
   */
  Robot(Eigen::Vector2f joint1, Eigen::Vector2f joint2,
        Eigen::Vector2f endEffector);

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

  bool isInWorkspace(double x, double y);

  /**
   * @brief method to check whether robot has reached target
   *
   * @param x variable represents x-coordinate of target position
   *
   * @param y variable represents y-coordinate of target position
   *
   * @return boolean - true if target is reached and false otherwise
   *
   */

  bool targetReached(double x, double y);

 private:
  Eigen::Vector2f joint1;
  Eigen::Vector2f joint2;
  Eigen::Vector2f endEffector;
};
#endif  // INCLUDE_ROBOT_HPP_
