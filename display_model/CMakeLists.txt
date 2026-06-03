cmake_minimum_required(VERSION 3.20)

project(display_model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PPP_QT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../ProgrammingPrinciplesAndPracticeUsingQt")

set(PPP_QT_SOURCES
    "${PPP_QT_ROOT}/PPP/Window.h"
    "${PPP_QT_ROOT}/PPP/Graph.h"
    "${PPP_QT_ROOT}/PPP/GUI.h"
    "${PPP_QT_ROOT}/PPP/Simple_window.h"
    "${PPP_QT_ROOT}/PPP/Point.h"
    "${PPP_QT_ROOT}/PPP/std_lib_facilities.h"
    "${PPP_QT_ROOT}/PPP/Image_private.h"
    "${PPP_QT_ROOT}/PPP/GUI_private.h"

    "${PPP_QT_ROOT}/Window.cpp"
    "${PPP_QT_ROOT}/Graph.cpp"
    "${PPP_QT_ROOT}/GUI.cpp"
    "${PPP_QT_ROOT}/Simple_window.cpp"
    "${PPP_QT_ROOT}/Colormap.cpp"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(first_example
        MANUAL_FINALIZATION
        first_example.cpp
        ${PPP_QT_SOURCES}
    )
else()
    add_executable(first_example
        first_example.cpp
        ${PPP_QT_SOURCES}
    )
endif()

target_include_directories(first_example PRIVATE
    "${PPP_QT_ROOT}"
)

target_link_libraries(first_example PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(first_example)
endif()
