cmake_minimum_required(VERSION 3.26)
project(EngineWrapper)

set(CMAKE_CXX_STANDARD 20)

add_executable(EngineWrapper main.cpp
        Subject.cpp
        Subject.h
        Wrapper.cpp
        Wrapper.h
        Engine.cpp
        Engine.h
        Engine.h)
