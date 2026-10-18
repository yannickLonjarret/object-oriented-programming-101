add_library(StoneTest OBJECT)

target_sources(StoneTest
  PRIVATE
    stoneTest.cpp)

target_link_libraries(StoneTest
  PRIVATE
    GTest::gtest_main
    Stone
    Combination
    CompletionOrder
    Card
    Side
    PlayerId
)



add_subdirectory(Combination)
add_subdirectory(CompletionOrder)
add_subdirectory(Side)