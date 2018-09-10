cmake_minimum_required(VERSION 3.10)

project(LOGIN_SERVER)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/mysql-cpp)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(
        src
        lib/base64)

add_executable(LOGIN_SERVER
        src/packets/packet.h
        src/core/memorystream.cc
        src/core/memorystream.h
        src/core/loginserver.cc
        src/core/loginserver.h
        src/main.cc
        src/core/serverbase.h
        src/core/io_service_pool.cpp
        src/core/io_service_pool.h
        src/packets/loginpacket.h
        src/packets/registerpacket.h)

target_link_libraries(LOGIN_SERVER
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES}
        mysql_cpp
        mysqlclient)