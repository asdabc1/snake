cmake_minimum_required(VERSION 4.3)
project(snake)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest CONFIG REQUIRED)

add_executable(snake main.cpp
        Game.cpp
        Game.h
        MoveDirection.h
)

add_executable(snake_tests tests.cpp
        Game.cpp
        Game.h
        MoveDirection.h)

target_link_libraries(snake_tests PRIVATE GTest::gtest_main)
