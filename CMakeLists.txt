cmake_minimum_required(VERSION 3.28)
project(sdl_practice)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_COMPILE_WARNING_AS_ERROR)

#on Windows, ensure CMAKE_PREFIX_PATH is added to path containing a directory with SDL lib/inc files.
#on Linux, the libraries usually just get to be installed to /usr/lib and /usr/include via distro package managers.
find_package(SDL3 CONFIG REQUIRED) # by default SDL3 is happy to install in the CMAKE_PREFIX_PATH dir
find_package(Vulkan REQUIRED) # by default the LunarG Vulkan SDK installer installs Vulkan lib/inc at C:/VulkanSDK on Windows

set(SOURCES_DIR src/)
set(SOURCES main.cpp
        app.cpp
        input.cpp
        renderer.cpp
        validation.cpp
        window.cpp
)
list(TRANSFORM SOURCES PREPEND ${SOURCES_DIR})

set(HEADER_DIR include/)
set(HEADERS app.hpp
        color.hpp
        constants.hpp
        errors.hpp
        input.hpp
        renderer.hpp
        validation.hpp
        window.hpp
)
list(TRANSFORM HEADERS PREPEND ${HEADER_DIR})

add_executable(sdl_practice ${SOURCES} ${HEADERS})

target_include_directories(sdl_practice PRIVATE Vulkan::Headers ${HEADER_DIR})
# add subdirectories
add_subdirectory(utils)
target_link_libraries(sdl_practice PRIVATE SDL3::SDL3 Vulkan::Vulkan utils)

#Copy SDL3.dll from CMAKE_PREFIX_PATH environment variable directory to the post-build directory
if (WIN32)
    add_custom_command(
            TARGET sdl_practice POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL3::SDL3>" "$<TARGET_FILE_DIR:sdl_practice>"
            VERBATIM
    )
endif ()