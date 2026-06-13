add_library(Side)

target_sources(Side
    PRIVATE
        side.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            side.h
)
