cmake_minimum_required(VERSION 3.13)
project(simple_nn)

set(CMAKE_CXX_STANDARD 17)

add_executable(simple_nn Matrix.h Matrix.cpp Global.h Layer.h FunctionType.h FunctionType.cpp Layer.cpp Network.h Network.cpp main.cpp)