add_library(Stone)

target_sources(Stone
    PRIVATE
        stone.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            stone.h
)


add_subdirectory(Combination)