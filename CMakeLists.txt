cmake_minimum_required(VERSION 3.13)
project(simple_neural_network_cpp)

set(CMAKE_CXX_STANDARD 17)

# macro from StackOverflow
# https://stackoverflow.com/questions/7787823/cmake-how-to-get-the-name-of-all-subdirectories-of-a-directory
macro(SUBDIRLIST RESULT CURDIR)
    file(GLOB CHILDREN RELATIVE ${CURDIR} ${CURDIR}/*)
    set(DIRLIST "")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY ${CURDIR}/${CHILD})
            list(APPEND DIRLIST ${CHILD})
        endif()
    endforeach()
    set(${RESULT} ${DIRLIST})
endmacro()

subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach(SUBDIR ${SUBDIRS})
    file(GLOB SOURCES "${SUBDIR}/*.h" "${SUBDIR}/*.cpp")
    list(APPEND BUILD_FILES "${SOURCES}")
endforeach()

foreach(FILES ${BUILD_FILES})
    message("File: ${FILES}")
endforeach()

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${BUILD_FILES})