add_library(UtilsMathTest OBJECT)

target_sources(UtilsMathTest
  PRIVATE
    utils_math_test.cpp)

target_link_libraries(UtilsMathTest
  PRIVATE
    GTest::gtest_main
  PUBLIC
    Utilities
)
