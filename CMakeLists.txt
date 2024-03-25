cmake_minimum_required(VERSION 3.16)
project(card-shuffle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CMakeLocal.txt OPTIONAL)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(card-shuffle main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
               cards.qrc card.cpp card.h)
target_link_libraries(card-shuffle PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
