add_library(Card)

target_sources(Card
    PRIVATE
        card.cpp
    PUBLIC
    FILE_SET HEADERS
    FILES
        card.h
)