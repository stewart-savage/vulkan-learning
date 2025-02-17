## Description ##
Based on the instuctions provided at https://vulkan-tutorial.com/
In its current state this project is only for learning purposes- I may one day fork what is in here to create something more concrete.

## Dependencies/Requirements ##
CMake for building the project. (https://cmake.org/download/)
See root CMakeLists.txt for version currently used, although older versions may work fine.

Vulkan SDK/Headers (https://vulkan.lunarg.com/sdk/home)
Ensure the headers are available on your environment variables (Windows), or on Linux, installed to /usr/include or /usr/local/include

SDL3 (https://github.com/libsdl-org/SDL/releases)
Ensure the SDL3 files are present in your CMAKE_PREFIX_PATH enviroment variable directory (Windows), or on Linux, that headers are available at /usr/include and libraries are available at /usr/lib
