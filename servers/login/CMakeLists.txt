cmake_minimum_required(VERSION 3.9.2)

project(LoginServer)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../lib/mysql-cpp ${CMAKE_CURRENT_SOURCE_DIR}/mysql-cpp)

find_package(Threads REQUIRED)

include_directories(
        src
        ../../lib/base64
        ../../lib/common
#        ../../lib/mysql-cpp/
        ../../lib/boost/asio/include)

file(GLOB_RECURSE SOURCES . "*.cc")
file(GLOB_RECURSE HEADERS . "*.h")

add_executable(LoginServer
        ${SOURCES}
        ${HEADERS})

target_link_libraries(LoginServer
        ${CMAKE_THREAD_LIBS_INIT}
        )
#        mysql_cpp
#        mysqlclient)