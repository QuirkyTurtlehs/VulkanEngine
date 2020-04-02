#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


struct VulkanSetup
{
	VkInstance instance = VK_NULL_HANDLE;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device = VK_NULL_HANDLE;

	VkQueue graphicsQueue;

	void CreateInstance();

	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);	

	void createLogicalDevice();

	void CleanUp();
};

