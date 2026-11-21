add_library(PlayerTest OBJECT)

target_sources(PlayerTest
  PRIVATE
    playerTest.cpp)

target_link_libraries(PlayerTest
  PRIVATE
    GTest::gtest_main
    Player
    PlayerId
    Card
)

add_subdirectory(PlayerId)