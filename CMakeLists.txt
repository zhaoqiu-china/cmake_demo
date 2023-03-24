cmake_minimum_required(VERSION 3.1.0)

project(CMakeDemo VERSION 1.0.0 LANGUAGES CXX)

set(DOWNLOAD_EXTRACT_TIMESTAMP ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# GET GoogleTest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)

# Install spdlog
find_package(spdlog REQUIRED)

find_package(nlohmann_json REQUIRED)

# find_package()

add_executable(
    deleted_copy_func_demo
    src/deleted_copy_func_demo.cpp
)


add_executable(
    io_file_demo
    src/io_file_demo.cpp
)

target_compile_definitions(
  io_file_demo PUBLIC
  TEMP_DIR="${CMAKE_CURRENT_SOURCE_DIR}/temp/"
)

target_include_directories(
    io_file_demo PRIVATE
    src/include
)

add_executable(
    winapi_demo
    src/winapi_demo.cc
)

add_executable(
    std_thread_demo
    src/std_thread_demo.cc
)

add_executable(
  Array2D_demo
  src/Array2D_demo.cpp
)

add_executable(
  chrono_demo
  src/chrono_demo.cc
)

add_executable(
  template_demo
  src/template_demo.cc
)

add_executable(
  pthread_demo
  src/pthread_demo.cc
)

add_executable(
  move_demo
  src/move_demo.cc
)

add_executable(
  nlohmann_json_demo
  src/nlohmann_json_demo.cc
)

add_executable(
  string_demo
  src/string_demo.cc
)

add_executable(
  cpp11_variable_template_args
  src/cpp11_variable_template_args.cc
)

add_executable(
  cpp17_demo
  src/cpp17_demo.cc
)

add_executable(
  cpp20_demo
  src/cpp20_demo.cc
)

add_executable(
  process_pool_thal
  src/process_pool_thal.cc
)

add_executable(
  fork_pipe_demo
  src/fork_pipe_demo.cc
)

add_executable(
  fold_expression
  src/fold_expression.cc
)

#google test
enable_testing()

add_executable(
  gtest_test
  tests/gtest_test.cc
)

target_compile_definitions(
  gtest_test PUBLIC
  TEMP_DIR="${CMAKE_CURRENT_SOURCE_DIR}/temp"
)

target_link_libraries(
  gtest_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gtest_test)





