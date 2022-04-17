add_executable(SwordSong Main.cpp SwordSong.cpp Engine.cpp Game.cpp Model.cpp RenderEngine.cpp Shader.cpp TileSet.cpp Window.cpp)
target_include_directories(SwordSong PUBLIC "${PROJECT_SOURCE_DIR}/Include")

find_package(OpenGL REQUIRED)
target_link_libraries(SwordSong OpenGL::GL)
target_link_libraries(SwordSong glfw)
target_link_libraries(SwordSong glad)

file(COPY ${CMAKE_SOURCE_DIR}/Resources DESTINATION ${CMAKE_BINARY_DIR}/Source/Debug)