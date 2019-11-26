
set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    PathplanningTest.cpp
    RobotTest.cpp
    RobotsimulatorTest.cpp
    MockRobotsimulatorTest.cpp
    ../app/Pathplanning.cpp
    ../app/Robot.cpp
    ../app/Robotsimulator.cpp
)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include
                                           /usr/include/eigen3
                                            ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS}
)
target_link_libraries(cpp-test PUBLIC gtest gmock 
                                      ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}
)
