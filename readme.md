# Robot Arm Manipulator Path Planner
[![Build Status](https://travis-ci.org//Eashwar-S/robot_arm_manipulator.svg?branch=master)](https://travis-ci.org//Eashwar-S/robot_arm_manipulator)
[![Coverage Status](https://coveralls.io/repos/github//Eashwar-S/robot_arm_manipulator/badge.svg?branch=master)](https://coveralls.io/github//Eashwar-S/robot_arm_manipulator?branch=master)

## Overview
In recent times, significant developments have been made to robotic arm manipulators. But, most of them have
basic functionalities like moving objects from one point to another within their reachable workspace. In a
structured environment where a robot is tasked with some mundane task, it is of essence that the robot be able
to navigate its environment precisely and efficiently. 


Developed is a simple path planner(IK solver) for a robot arm manipulator. For brevity, this is demonstrated with a 2D
robot  with only revolute joints.That is, given some start and end point,the robot follows a predetermined path to reach the end point.

![](https://github.com/mesneym/ENPM808X_MIDTERM/blob/master/data/robot.png)


#### Dependencies Added
## Add Target Link Libraries
In order to add googlemock framework,include this line in CMakelists.txt file in test folder.
```
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include)
```
## Add executables

```
add_executable(
    MockRobotsimulatorTest.cpp
)
```

## Standard install via command-line
```
git clone https://github.com/mesneym/ENPM808X_MIDTERM.git
git checkout GMock_Extra_Credit
cd <path to repository>
```
## How to build the project
```
mkdir build
cd build
cmake ..
```

## How to compile the project
```
cd <path to build>
make
```

## How to run the program
```
cd <path to build>
Run program: ./app/shell-app
```

## How to test the program
```
cd <path to build>
Run program: ./test/cpp-test
```
## Google Mock framework
Used google mock framework to mock Pathplanning class.
Created virtual methods and interface of Pathplanning class and used it to test methods in Pathplanning class.


## License
```
MIT License

Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

