cmake_minimum_required(VERSION 3.5)

project(DynMenu-prototype VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core)

add_subdirectory(mcore)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(DynMenu-prototype
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:

target_link_libraries(DynMenu-prototype PRIVATE Qt5::Widgets Qt5::Core mcore)
