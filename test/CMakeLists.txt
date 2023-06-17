include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(
  input_test
  input_test.cc
)

target_link_libraries(
  input_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(input_test)