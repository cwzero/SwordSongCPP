add_subdirectory(SwordSong)

add_library(glad STATIC glad.c)
target_include_directories(glad PUBLIC "${PROJECT_SOURCE_DIR}/Include")