add_library(Utilities SHARED)

set_target_properties(Utilities PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

install(TARGETS Utilities
        LIBRARY DESTINATION CMAKE_RUNTIME_OUTPUT_DIRECTORY
        )

add_subdirectory(math)