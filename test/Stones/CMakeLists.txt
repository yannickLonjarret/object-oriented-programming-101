add_library(CombinationTest OBJECT)

target_sources(CombinationTest
  PRIVATE
    combinationTest.cpp)

target_link_libraries(CombinationTest
  PUBLIC
    GTest::gtest_main
    Combination
)

