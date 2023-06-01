cmake_minimum_required (VERSION 2.8)

project (los_malloc)

set(QUEUE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/queue/)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/priv)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tmp)
#set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")
#set (CMAKE_C_FLAGS "-g")
add_library(los_malloc SHARED  ${SRC_DIR}/los_memory.c ${SRC_DIR}/los_membox.c)

add_executable (example example.c)

target_link_libraries (example los_malloc pthread)