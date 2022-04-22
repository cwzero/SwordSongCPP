add_executable(SwordSong 
    Main.cpp
    SwordSong.cpp
    Drawable.cpp
    Engine.cpp 
    Entity.cpp
    Game.cpp 
    GameWorld.cpp 
    KeyEvent.cpp
    LayeredTile.cpp
    Model.cpp 
    Movable.cpp
    Player.cpp 
    PlayerView.cpp 
    RenderEngine.cpp 
    Shader.cpp 
    Space.cpp
    StackTile.cpp
    StaticTile.cpp
    TileGrid.cpp 
    TileSet.cpp 
    Window.cpp)
target_include_directories(SwordSong PUBLIC "${PROJECT_SOURCE_DIR}/Include")

find_package(OpenGL REQUIRED)
target_link_libraries(SwordSong OpenGL::GL)
target_link_libraries(SwordSong glfw)
target_link_libraries(SwordSong glad)
target_link_libraries(SwordSong glm)

file(COPY ${CMAKE_SOURCE_DIR}/Resources DESTINATION ${CMAKE_BINARY_DIR}/Source/Debug)