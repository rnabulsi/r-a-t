# Setup cmake common stuff.
if(NOT DEFINED CMAKE_MACOSX_RPATH)
    set(CMAKE_MACOSX_RPATH 0)
endif()

# Setup Qt5 support.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Find Qt5 component libraries
find_package(Qt5Core)
find_package(Qt5Sql)
find_package(Qt5Test)

# Set common compiler flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-braces")

# Node class configuration. Look at class documentation for details.
#
# Possible values: BINARY_SEARCH, HASH_TABLE, EXTENSIVE_TREE
#
# Values are mutualy exclusive and prioritized in the order given above.
# The node class has to be configured or the compilation will fail.
add_definitions(-DEXTENSIVE_TREE)

# ResultNode class configuration. Look at class documentation for details.
#
# Possible value: REDUCE_THRU_DIACRITICS
#
# Value can be not defined too, causing default implementation of ResultNode
# to be compiled.
add_definitions(-DREDUCE_THRU_DIACRITICS)

