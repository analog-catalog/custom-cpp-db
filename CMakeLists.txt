cmake_minimum_required(VERSION 3.16)
project(MiniRedis)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MiniRedis
    src/main.cpp
    src/Parser.cpp
    src/KeyValueStore.cpp
    src/Commands.cpp
    src/Storage.cpp
)

target_include_directories(MiniRedis PRIVATE header)
target_link_libraries(MiniRedis PRIVATE stdc++exp)

enable_testing()

find_package(GTest REQUIRED)

add_executable(MiniRedisTests
    tests/parser_driver.cpp
    tests/KeyValueStore_tests.cpp
    tests/commands_driver.cpp
    tests/storage_tests.cpp
    src/Parser.cpp
    src/KeyValueStore.cpp
    src/Commands.cpp
    src/Storage.cpp
)

target_include_directories(MiniRedisTests PRIVATE header)
target_link_libraries(MiniRedisTests PRIVATE GTest::gtest_main stdc++exp)

include(GoogleTest)
gtest_discover_tests(MiniRedisTests)
