add_library(CompletionOrderTest OBJECT)

target_sources(CompletionOrderTest
  PRIVATE
    completionOrderTest.cpp)

target_link_libraries(CompletionOrderTest
  PRIVATE
    GTest::gtest_main
    CompletionOrder
    PlayerId
)

