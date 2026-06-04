cmake_minimum_required(VERSION 3.20)

project(display_model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

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

file(GLOB EXERCISE_SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(source_file ${EXERCISE_SOURCES})
    get_filename_component(target_name ${source_file} NAME_WE)

    qt_add_executable(${target_name}
        ${source_file}
        ${PPP_QT_SOURCES}
    )

    target_include_directories(${target_name} PRIVATE
        "${PPP_QT_ROOT}"
    )

    target_link_libraries(${target_name} PRIVATE
        Qt6::Widgets
    )
endforeach()
