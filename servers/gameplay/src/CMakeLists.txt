cmake_minimum_required(VERSION 3.10)

project(GamePlayServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

include_directories(
        ../src)

file(GLOB_RECURSE HEADER_LIST "./*.cc")
file(GLOB_RECURSE SOURCE_LIST "./*.h")

add_executable(GamePlayServer
        ${HEADER_LIST}
        ${SOURCE_LIST})

target_link_libraries(GamePlayServer
        zmq
        protobuf
        ${CMAKE_THREAD_LIBS_INIT})