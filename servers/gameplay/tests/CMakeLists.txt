cmake_minimum_required(VERSION 3.9)

project(GamePlayServerTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)

file(GLOB_RECURSE TEST_SOURCE_LIST "./*.cc")

add_executable(GamePlayServerTest ${TEST_SOURCE_LIST})

target_link_libraries(GamePlayServerTest
        pthread
        gtest
        gtest_main)