#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm> //std::min/max
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>//UINT32_MAX
#include <optional> //std::optional
#include <array>
#include <set> // std::set

const int WIDTH = 800; //maybe this shouldn't be hard coded like this
const int HEIGHT = 600; //		^                    ^

const int MAX_FRAMES_IN_FLIGHT = 2; //maybe this shouldn't be hard coded like this

const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" }; //Validation layers (debugging Vulcan)

const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME }; //Swap chain, queue of buffers (Vk has no default frame buffer)


#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif


struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

struct Vertex
{

};

class Render
{

public:

	GLFWwindow* window = nullptr;

	
	VkInstance instance = VK_NULL_HANDLE; ////Instance
	VkDebugUtilsMessengerEXT debugMessenger;//Validation
	VkSurfaceKHR surface = VK_NULL_HANDLE; //Pipeline?

	
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; //Device
	VkDevice device = VK_NULL_HANDLE; //Device
	
	VkQueue graphicsQueue = VK_NULL_HANDLE; //Queue
	VkQueue presentQueue = VK_NULL_HANDLE; //Queue

	//SwapChain
	VkSwapchainKHR swapChain = VK_NULL_HANDLE; 
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent = {};

	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;


	VkRenderPass renderPass = VK_NULL_HANDLE;
	VkPipelineLayout pipelineLayout = VK_NULL_HANDLE; //Pipeline
	VkPipeline graphicsPipeline = VK_NULL_HANDLE; //Pipeline

	VkCommandPool commandPool = VK_NULL_HANDLE; //CommandBuffers?

	VkBuffer vertexBuffer = VK_NULL_HANDLE; //VertexBuffer
	VkDeviceMemory vertexBufferMemory; //VErtexBuffer

	std::vector<VkCommandBuffer> commandBuffers; //CommandBuffers

	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	std::vector<VkFence> imagesInFlight;
	size_t currentFrame = 0;

	bool framebufferResized = false;

	const std::vector<Vertex> vertices = {
	{{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
	{{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
	{{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
	};


private:

};