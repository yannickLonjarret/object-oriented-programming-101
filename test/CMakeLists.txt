
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/063de7e9578f82b369302001269680b4b1553359.zip # v1.18
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(GameTest)

target_sources(GameTest
  PRIVATE
    hello_test.cc)

target_link_libraries(
  GameTest
  GTest::gtest_main
  # Add future test here
  CombinationTest
  PlayerIdTest
  SideTest
  StoneTest
  CompletionOrderTest
  CombinationTest
  UtilsMathTest
  PlayerIDServiceTest
  PlayerTest
)

include(GoogleTest)
gtest_discover_tests(
  GameTest
  CombinationTest
  PlayerIdTest
  PlayerTest
  SideTest
  StoneTest
  CompletionOrderTest
  CombinationTest

  UtilsMathTest
  PlayerIDServiceTest
)

# Subdirectories:
add_subdirectory(Stones)
add_subdirectory(Player)
add_subdirectory(utils)
