cmake_minimum_required(VERSION 3.28)
project(sdl_practice)
set(CMAKE_CXX_STANDARD 26)

#(on Windows, ensure CMAKE_PREFIX_PATH is added to path containing a directory with SDL2 lib/inc files)
find_package(SDL2 CONFIG REQUIRED SDL2)

set(SRC main.cpp
        input.cpp
        renderer.cpp
        window.cpp
)
list(TRANSFORM SRC PREPEND "src/") #Handy way to not need to prefix all src files with the src/ directory

#Headers
set(INCLUDE ${PROJECT_SOURCE_DIR}/include)

#Generate executable, include headers and link libs
add_executable(sdl_practice ${SRC})
target_include_directories(sdl_practice PRIVATE ${INCLUDE})
target_link_libraries(sdl_practice SDL2::SDL2 SDL2::SDL2main)