cmake_minimum_required(VERSION 3.28)
project(sdl_practice)
set(CMAKE_CXX_STANDARD 26)

#(on Windows, ensure CMAKE_PREFIX_PATH is added to path containing a directory with SDL lib/inc files)
find_package(SDL3 CONFIG REQUIRED) # by default SDL3 is happy to install in the CMAKE_PREFIX_PATH dir
find_package(Vulkan REQUIRED) # by default the LunarG Vulkan SDK installer installs Vulkan lib/inc at C:/VulkanSDK on Windows

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
target_include_directories(sdl_practice PRIVATE ${INCLUDE} Vulkan::Headers)
target_link_libraries(sdl_practice PRIVATE SDL3::SDL3 Vulkan::Vulkan)

#Copy SDL3.dll from CMAKE_PREFIX_PATH environment variable directory to the post-build directory
if (WIN32)
    add_custom_command(
            TARGET sdl_practice POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL3::SDL3>" "$<TARGET_FILE_DIR:sdl_practice>"
            VERBATIM
    )
endif ()