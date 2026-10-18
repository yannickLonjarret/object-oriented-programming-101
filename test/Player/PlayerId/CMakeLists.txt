add_library(PlayerIdTest OBJECT)

target_sources(PlayerIdTest
  PRIVATE
    playerIdTest.cpp)

target_link_libraries(PlayerIdTest
  PRIVATE
    GTest::gtest_main
    PlayerId
)

