#===========================================#
# CMakeList.txt for the LinkedList library  #
#                                           #
# Dependencies:                             #
#     o None                                #
#                                           #
#===========================================#


# project setup
cmake_minimum_required(VERSION 3.12)
project(LinkedList C)

# library setup
set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/list.c
)

add_library(LinkedList
    STATIC
    ${SOURCES}
)

target_include_directories(LinkedList
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)