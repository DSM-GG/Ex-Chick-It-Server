cmake_minimum_required(VERSION 3.10)

project(LoginServer)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../lib/mysql-cpp ${CMAKE_CURRENT_SOURCE_DIR}/mysql-cpp)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(
        src
        ../../lib/base64)

add_executable(LoginServer
        src/packets/packet.h
        src/core/memorystream.cc
        src/core/memorystream.h
        src/core/loginserver.cc
        src/core/loginserver.h
        src/main.cc
        src/core/serverbase.h
        src/core/io_service_pool.cc
        src/core/io_service_pool.h
        src/packets/loginpacket.h
        src/packets/registerpacket.h)

target_link_libraries(LoginServer
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES}
        mysql_cpp
        mysqlclient)