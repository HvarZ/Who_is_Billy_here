cmake_minimum_required(VERSION 3.17)
project(Who_is_Billy_here)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        sources/main_button.cpp
        sources/main_menu.cpp
        sources/message.cpp
        sources/titles.cpp
        sources/textbox.cpp
        sources/back_button.cpp
        sources/timer.cpp
        sources/single_game.cpp
        sources/gem.cpp
        )

set(HEADERS
        include/main_button.h
        include/main_menu.h
        include/message.h
        include/titles.h
        include/textbox.h
        include/back_button.h
        include/timer.h
        include/single_game.h
        include/gem.h
        )

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(Who_is_Billy_here ${SOURCES})

target_include_directories(Who_is_Billy_here
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/gems)

target_link_libraries(Who_is_Billy_here sfml-graphics sfml-audio)