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

FIND_PATH(MYSQLPP_INCLUDE_PATH mysql++.h /usr/include/mysql++/)

FIND_PATH(MYSQL_INCLUDE_PATH mysql.h /usr/include/mysql/)
IF(MYSQL_INCLUDE_PATH AND MYSQLPP_INCLUDE_PATH)
    SET(MYSQLPP_INCLUDE_DIR
            ${MYSQLPP_INCLUDE_PATH}
            ${MYSQL_INCLUDE_PATH}
            )
ENDIF(MYSQL_INCLUDE_PATH AND MYSQLPP_INCLUDE_PATH)

FIND_LIBRARY(MYSQLPP_LIBRARIES mysqlpp)

IF (MYSQLPP_INCLUDE_DIR AND MYSQLPP_LIBRARIES)
    SET(MYSQLPP_FOUND TRUE)
ELSE (MYSQLPP_INCLUDE_DIR AND MYSQLPP_LIBRARIES)
    SET(MYSQLPP_FOUND FALSE)
ENDIF (MYSQLPP_INCLUDE_DIR AND MYSQLPP_LIBRARIES)

IF(MYSQLPP_FIND_REQUIRED)
    IF(MYSQLPP_FOUND)
    ELSE(MYSQLPP_FOUND)
        MESSAGE(FATAL_ERROR "Could not find mysqlpp")
    ENDIF(MYSQLPP_FOUND)
ENDIF(MYSQLPP_FIND_REQUIRED)

target_link_libraries(LoginServer
        ${CMAKE_THREAD_LIBS_INIT}
        mysql++-dev
        )
#        mysql_cpp
#        mysqlclient)