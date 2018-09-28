cmake_minimum_required(VERSION 3.10)

project(LoginServer)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../lib/mysql-cpp ${CMAKE_CURRENT_SOURCE_DIR}/mysql-cpp)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(
        src
        ../../lib/base64
        ../../lib/common)

file(GLOB_RECURSE SOURCES . "*.cc")
file(GLOB_RECURSE HEADERS . "*.h")

add_executable(LoginServer
        ${SOURCES}
        ${HEADERS})

target_link_libraries(LoginServer
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES}
        mysql_cpp
        mysqlclient)