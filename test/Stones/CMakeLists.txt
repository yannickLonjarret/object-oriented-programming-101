add_library(CombinationTest)

target_sources(CombinationTest
    PRIVATE
        combinationTest.cpp
)

target_link_libraries(Combination)