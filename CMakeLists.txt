cmake_minimum_required(VERSION 2.8.11)
project(atmine)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

file(STRINGS ${PROJECT_SOURCE_DIR}/VERSION VERSION)

enable_testing()

add_subdirectory(common)
add_subdirectory(sql)
add_subdirectory(model)
add_subdirectory(engine)

