#===========================================#
# CMakeList.txt for the LinkedList library  #
#                                           #
# Dependencies:                             #
#     o None                                #
#                                           #
#===========================================#


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