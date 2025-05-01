cmake_minimum_required (VERSION 3.28.3)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/cb455a71fb23303e37ce8ee5b1cde6a2c18f66a5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()
set(gtest_xml_output_args)
list(APPEND gtest_xml_output_args
    TEST_XML_OUTPUT_DIR "${CMAKE_BINARY_DIR}/output")


if(BUILD_TESTING)
    add_executable(ctest-run-tests
        RandomNumberGeneratorTests.cpp
    )

    target_link_libraries(ctest-run-tests
        PRIVATE
            GTest::gtest_main
            utils)

    include(GoogleTest)
    gtest_discover_tests(ctest-run-tests ${gtest_xml_output_args})
endif()
