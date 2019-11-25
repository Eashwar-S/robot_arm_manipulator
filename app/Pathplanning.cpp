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
 * @file Pathplanning.cpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Pathplanning class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This program implements the methods of the
 * Pathplanning class from Pathplanning.hpp header file
 *
 */

#include "Pathplanning.hpp"
#include "IPathplanning.hpp"
/**
 * @brief method to calculate joint angle velocities
 *
 * @param jacobianInv a 2x2 matrix used in calculating joint velocities
 *
 * @param angles 2x1 vector containing linear and angular velocity
 *
 * @return void- modified angle is incremented by joint velocities(step size)
 *
 */

Eigen::Vector2d& Pathplanning::AnglesForLinearPath(Eigen::Vector2d& angles,
                                                   Eigen::Vector2d path) {
  Eigen::MatrixXd jacobianInv(2, 2);
  /// convert angles to radians
  float th1 = angles[0] * PI / 180;
  float th2 = angles[1] * PI / 180;
  /// Initializing Link lengths
  int l1 = 20, l2 = 20;
  /// Calculating Inverse Jacobian Coordinates
  int m11 = cos(th1 + th2) / (l1 * sin(th2));
  int m12 = sin(th1 + th2) / (l1 * sin(th2));
  int m21 = -(l2 * cos(th1 + th2) + l1 * cos(th1)) / (l1 * l2 * sin(th2));
  int m22 = -(l2 * sin(th1 + th2) + l1 * sin(th1)) / (l1 * l2 * sin(th2));
  jacobianInv << m11, m12, m21, m22;

  std::cout << jacobianInv << std::endl;
  // convert back radians to degrees
  angles = angles + 0.01 * jacobianInv * path * 180 / PI;
  Eigen::Vector2d& angles1 = angles;
  return angles1;
}

/**
 * @brief method to calculate joint angle velocities for circular path
 *
 * @param angles 2x1 vector containing linear and angular velocity
 *
 * @return void- modified angle is incremented by joint velocities(step size)
 *
 */

Eigen::Vector2d& Pathplanning::AnglesForCircularPath(Eigen::Vector2d& angles) {
  angles[0] += 1;
  return angles;
}

/**
 * @brief method to calculate joint angle velocities for continuous path
 *
 * @param angles 2x1 vector containing linear and angular velocity
 *
 * @return void- modified angle is incremented by joint velocities(step size)
 *
 */
Eigen::Vector2d& Pathplanning::AnglesForContinuousPath(
    Eigen::Vector2d& angles) {
  angles[0] += 1;
  angles[1] += 1;
  return angles;
}
