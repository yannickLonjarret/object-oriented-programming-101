add_library(Player)

target_sources(Player
    PRIVATE
        player.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            player.h
)

target_link_libraries(Player
    PRIVATE
        PlayerId
        Card
)

add_subdirectory(PlayerId)