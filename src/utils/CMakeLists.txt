add_library(Utilities SHARED)

set_target_properties(Utilities PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

install(TARGETS Utilities
        LIBRARY DESTINATION bin
        )

add_subdirectory(math)