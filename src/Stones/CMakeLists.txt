add_library(Stone)

target_sources(Stone
    PRIVATE
        stone.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            stone.h
)

target_link_libraries(Stone
    PRIVATE
        Combination)

add_subdirectory(Combination)