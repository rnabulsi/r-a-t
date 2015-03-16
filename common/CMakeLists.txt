project(atmine-common)

include(AtmineConfig)

# Setup library
set(PROJECT_LIBRARY_NAME common)
aux_source_directory(${PROJECT_SOURCE_DIR} LIBRARY_SOURCES)

add_library(${PROJECT_LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})
target_link_libraries(${PROJECT_LIBRARY_NAME} Qt5::Core)
target_link_libraries(${PROJECT_LIBRARY_NAME} Qt5::Sql)

# Setup tests
set(PROJECT_TEST_NAME ${PROJECT_NAME}-test)
enable_testing()
aux_source_directory(${PROJECT_SOURCE_DIR}/tests TEST_SOURCES)
add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCES})
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIBRARY_NAME})
target_link_libraries(${PROJECT_TEST_NAME} Qt5::Core)
target_link_libraries(${PROJECT_TEST_NAME} Qt5::Test)
add_test(NAME "Atmine-common-tests" COMMAND ${PROJECT_TEST_NAME})
