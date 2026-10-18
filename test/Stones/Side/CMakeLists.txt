add_library(SideTest OBJECT)

target_sources(SideTest
  PRIVATE
    sideTest.cpp)

target_link_libraries(SideTest
  PRIVATE
    GTest::gtest_main
    Side
)

