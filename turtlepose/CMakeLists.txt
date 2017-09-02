cmake_minimum_required(VERSION 3.1.0) #version 3.1.0 is recommended for qt5
project(turtlepose)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(  qt_srcs
      GUI/mainwindow.cpp
   )
set(  qt_hdrs
      GUI/mainwindow.h
   )

#QT5_WRAP_CPP(qt_moc_srcs ${qt_hdrs})
#QT5_WRAP_UI(uis_h GUI/mainwindow.ui)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Qt5Widgets_INCLUDES})

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ros_qt_template
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
#tp=turtlepose
add_library(tp_window GUI/mainwindow.cpp)
target_link_libraries (tp_window Qt5::Widgets)

add_executable(turtlepose src/turtlepose.cpp)
target_link_libraries(turtlepose
                   tp_window
                   ${catkin_LIBRARIES}
                   ${Qt5Widgets_LIBRARIES}    )

