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
        Combination
        CompletionOrder
        Side
        PlayerId)

add_subdirectory(Combination)
add_subdirectory(Side)
add_subdirectory(CompletionOrder)