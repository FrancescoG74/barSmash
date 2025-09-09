
cmake_minimum_required(VERSION 3.16)
project(barSmash VERSION 1.0 LANGUAGES CXX)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(barSmash sources/main.cpp sources/MyWindow.cpp)
target_include_directories(barSmash PRIVATE headers)

# Link Qt6 libraries
qt6_wrap_ui(UI_HEADERS mainwindow.ui)
target_link_libraries(barSmash PRIVATE Qt6::Widgets)
