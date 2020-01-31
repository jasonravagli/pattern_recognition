cmake_minimum_required(VERSION 3.15)
project(pattern_recognition)

set(CMAKE_CXX_STANDARD 14)

include_directories(../eigen-3.3.7)

add_executable(pattern_recognition main.cpp MarkovChain.h MarkovChain.cpp SequenceGenerator.cpp SequenceGenerator.h)