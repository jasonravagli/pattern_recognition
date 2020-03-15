cmake_minimum_required(VERSION 3.15)
project(pattern_recognition)

set(CMAKE_C_COMPILER "$ENV{CMAKE_C_COMPILER}")
set(CMAKE_CXX_COMPILER "$ENV{CMAKE_CXX_COMPILER}")
set(OPENMP_LIBRARIES "$ENV{OPENMP_LIBRARIES}")
set(OPENMP_INCLUDES "$ENV{OPENMP_INCLUDES}")

# Find OpenMP
set(OpenMP_C "${CMAKE_C_COMPILER}")
set(OpenMP_C_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
set(OpenMP_C_LIB_NAMES "libomp" "libgomp" "libiomp5")
set(OpenMP_libomp_LIBRARY ${OpenMP_C_LIB_NAMES})
set(OpenMP_libgomp_LIBRARY ${OpenMP_C_LIB_NAMES})
set(OpenMP_libiomp5_LIBRARY ${OpenMP_C_LIB_NAMES})

set(OpenMP_CXX "${CMAKE_CXX_COMPILER}")
set(OpenMP_CXX_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
set(OpenMP_CXX_LIB_NAMES "libomp" "libgomp" "libiomp5")
set(OpenMP_libomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
set(OpenMP_libgomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
set(OpenMP_libiomp5_LIBRARY ${OpenMP_CXX_LIB_NAMES})

find_package(OpenMP REQUIRED)

include_directories("${OPENMP_INCLUDES}")
link_directories("${OPENMP_LIBRARIES}")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

include_directories(eigen-3.3.7)

add_executable(pattern_recognition main.cpp MarkovChain.h MarkovChain.cpp SequenceGenerator.cpp SequenceGenerator.h PatternRecognizer.cpp PatternRecognizer.h)