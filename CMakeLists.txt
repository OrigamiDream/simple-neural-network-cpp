cmake_minimum_required(VERSION 3.13)
project(simple_nn)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_CURRENT_SOURCE_DIR}/nn/CMakeLists.txt)

foreach(files ${HEADER_FILES})
    list(APPEND BUILD_FILES "nn/${files}")
endforeach()

foreach(files ${SOURCE_FILES})
    list(APPEND BUILD_FILES "nn/${files}")
endforeach()

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${BUILD_FILES})