add_library(Utilities SHARED)

set_target_properties(Utilities PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_link_libraries(Utilities
    PUBLIC
PlayerIdService
UtilsMath
)
add_subdirectory(math)
add_subdirectory(services)