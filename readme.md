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

## Description
The module developed for this project utilizes two revolute joints and flxed linked lengths.

#### Components
Project is segmented into 3 key components. 
* Kinematics - This is mainly reponsible for the inverse and forward kinematics calculations of the robot.
* Path Planning - A predefined path(line,parabola etc) is chosen as the path that links start to end point. Given some predetermined path 
[Gauss-Seidel algorithm](https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method) is used to converge to the suitable angles needed to rotate the robot
* Simulator  - This component is responsible for simulatiing the robot in some created environment.
For full overview of project refer to the UML diagrams.

#### Assumptions
* Zero configuration (robot at rest initially)
* Robot arm is attached to some fixed location
* 90 < J1(joint attached to fixed frame angle) < -90
* -180 < J2(joint attached to attached to link1) < 180


## Dependencies
To use the program, the following need to be installed
* OpenGL
```
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

## Standard install via command-line
```
git clone https://github.com/mesneym/ENPM808X_MIDTERM.git
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
## Output:
Case1: If the target point is within the workspace:
Run the program in build directory
```
./app/shell-app
Please Enter display Type
1-> rotate links continuously
2-> rotate in circular path to target
3-> rotate in linear path to target 
(Choose 1 or 2 or 3)
Target Coordinates with range X(-28,28), Y(-28,28)
Enter X Coordinate -28
Enter Y Coordinate 28
```
![](https://github.com/mesneym/ENPM808X_MIDTERM/blob/master/Output/outpu1.png)

![](https://github.com/mesneym/ENPM808X_MIDTERM/blob/master/Output/output2.png)

![](https://github.com/mesneym/ENPM808X_MIDTERM/blob/master/Output/output3.png)

Case2: If the target point is not within the workspace:
Run the program in build directory
```
./app/shell-app
Please Enter display Type
1-> rotate links continuously
2-> rotate in circular path to target
3-> rotate in linear path to target 
(Choose 1 or 2 or 3)
Target Coordinates with range X(-28,28), Y(-28,28)
Enter X Coordinate -50
Enter Y Coordinate 29
```
![](https://github.com/mesneym/ENPM808X_MIDTERM/blob/master/Output/Output4.png)

### Google Spreadsheet AIP
Click on [link](https://docs.google.com/spreadsheets/d/10R_Otal_Gfjr0w5yJNEBC7csmbCSRA3b/edit#gid=1981406559) to view Spreadsheet

### Sprint Planning Notes
Click on [link](https://docs.google.com/document/d/1yKubIXh2VU4r4MyImYy5NaWd8WPoInfSN3GemB6s83w/edit?usp=sharing) to view Sprint Planning Google Doc file

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

## Doxygen Installation through command line
```
sudo apt install doxygen
```

## To generate Doxygen Documentation
```
cd <path to repository>
mkdir Doxygen
cd Doxygen
doxygen -g <config_file_name>
```
Change the following things in the configuration file.
```
PROJECT_NAME = 'ENPM808X_MIDTERM'
INPUT = ../app ../include ../test
```
Afer making changes, run the following command on the terminal
```
doxygen <config_file_name>
```
## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/mesneym/ENPM808X_MIDTERM
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of ENPM808X_MIDTERM

```
cd ~/workspace
mkdir -p ENPM808X_MIDTERM-eclipse
cd ENPM808X_MIDTERM-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../ENPM808X_MIDTERM

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "ENPM808X_MIDTERM-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold ENPM808X_MIDTERM-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the ENPM808X_MIDTERM-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)
```

## Personal Information:

We (Eashwar Sathyamurthy and Akwasi A Obeng) both are pursuing Masters in Engineering specializing in Robotics in University of Maryland. We both are first year graduate students. We mainly chose to do this project as it resonated with our interests.

