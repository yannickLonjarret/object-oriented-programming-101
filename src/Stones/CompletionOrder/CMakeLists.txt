add_library(CompletionOrder)

target_sources(CompletionOrder
    PRIVATE
        completionOrder.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            completionOrder.h
)

target_link_libraries(CompletionOrder
    PRIVATE
        PlayerId
)
