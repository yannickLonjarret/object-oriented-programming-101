add_library(Combination)

target_sources(Combination
    PRIVATE
        combination.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            combination.h
)

target_link_libraries(Card)