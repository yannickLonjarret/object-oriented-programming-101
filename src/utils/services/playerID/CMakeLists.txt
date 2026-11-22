add_library(PlayerIdService)

target_sources(PlayerIdService
    PRIVATE
        playerIDService.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            playerIDService.h
)

target_link_libraries(PlayerIdService
    PRIVATE
        PlayerId)