#pragma once

#include <expected>
#include <string>
#include <vector>

namespace Validation
{
    const std::vector validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};
    std::expected<uint32_t, std::string> checkValidationLayerSupport();
}
