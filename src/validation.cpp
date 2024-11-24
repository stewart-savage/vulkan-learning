#include "validation.hpp"

#include <expected>
#include <format>
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace Validation
{
#ifdef NDEBUG
    constexpr bool enableValidationLayers = false;
#else
    constexpr bool enableValidationLayers = true;
#endif


    std::expected<uint32_t, std::string> checkValidationLayerSupport()
    {
        if constexpr (!enableValidationLayers)
            return 0;

        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for (const char* layerName: validationLayers)
        {
            bool layerFound = false;
            for (const auto& layerProperties: availableLayers)
            {
                if (std::strcmp(layerName, layerProperties.layerName) == 0)
                {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound)
            {
                return std::unexpected(std::format("Missing validation layer: {} not found in available layers",
                                                   layerName));
            }
        }
        return {layerCount};
    }
}
