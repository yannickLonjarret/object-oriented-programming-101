add_library(PlayerIDServiceTest OBJECT)

target_sources(PlayerIDServiceTest
  PRIVATE
    playerIDServiceTest.cpp)

target_link_libraries(PlayerIDServiceTest
  PRIVATE
    GTest::gtest_main
    PlayerId
    Utilities
)