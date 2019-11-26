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
 * @file Robotsimulator.hpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief declaration for Robotsimulator class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of the robot arm mainpulator.
 *
 */
#ifndef INCLUDE_ROBOTSIMULATOR_HPP_
#define INCLUDE_ROBOTSIMULATOR_HPP_

#include <GL/glut.h>
#include <vector>
#include <memory>
#include "Pathplanning.hpp"
#include "Robot.hpp"


#define PI 3.1415926

/**
 *
 * @brief declaration of Robotsimulator class
 *
 */

class Robotsimulator {
 public:
  /// static objects of Robot and Pathplanning class
  static Robot robot;
  static Pathplanning planPath;
  /**
   * @brief method to draw outer circle of joint
   *
   * @param centerx - x Coordinate of Joint
   *
   * @param centery - y Coordinate of Joint
   *
   * @return int - for testing purposes
   *
   */

  static int drawOuterCircle(int centerx, int centery, int r);

  /**
   * @brief method to draw inner circle of joint
   *
   * @param centerx - x Coordinate of Joint
   *
   * @param centery - y Coordinate of Joint
   *
   * @return int - for testing purposes
   *
   */

  static int drawInnerCircle(int centerx, int centery, int r);

  /**
   * @brief method to draw the joint using outercircle and innercircle methods
   *
   * @param centerx - x Coordinate of Joint
   *
   * @param centery - y Coordinate of Joint
   *
   * @return returns 1 to indicate success
   *
   */

  static int drawJoint(int centerx, int centery);

  /**
   * @brief method to draw link between joints
   *
   * @param cx1 - X coordinate of Joint1
   *
   * @param cy1 - Y coordinate of Joint1
   *
   * @param cx2 - X coordinate of Joint2
   *
   * @param cy2 - Y coordinate of joint2
   *
   * @return int - returns 1 to indicate success
   *
   */

  static int drawLinkBtnJoints(float cx1, float cy1, float cx2, float cy2);

  /*
   * @brief method to draw the end effector
   *
   * @param centerx- x Coordinate of center of endEffector
   *
   * @param centery- y Coordinate of center of endEffector
   *
   * @return returns 1 to indicate success
   *
   */

  static int drawEndEffector(float centerx, float centery);

  /**
   * @brief method to display robot arm
   *
   * @param void
   *
   * @return void
   *
   */

  static void displayArm(void);

  /**
   * @brief method to reshape the arm
   *
   * @param
   *
   * @param
   *
   * @return void -
   *
   */
  static void reshape(int w, int h);

  /**
   * @brief method to display all components for simulation
   *
   * @param void
   *
   * @return void - displays components
   *
   */

  static void display(void);

  /**
   * @brief method to draw Circular path taken by robot
   *
   *
   * @return returns 1 to indicate success
   *
   */

  static int drawPathCircle(void);

  /**
     * @brief method to draw Target point
     *
     * @param x - X coordinate of target point
     *
     * @param y - Y coordinate of target point
     *
     * @return returns 1 to indicate success
     *
     */

  static int drawTarget(float x, float y);

  /**
   * @brief method to display all components for simulation
   *
   * @param void
   *
   * @return void - displays components
   *
   */
  static void runSimulation(int argc, char * argv[]);
};
#endif  // INCLUDE_ROBOTSIMULATOR_HPP_
