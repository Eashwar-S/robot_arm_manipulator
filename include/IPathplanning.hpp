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
 * @file Pathplanning.hpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief declaration for Pathplanning class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of path planning of robot arm mainpulator.
 *
 */
#ifndef INCLUDE_IPATHPLANNING_HPP_
#define INCLUDE_IPATHPLANNING_HPP_

#include <Eigen/Dense>
#include <iostream>
#include <vector>

#define PI 3.1415926

/**
 *
 * @brief declaration of Pathplanning class
 *
 */

class IPathplanning {
 public:
  /**
   *   @brief  Default constructor for Pathplanning class
   *
   *   @param  none
   *   @return void
   */

  IPathplanning();

  /**
   *   @brief  Destructor for Pathplanning class
   *
   *   @param  none
   *   @return void
   */
  virtual ~IPathplanning();
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

  virtual Eigen::Vector2d& AnglesForLinearPath(Eigen::Vector2d& angles,
                                      Eigen::Vector2d path);

  /**
   * @brief method to calculate joint angle velocities for circular path
   *
   * @param angles 2x1 vector containing linear and angular velocity
   *
   * @return void- modified angle is incremented by joint velocities(step size)
   *
   */

  virtual Eigen::Vector2d& AnglesForCircularPath(Eigen::Vector2d& angles);

  /**
   * @brief method to calculate joint angle velocities for continuous path
   *
   * @param angles 2x1 vector containing linear and angular velocity
   *
   * @return void- modified angle is incremented by joint velocities(step size)
   *
   */
  virtual Eigen::Vector2d& AnglesForContinuousPath(Eigen::Vector2d& angles);
};
#endif  // INCLUDE_IPATHPLANNING_HPP_
