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
 * @file Robotsimulator.cpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Robotsimulator class
 *
 * @version 1
 *
 * @date 2019-10-12
 *
 * This program implements the methods of the
 * Robotsimulator class from Robotsimulator.hpp header file
 *
 */

#include "Robotsimulator.hpp"

Eigen::Vector2f joint1(0, 0);
Eigen::Vector2f joint2(20, 0);
Eigen::Vector2f endEffector(40, 0);
Eigen::Vector2f endEffectorCopy = endEffector;

Robot Robotsimulator::robot(joint1, joint2, endEffector);

Eigen::Vector2d path(1, -1);
Eigen::Vector2d angles(1, 1);
Pathplanning Robotsimulator::planPath;

float targetX, targetY;
int displayType;
Robotsimulator::Robotsimulator(PathplanningMock &path) : pathMock_(path){}
Robotsimulator::~Robotsimulator(){}
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

int Robotsimulator::drawOuterCircle(int centerx, int centery, int r) {
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i <= 30; i++) {
    /// black foreground
    glColor3f(0, 0.3, 0);
    float x = r * cos(PI * i * 2.0 / 30);
    float y = -r * sin(PI * i * 2.0 / 30);

    glVertex2f(x + centerx, y + centery);
  }
  glEnd();
  return 1;
}

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

int Robotsimulator::drawInnerCircle(int centerx, int centery, int r) {
  float prevx = centerx;
  float prevy = centery + r;

  for (int i = 0; i <= 30; i++) {
    glBegin(GL_TRIANGLES);
    /// black foreground
    glColor3f(0, 0, 0);
    float v1 = r * cos(PI * i * 2.0 / 30) + centerx;
    float v2 = -r * sin(PI * i * 2.0 / 30) + centery;
    glVertex2f(centerx, centery);
    glVertex2f(prevx, prevy);
    glVertex2f(v1, v2);
    glEnd();

    prevx = v1;
    prevy = v2;
  }
  return 1;
}

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

int Robotsimulator::drawJoint(int centerx, int centery) {
  drawOuterCircle(centerx, centery, 5);
  drawInnerCircle(centerx, centery, 3);
  return 1;
}

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

int Robotsimulator::drawLinkBtnJoints(float cx1, float cy1, float cx2,
                                      float cy2) {
  glLineWidth(20);
  glBegin(GL_LINES);
  glVertex2f(cx1, cy1);
  glVertex2f(cx2, cy2);
  glEnd();
  glLineWidth(1);
  return 1;
}

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

int Robotsimulator::drawEndEffector(float centerx, float centery) {
  drawInnerCircle(centerx, centery, 3);
  return 1;
}

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

int Robotsimulator::drawTarget(float x, float y) {
  glPointSize(20.0f);
  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  glVertex2f(x, y);
  glEnd();

  return 1;
}

/**
 * @brief method to draw Circular path taken by robot
 *
 * @return returns 1 to indicate success
 *
 */

int Robotsimulator::drawPathCircle(void) {
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i <= 50; i++) {
    /// black foreground
    glColor3f(0, 0.3, 0);
    float x = 40 * cos(PI * i * 2.0 / 50);
    float y = -40 * sin(PI * i * 2.0 / 50);

    glVertex2f(x + joint1[0], y + joint1[1]);
  }
  glEnd();
  return 1;
}

/**
 * @brief method to display all components for simulation
 *
 * @param void
 *
 * @return void - displays components
 *
 */

