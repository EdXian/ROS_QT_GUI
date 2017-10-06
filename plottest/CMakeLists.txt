#https://gist.github.com/gicmo/e394737efa88fcf0dae6 cmake skeleton

cmake_minimum_required(VERSION 3.1.0) #version 3.1.0 is recommended for qt5
project(plottest)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp

)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(  qt_srcs
      GUI/mainwindow.cpp
        GUI/qcustomplot.cpp
        include/rigidbody.cpp
   )
set(  qt_hdrs
      GUI/mainwindow.h
         GUI/qcustomplot.h
         include/rigidbody.h
   )
find_package(Qt5PrintSupport)
#QT5_WRAP_CPP(qt_moc_srcs ${qt_hdrs})


include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Qt5Widgets_INCLUDES})

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES ros_qt_template
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
#tp=turtlepose
add_library(plot GUI/mainwindow.cpp)
target_link_libraries (plot Qt5::Widgets)

add_executable(testplot src/testplot.cpp
                                ${qt_srcs}
                                 ${qt_hdrs})
target_link_libraries(testplot
                  plot
                   ${catkin_LIBRARIES}
                   ${Qt5Widgets_LIBRARIES}
                    Qt5::PrintSupport)

