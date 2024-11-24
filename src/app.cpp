#include "app.hpp"
#include "input.hpp"
#include "validation.hpp"
#include "window.hpp"

#include <vector>
#include <vulkan/vulkan_core.h>

namespace App
{
    namespace // anonymous namespace here allows encapsulated initialization without using class/singleton
    {
        std::expected<VkInstance, std::string> createInstance()
        {
            auto validationLayers = Validation::checkValidationLayerSupport();
            if (!validationLayers)
            {
                return std::unexpected(validationLayers.error());
            }

            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello Triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;
            if (const uint32_t layerCount = validationLayers.value(); layerCount > 0)
            {
                createInfo.enabledLayerCount = layerCount;
                createInfo.ppEnabledLayerNames = Validation::validationLayers.data();
            } else
            {
                createInfo.enabledLayerCount = 0;
            }

            uint32_t extensionCount;
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
            std::vector<VkExtensionProperties> extensions(extensionCount);
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
            std::vector<const char*> extensionNames;
            extensionNames.reserve(extensionCount);
            for (const VkExtensionProperties& extension: extensions)
            {
                extensionNames.emplace_back(extension.extensionName);
            }
            if (const bool appleHardware = false; appleHardware == true) //TODO: add check for MacOS to flip this bool
            {
                extensionNames.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
                extensionCount++;
                createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
            }
            createInfo.enabledExtensionCount = extensionCount;
            createInfo.ppEnabledExtensionNames = extensionNames.data();

            if (VkInstance instance; vkCreateInstance(&createInfo, nullptr, &instance) == VK_SUCCESS)
            {
                return instance;
            }
            return std::unexpected{"Failed to create Vulkan instance"};
        }

        // More complex init logic than just creating the instance will go here eventually
        std::expected<VkInstance, std::string> initVulkan()
        {
            return createInstance();
        }

        void mainLoop()
        {
            while (Input::Event::trigger() != SDL_EVENT_QUIT)
            {
                // ?
            }
        }

        void cleanup(const VkInstance& instance)
        {
            vkDestroyInstance(instance, nullptr);
            SDL_Quit();
        }
    } // namespace

    std::expected<void, std::string> run()
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
            return std::unexpected("Error initializing SDL");
        Window window{};
        auto vkInstance = initVulkan();
        if (!vkInstance.has_value())
            return std::unexpected(vkInstance.error());
        mainLoop();
        cleanup(vkInstance.value());
        return {};
    }
}
