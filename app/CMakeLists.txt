add_executable(shell-app
               main.cpp
               Pathplanning.cpp
               Robot.cpp
               Robotsimulator.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(shell-app ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/eigen3
)
