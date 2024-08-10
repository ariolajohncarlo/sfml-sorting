cmake_minimum_required (VERSION 3.28.3)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/cb455a71fb23303e37ce8ee5b1cde6a2c18f66a5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(run-tests RandomNumberGeneratorTests.cpp)

target_link_libraries(run-tests GTest::gtest_main utils)

include(GoogleTest)
gtest_discover_tests(run-tests)
