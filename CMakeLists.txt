cmake_minimum_required(VERSION 4.3)
project(snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake main.cpp
        Game.cpp
        Game.h
        MoveDirection.h
)
