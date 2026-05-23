add_executable(SchottenTotten)

target_sources(SchottenTotten 
  PRIVATE
    main.cpp)

# Dependencies:

# Subdirectories:
add_subdirectory(Action)
add_subdirectory(Card)
add_subdirectory(Game)
add_subdirectory(Player)
