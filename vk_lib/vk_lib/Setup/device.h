#pragma once
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class Device{
public:
	Device();
	~Device();

	VkDevice GetDevice() const { return _device; }

private:
	VkInstance _instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkDevice _device = VK_NULL_HANDLE;
	VkPhysicalDevice _physicalDevice;
	VkQueue _graphicsQueue;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

	void CreateInstance();

	bool isDeviceSuitable(VkPhysicalDevice device);
	void PickPhysicalDevice();

	void CreateDevice();	

	bool checkValidationLayerSupport();
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void setupDebugMessenger();
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
		const VkAllocationCallbacks* pAllocator);

	std::vector<const char*> getRequiredExtensions();

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};

