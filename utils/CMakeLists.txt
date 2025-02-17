set(SOURCES_DIR src/)
set(SOURCES debug-callback.cpp)
list(TRANSFORM SOURCES PREPEND ${SOURCES_DIR})

set(HEADER_DIR include/)
set(HEADERS debug-callback.hpp)
list(TRANSFORM HEADERS PREPEND ${HEADER_DIR})

add_library(utils STATIC ${SOURCES} ${HEADERS})
target_include_directories(utils PRIVATE Vulkan::Headers ${HEADER_DIR})
target_link_libraries(utils PRIVATE Vulkan::Vulkan)
