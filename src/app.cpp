#include "app.hpp"
#include "constants.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "validation.hpp"
#include "window.hpp"

#include <SDL3/SDL_vulkan.h>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace App
{
    namespace // anonymous namespace here allows encapsulated initialization without using class/singleton
    {
        std::vector<const char*> getRequiredExtensions()
        {
            uint32_t sdlExtensionCount = 0;
            char const* const* sdlExtensions = SDL_Vulkan_GetInstanceExtensions(&sdlExtensionCount);

            std::vector<const char*> extensions(sdlExtensions, sdlExtensions + sdlExtensionCount);

            if (Validation::enableValidationLayers) {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            }

            return extensions;
        }

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
            appInfo.apiVersion = VK_API_VERSION_1_1;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;
            if (validationLayers.value())
            {
                createInfo.enabledLayerCount = Validation::validationLayers.size();
                createInfo.ppEnabledLayerNames = Validation::validationLayers.data();
            } else
            {
                createInfo.enabledLayerCount = 0;
            }

            std::vector extensions{ getRequiredExtensions() };

            if constexpr (constexpr bool appleHardware = false; appleHardware == true) //TODO: add check for MacOS to flip this bool
            {
                extensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
                createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
            }
            createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
            createInfo.ppEnabledExtensionNames = extensions.data();

            if (VkInstance instance; vkCreateInstance(&createInfo, nullptr, &instance) == VK_SUCCESS)
            {
                return instance;
            }
            return std::unexpected{"Failed to create Vulkan instance"};
        }

        void setupDebugMessenger()
        {
            if constexpr (!Validation::enableValidationLayers) return;

            VkDebugUtilsMessengerCreateInfoEXT createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
            createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
            createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
            //createInfo.pfnUserCallback = debugCallback;
            createInfo.pUserData = nullptr; // Optional
        }

        // More complex init logic than just creating the instance will go here eventually
        std::expected<VkInstance, std::string> initVulkan()
        {
            auto result = createInstance();
            if (result)
            {
                setupDebugMessenger();
            }
            return createInstance();
        }

        VkDebugUtilsMessengerEXT debugMessenger;

        void mainLoop(Window& window)
        {
            while (Input::Event::trigger() != SDL_EVENT_QUIT)
            {
                // Renderer r {window};
                // r.renderRectangle(Color{ 86, 8,24, },Transparency::HALF);
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
        mainLoop(window);
        cleanup(vkInstance.value());
        return {};
    }
}
