
cmake_minimum_required(VERSION 3.1.0) #version 3.1.0 is recommended for qt5
project(googlemap)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp

)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)
find_package(Qt5Network REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(  qt_srcs
      GUI/mainwindow.cpp
      GUI/geocode_data_manager.cpp

   )
set(  qt_hdrs
      GUI/mainwindow.h
      GUI/geocode_data_manager.h

   )
set(
    RESOURCES
    GUI/resources.qrc
    )

qt5_add_resources(QRC ${RESOURCES})
set_source_files_properties(${QRC} PROPERTIES GENERATED ON)






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
add_library(googlemap GUI/mainwindow.cpp
                       GUI/resources.qrc
                       ${QRC})
target_link_libraries (googlemap Qt5::Widgets
                                    )

add_executable(ros_google_map src/ros_google_map.cpp
                                ${qt_srcs}
                                 ${qt_hdrs}
                                 ${QRC}
                                  GUI/resources.qrc)
target_link_libraries(ros_google_map
                  googlemap
                   ${catkin_LIBRARIES}
                   ${Qt5Widgets_LIBRARIES}
                   ${Qt5WebEngine_LIBRARIES}
                   ${Qt5WebEngineWidgets_LIBRARIES}
                    ${Qt5Network_LIBRARIES}

                  )

