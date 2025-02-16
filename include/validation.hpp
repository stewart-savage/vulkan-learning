#pragma once

#include <array>
#include <expected>
#include <string>

namespace Validation
{
#ifdef NDEBUG
    constexpr bool enableValidationLayers = false;
#else
    constexpr bool enableValidationLayers = true;
#endif

    constexpr std::array<const char*, 1> validationLayers = {"VK_LAYER_KHRONOS_validation"};
    std::expected<bool, std::string> checkValidationLayerSupport();
}
