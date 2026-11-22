add_library(UtilsMath OBJECT)

target_sources(UtilsMath
    PRIVATE
        utils_math.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            utils_math.h
)