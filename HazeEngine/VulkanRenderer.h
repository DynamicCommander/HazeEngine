#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H

/*
<Dylan Higbee>
<April 3rd, 2018>
<7:49AM>
<VulkanRenderer.h>
<Vulkan Renderer Class Declaration>
*/

#pragma once

#include "stdafx.h"

#include "CSystem.h"
#include "VkVertex.h"

#include "Haze_Functions_STD.h"

#include <vector>
#include <array>

using namespace Haze_Engine;

namespace Vulkan_Renderer
{

	//Contains indices of Queue Families that satisfy certain desired properties (-1 == not found)
	struct QueueFamilyIndices
	{
		int graphicsFamily = -1;
		int presentFamily = -1;

		bool isComplete() { return graphicsFamily >= 0 && presentFamily >= 0; }
	};

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR		capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR>	presentModes;
	};

	struct UniformBufferObject
	{
		mat4 model;
		mat4 view;
		mat4 proj;
	};

	//Vulkan Renderer class, renders all objects in window
	class VulkanRenderer : public CSystem
	{

	public:
		VulkanRenderer();																							//Vulkan Renderer Constructor
		~VulkanRenderer();																							//Vulkan Renderer Destructor

		const bool					IsWindowClose() { return vkrWindowClose; };										//Is the GLFW window closed?	
		GLFWwindow*					GetGLFWWindow() { return glfwWindow; }											//Return the GLFW window

		void						Initialize(HazeEngine* _engine);												//Initialize
		void						Update(float _deltaTime);														//Update
		void						ShutDown();																		//Shutdown
		void						Render();																		//Vulkan Render, renders all buffers to window

		float						GetAspectRatio();																//Calculates Aspect Ratio

		//const std::vector<Vertex> triangleVertices = 
		//{
		//	{ { 0.0f, -0.5f },{ 1.0f, 1.0f, 1.0f } },
		//	{ { 0.5f, 0.5f },{ 0.0f, 1.0f, 0.0f } },
		//	{ { -0.5f, 0.5f },{ 0.0f, 0.0f, 1.0f } }
		//};

		const std::vector<VkVertex> vertices =
		{
			{ {-1.0f, -1.0f, -1.0f}	,{1.0f, 0.0f, 0.0f} },
			{ {1.0f, -1.0f, -1.0f}	,{0.0f, 1.0f, 0.0f} },
			{ {1.0f, 1.0f, -1.0f}	,{0.0f, 0.0f, 1.0f} },
			{ {-1.0f, 1.0f, -1.0f}	,{1.0f, 1.0f, 1.0f} },
			{ {-1.0f, -1.0f, 1.0f}	,{1.0f, 0.0f, 0.0f} },
			{ {1.0f, -1.0f, 1.0f}	,{0.0f, 1.0f, 0.0f} },
			{ {1.0f, 1.0f, 1.0f}	,{0.0f, 0.0f, 1.0f} },
			{ {-1.0f, 1.0f, 1.0f}	,{1.0f, 1.0f, 1.0f} }
		};
		
		const std::vector<uint16_t> indices =
		{
			0, 1, 3, 3, 1, 2,
			1, 5, 2, 2, 5, 6,
			5, 4, 6, 6, 4, 7,
			4, 0, 7, 7, 0, 3,
			3, 2, 7, 7, 2, 6,
			4, 5, 0, 0, 5, 1
		};

	private:

		HazeEngine*		hzEngine;

		////////////////////////////////////////VULKAN INSTANCE MEMBERS AND FUNCTIONS////////////////////////////////////////
		VkInstance					vkInstance;																		//Vulkan Instance
		VkResult					CreateVkInstance(VkStructureType _applicationInfo, std::string _applicationName, int _applicationVersion, std::string _engineName, int _engineVersion, int _apiVersion); //Creates Vulkan Instance
		////////////////////////////////////////VULKAN INSTANCE MEMBERS AND FUNCTIONS////////////////////////////////////////


		////////////////////////////////////////VULKAN PHYSICAL AND LOGICAL DEVICE MEMBERS AND FUNCTIONS////////////////////////////////////////
		VkPhysicalDevice			vkPhysicalDevice = VK_NULL_HANDLE;												//Vulkan Physcial Device, link to physcial hardware
		VkDevice					vkLogicalDevice;																//Vulkan Logical Device, link to vulkan software

		VkResult					CreateVkPhyscialDevice();														//Creates Physcial Device
		bool						IsPhysicalDeviceSuitable(VkPhysicalDevice _device);								//Verifies that a physcial device exists that supports vulkan features
		bool						CheckDeviceExtensionSupport(VkPhysicalDevice _device);							//Checks Extension support for physcial device
		QueueFamilyIndices			FindQueueFamilies(VkPhysicalDevice _device);									//Finds waht queue families are supported by physcial device
		std::vector<const char*>	GetRequiredExtensions();														//Finds what extensions are needed for feature levels
		VkResult					CreateVkLogicalDevice();														//Creates Logical Device
		////////////////////////////////////////VULKAN PHYSICAL AND LOGICAL DEVICE MEMBERS AND FUNCTIONS////////////////////////////////////////



		////////////////////////////////////////VULKAN SWAP CHAIN MEMBERS AND FUNCTIONS////////////////////////////////////////
		VkSwapchainKHR				vkSwapChain;																	//Vulkan Swap Chain
		std::vector<VkImage>		vkSwapChainImages;																//Swap Chain Images to swap between
		std::vector<VkImageView>	vkSwapChainImageViews;															//Swap Chain Image Views
		VkFormat					vkSwapChainImageFormat;															//Image Format
		VkExtent2D					vkSwapChainExtent;																//Extent 2D Format
		VkSemaphore					vkImageAvailable;																//Is the Image available for render?
		VkSemaphore					vkRenderFinished;																//Has the Image finished rendering?

		VkResult					CreateSwapChain();																//Creates Swap Chain using previously defined structures
		void						CleanupSwapChain();																//Destroys Swap Chain for re-creation purposes
		VkResult					ReCreateSwapChain();															//Recreate Swap Chain
		VkResult					CreateImageViews();																//Creates Image Views for Swap Chain
		SwapChainSupportDetails		QuerySwapChainSupport(VkPhysicalDevice _device);								//Queries Swap Chain support features
		VkSurfaceFormatKHR			ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);	//Chooses Swap Surface formats
		VkPresentModeKHR			ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);	//Chooses Swap Present mode
		VkExtent2D					ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);					//Chooses Swap Extent
		VkResult					CreateSemaphores();																//Create's Semaphores
		////////////////////////////////////////VULKAN SWAP CHAIN MEMBERS AND FUNCTIONS////////////////////////////////////////



		////////////////////////////////////////VULKAN BUFFER MEMBERS AND FUNCTIONS////////////////////////////////////////
		VkBuffer					vkVertexBuffer;																	//Vertex Buffer, contains vertex information
		VkDeviceMemory				vkVertexBufferMemory;															//Allocated Memory Dedicated to Vertex buffer
		VkBuffer					vkIndexBuffer;																	//Index Buffer, contains index information 
		VkDeviceMemory				vkIndexBufferMemory;															//Allocated Memory Dedicated to Index Buffer
		VkBuffer					vkUniformBuffer;																//Uniform Buffer, used for uniform data transfer to shaders
		VkDeviceMemory				vkUniformBufferMemory;															//Allocated Memory Dedicated to Uniform Buffer
		VkDescriptorPool			vkDescriptorPool;																//Descriptor Pool
		VkDescriptorSet				vkDescriptorSet;																//Descriptor Set
		bool						vkRebuildBuffers;																//Reminds Vulkan to Rebuild Vertex, Index, and Uniform Buffers

		VkResult					CreateBuffer(VkDeviceSize _deviceSize, VkBufferUsageFlags _usageFlags, VkMemoryPropertyFlags _propertyFlags, VkBuffer& _buffer, VkDeviceMemory& _bufferMemory); //General buffer creation function
		VkResult					CopyBuffer(VkBuffer _srcBuffer, VkBuffer _destBuffer, VkDeviceSize _size);		//Copies buffer information from src to dest
		void						UpdateUniformBuffer(float _deltaTime);											//Updates uniform buffer every frame

		VkResult					CreateVertexBuffer();															//Create Vertex Buffer
		VkResult					CreateIndexBuffer();															//Create Index Buffer
		VkResult					CreateUniformBuffer();															//Create Uniform Buffer
		VkResult					CreateDescriptorPool();															//Create Descriptor Pool
		VkResult					CreateDescriptorSet();															//Create Descriptor Set
		uint32_t					FindMemoryType(uint32_t _typeFilter, VkMemoryPropertyFlags _properties);
		////////////////////////////////////////VULKAN BUFFER MEMBERS AND FUNCTIONS////////////////////////////////////////



		////////////////////////////////////////VULKAN GRAPHICS AND SURFACE MEMBERS AND FUNCTIONS////////////////////////////////////////
		VkQueue						vkGraphicsQueue;																//Vulkan Graphics Queue
		VkQueue						vkPresentationQueue;															//Vulkan Presentation Queue
		VkSurfaceKHR				vkSurfaceKHR;																	//Vulkan Window Surface
		VkPipeline					vkGraphicsPipeline;																//Vulkan Graphics Pipeline
		VkDescriptorSetLayout		vkDescriptorSetLayout;
		VkPipelineLayout			vkPipelineLayout;																//Layout of graphics pipeline
		std::vector<VkFramebuffer>	vkSwapChainFrameBuffers;														//Swap Chain frame buffers
		VkCommandPool				vkCommandPool;																	//Vulkan Command Pool
		std::vector<VkCommandBuffer> vkCommandBuffers;																//Command Buffers
		VkRenderPass				vkRenderPass;																	//Vulkan Render Pass
		bool						vkrWindowClose;																	//Controls whether Vulkan Renderer should shut down and clean up all data

		VkResult					CreateVulkanWindowSurface();													//Create Vulkan Window Surface
		VkResult					CreateGraphicsPipeline();														//Create Graphics Pipeline
		static std::vector<char>	ReadShaderFile(const std::string& _filename);									//Read Shader files from .spv
		VkShaderModule				CreateShaderModule(const std::vector<char>& code);								//Create Shader Module based on compiled code
		VkResult					CreateFrameBuffers();															//Create Frame Buffers
		VkResult					CreateCommandPool();															//Create Command Pool
		VkResult					CreateCommandBuffers();															//Create Command Buffers
		VkResult					CreateDescriptorSetLayout();													//Create Descriptor Set Layout
		VkResult					CreateRenderPass();																//Create Render Pass
		void						SetVkrWindowClose(bool _windowClose) { vkrWindowClose = _windowClose; }			//Set Window Close
		////////////////////////////////////////VULKAN GRAPHICS AND SURFACE MEMBERS AND FUNCTIONS////////////////////////////////////////

		VkDebugReportCallbackEXT	vkDebugCallback;

		void						SetupDebugCallback();
		bool						CheckValidationLayerSupport();
		VkResult					CreateDebugReportCallbackEXT(VkInstance _instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
		void						DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
		static						VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData);

		////////////////////////////////////////OPENGL MEMBERS AND FUNCTIONS////////////////////////////////////////
		GLFWwindow*					glfwWindow;																		//OpenGL window management
		const GLFWvidmode*			glfwVidMode;																	//OpenGL Video Mode

		void						CreateGlfwWindow();																//Creates OGL window
		static void					OnWindowResized(GLFWwindow* _window, int _width, int _height);					//Recreates Swap Chain after window resize
		////////////////////////////////////////OPENGL MEMBERS AND FUNCTIONS////////////////////////////////////////

		const std::vector<const char*> deviceExtensions = { "VK_KHR_swapchain" };
		const std::vector<const char*> validationLayers = { "VK_LAYER_LUNARG_standard_validation" };

#ifdef NDEBUG
		const bool enableValidationLayers = false;						//Disable Debug Layers
#else
		const bool enableValidationLayers = true;						//Enable Debug Layers
#endif


		bool IS_VK_SUCCESS(VkResult _vk_result, std::string _message)
		{
			if (_vk_result != VK_SUCCESS)
				throw std::runtime_error(_message);

			return true;
		}
	};

}

#endif





