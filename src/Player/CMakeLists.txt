add_library(Player)

target_sources(Player
    PRIVATE
        player.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            player.h
)

add_subdirectory(PlayerId)