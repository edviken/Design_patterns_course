cmake_minimum_required(VERSION 3.21)
project(18_mediator)

set(CMAKE_CXX_STANDARD 20)

add_executable(18_mediator main.cpp Participant.cpp Participant.h Mediator.cpp Mediator.h)
