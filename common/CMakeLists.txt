project(atmine-common)

include(AtmineConfig)

set(PROJECT_LIBRARY_NAME common)
aux_source_directory(${PROJECT_SOURCE_DIR} LIBRARY_SOURCES)

add_library(${PROJECT_LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})
target_link_libraries(${PROJECT_LIBRARY_NAME} Qt5::Core)
target_link_libraries(${PROJECT_LIBRARY_NAME} Qt5::Sql)