void Robotsimulator::display(void) {
  /// Method to set white background
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  if (displayType == 1) {
    displayArm();
    planPath.AnglesForContinuousPath(angles);
    glutSwapBuffers();
  } else {
    if (robot.isInWorkspace(targetX, targetY)) {
      // printing appropriate message on window
      std::string str = "Not working properly. Opengl";
	  str += " doesn't give the R coordinates";

      glColor3f(1, 0, 0);
      glRasterPos2f(-50, 10);  // position to display string
      int len = str.size();
      for (int i = 0; i < len; i++)
	  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);

      str="To Workaround that breaks         our code";

      glColor3f(1, 0, 0);
      glRasterPos2f(-50, 0);  // position to display string
      len = str.size();
      for (int i = 0; i < len; i++)
	  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);


      str="Future implementations will rectify that";

      glColor3f(1, 0, 0);
      glRasterPos2f(-50, -10);  // position to display string
      len = str.size();
      for (int i = 0; i < len; i++)
	  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);

      drawTarget(targetX, targetY);
	  drawPathCircle();
      displayArm();

      if (robot.targetReached(targetX, targetY))
        std::cout << "targer Reached" << std::endl;

      switch (displayType) {
        case 2:
          planPath.AnglesForCircularPath(angles);
          break;

        case 3:
          planPath.AnglesForLinearPath(angles, path);
          break;
      }
      glutSwapBuffers();
    } else {
      // printing appropriate message on window
      std::string str = "Target Coordinates not in robot workspace";
      glColor3f(1, 0, 0);
      glRasterPos2f(-30, 0);  // position to display string
      int len = str.size();
      for (int i = 0; i < len; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);

      /// display string
      glFlush();
    }
  }
}

/**
 * @brief method to display robot arm
 *
 * @param void  
 *
 * @return void 
 *
 */
void Robotsimulator::displayArm(void) {
  drawJoint(joint1[0], joint1[1]);

  glPushMatrix();
  glTranslatef(joint1[0], joint1[1], 0);
  glRotatef(angles[0], 0.0f, 0.0f, 1.0f);
  glTranslatef(-joint1[0], -joint1[1], 0);
  drawJoint(joint2[0], joint2[1]);
  drawLinkBtnJoints(joint1[0], joint1[1], joint2[0], joint2[1]);

  glPushMatrix();
  glTranslatef(joint2[0], joint2[1], 0);
  glRotatef(angles[1], 0, 0, 1.0f);
  glTranslatef(-joint2[0], -joint2[1], 0);
  drawEndEffector(endEffector[0], endEffector[1]);
  drawLinkBtnJoints(joint2[0], joint2[1], endEffector[0], endEffector[1]);

  /// update robots endEffector coordinates
  float mat[16];
  glGetFloatv(GL_MODELVIEW_MATRIX, mat);
  glPopMatrix();
  glPopMatrix();
}

/**
 * @brief method to reshape the arm
 *
 * @param width of area for display in window
 *
 * @param height of area for display in window
 *
 * @return void -
 *
 */

void Robotsimulator::reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  /// Axis of window
  /// x axis from -50 to 50
  /// y axis from -50 to 50
  gluOrtho2D(-50, 50, -50, 50);
  glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief method times the display
 *
 * @param Referesh rate for display
 *
 * @return void 
 *
 */

void timer(int) {
  glutPostRedisplay();
  /// displays 60frames in 1000 milliseconds
  glutTimerFunc(1000 / 60, timer, 0);
}

/**
 * @brief method to start simulation
 *
 * @param command line arguments(Not used but needed for opengl library) 
 *
 * @return void - displays arm
 *
 */

void Robotsimulator::runSimulation(int argc, char * argv[]) {
  std::cout << "Please Enter display Type" << std::endl;
  std::cout << "1-> rotate links continuously" << std::endl;
  std::cout << "2-> rotate in circular path to target" << std::endl;
  std::cout << "3-> rotate in linear path to target " << std::endl;

  /// Robot functionalities to test
  std::cin >> displayType;
  if (displayType == 2 || displayType == 3) {
    std::cout << "Target Coordinates with range X(-28,28), Y(-28,28)"
        << std::endl;
    std::cout << "Enter X Coordinate ";
    std::cin >> targetX;
    std::cout << "Enter Y Coordinate ";
    std::cin >> targetY;
  }

  /// initialize window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("robot simulator");

  /// callback functions
  /// calls the display function
  glutDisplayFunc(display);
  /// calls the reshape function
  glutReshapeFunc(reshape);
  /// calls timer function
  glutTimerFunc(0, timer, 0);
  /// Events are looped continuously
  glutMainLoop();
}
