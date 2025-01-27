cmake_minimum_required(VERSION 3.28)
project(Wooloo)
set(CMAKE_CXX_STANDARD 23)
enable_testing()

add_subdirectory(external/googletest)

include_directories(
    include
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

file(GLOB LIBRARY_SOURCES
    "source/library/*.cpp"
)

file(GLOB TEST_SOURCES
    "source/test/*.cpp"
)

add_library(Library ${LIBRARY_SOURCES})

add_executable(AllTests ${TEST_SOURCES})
target_link_libraries(AllTests PRIVATE Library gtest gmock gtest_main)
add_test(NAME RunAllTests COMMAND AllTests)
