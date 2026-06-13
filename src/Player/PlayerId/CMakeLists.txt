add_library(PlayerId)

target_sources(PlayerId
    PRIVATE
        playerId.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            playerId.h
)