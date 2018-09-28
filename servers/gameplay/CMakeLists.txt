cmake_minimum_required(VERSION 3.10)

project(LogicServer)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(
        src
        ../../lib/base64)

add_executable(GamePlayServer
        src/packets/packet.h
        src/core/logicserver.cc
        src/core/logicserver.h
        src/main.cc
        src/packets/loginpacket.h
        src/packets/registerpacket.h src/core/util.cc src/core/util.h)

target_link_libraries(GamePlayServer
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES})