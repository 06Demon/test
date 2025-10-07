cmake_minimum_required(VERSION 3.14)
project(lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Для MSVC устанавливаем динамическую runtime библиотеку
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

include_directories(src)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

# Устанавливаем опцию для shared CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(main
    src/main.cpp
    src/Four.cpp
)

add_executable(runTests
    tests/FourTests.cpp
    src/Four.cpp
)

target_link_libraries(runTests
    gtest_main
)

enable_testing()
add_test(NAME FourTests COMMAND runTests)