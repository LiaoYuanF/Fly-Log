cmake_minimum_required(VERSION 3.2)
project(Utils)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/logUtils)

add_executable(Utils ${PROJECT_SOURCE_DIR}/Test/MultiThreadTest.cpp
        logUtils/logging.cpp)

target_link_libraries(Utils pthread)