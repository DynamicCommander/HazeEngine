/*
<Dylan Higbee>
<April 6th, 2018>
<7:49AM>
<VulkanRenderer.cpp>
<Vulkan Renderer Implementation>
*/

#include "stdafx.h"

#include "HazeEngine.h"
using namespace Haze_Engine;

#include "VulkanRenderer.h"

#include "Model.h"

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <fstream>

namespace Vulkan_Renderer
{

	VulkanRenderer::VulkanRenderer()
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	}

	VulkanRenderer::~VulkanRenderer()
	{
		CleanupSwapChain();

		vkDestroyDescriptorPool(vkLogicalDevice, vkDescriptorPool, nullptr);

		vkDestroyDescriptorSetLayout(vkLogicalDevice, vkDescriptorSetLayout, nullptr);

		for (int i = 0; i < vkSwapChainImages.size(); i++)
		{
			vkDestroyBuffer(vkLogicalDevice, vkUniformBuffers[i], nullptr);
			vkFreeMemory(vkLogicalDevice, vkUniformBuffersMemory[i], nullptr);
		}

		vkDestroyBuffer(vkLogicalDevice, vkIndexBuffer, nullptr);
		vkFreeMemory(vkLogicalDevice, vkIndexBufferMemory, nullptr);

		vkDestroyBuffer(vkLogicalDevice, vkVertexBuffer, nullptr);
		vkFreeMemory(vkLogicalDevice, vkVertexBufferMemory, nullptr);

		vkDestroySemaphore(vkLogicalDevice, vkImageAvailable, nullptr);
		vkDestroySemaphore(vkLogicalDevice, vkRenderFinished, nullptr);

		vkDestroyCommandPool(vkLogicalDevice, vkCommandPool, nullptr);

		vkDestroyDevice(vkLogicalDevice, nullptr);
		DestroyDebugReportCallbackEXT(vkInstance, vkDebugCallback, nullptr);
		vkDestroySurfaceKHR(vkInstance, vkSurfaceKHR, nullptr);
		vkDestroyInstance(vkInstance, nullptr);

		glfwDestroyWindow(glfwWindow);
		glfwTerminate();
	}

	void VulkanRenderer::Initialize()
	{
		VkResult vk_result;
		CreateGlfwWindow();
		vk_result = CreateVkInstance(VK_STRUCTURE_TYPE_APPLICATION_INFO, "Vulkan Renderer", 0, "Haze Engine", 0, VK_API_VERSION_1_0);
		SetupDebugCallback();
		vk_result = CreateVulkanWindowSurface();
		vk_result = CreateVkPhyscialDevice();
		vk_result = CreateVkLogicalDevice();
		vk_result = CreateSwapChain();
		vk_result = CreateImageViews();
		vk_result = CreateRenderPass();
		vk_result = CreateDescriptorSetLayout();
		vk_result = CreateGraphicsPipeline();
		vk_result = CreateFrameBuffers();
		vk_result = CreateCommandPool();
		vk_result = CreateUniformBuffer();
		vk_result = CreateDescriptorPool();
		vk_result = CreateDescriptorSet();

		vk_result = CreateSemaphores();
	}

	void VulkanRenderer::Update(float _deltaTime)
	{
		if (vkRebuildBuffers)
		{
			CreateVertexBuffer();
			CreateIndexBuffer();
			CreateCommandBuffers();
			vkRebuildBuffers = false;
		}

		Render();
		SetVkrWindowClose(glfwWindowShouldClose(glfwWindow));
	}

	void VulkanRenderer::ShutDown()
	{
		vkDeviceWaitIdle(vkLogicalDevice);
	}

	void VulkanRenderer::Render()
	{
		VkResult vk_result;

		uint32_t imageIndex;
		vk_result = vkAcquireNextImageKHR(vkLogicalDevice, vkSwapChain, std::numeric_limits<uint64_t>::max(), vkImageAvailable, VK_NULL_HANDLE, &imageIndex);
		if (vk_result == VK_ERROR_OUT_OF_DATE_KHR)
		{
			ReCreateSwapChain();
			return;
		}
		else if (vk_result != VK_SUCCESS && vk_result != VK_SUBOPTIMAL_KHR)
			throw std::runtime_error("failed to acquire swap chain image!");

		UpdateUniformBuffer(imageIndex);

		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

		VkSemaphore waitSemaphores[] = { vkImageAvailable };
		VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
		submitInfo.waitSemaphoreCount = 1;
		submitInfo.pWaitSemaphores = waitSemaphores;
		submitInfo.pWaitDstStageMask = waitStages;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &vkCommandBuffers[imageIndex];

		VkSemaphore signalSemaphores[] = { vkRenderFinished };
		submitInfo.signalSemaphoreCount = 1;
		submitInfo.pSignalSemaphores = signalSemaphores;

		vk_result = vkQueueSubmit(vkGraphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
		IS_VK_SUCCESS(vk_result, "Failed to Submit Draw Command Buffer");

		VkPresentInfoKHR presentInfo = {};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 1;
		presentInfo.pWaitSemaphores = signalSemaphores;

		VkSwapchainKHR swapChains[] = { vkSwapChain };
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = swapChains;
		presentInfo.pImageIndices = &imageIndex;
		presentInfo.pResults = nullptr;

		vk_result = vkQueuePresentKHR(vkPresentationQueue, &presentInfo);
		if (vk_result == VK_ERROR_OUT_OF_DATE_KHR || vk_result == VK_SUBOPTIMAL_KHR)
			ReCreateSwapChain();
		else if (IS_VK_SUCCESS(vk_result, "Failed to present swap chain image!"))

			vkQueueWaitIdle(vkPresentationQueue);
	}

	VkResult VulkanRenderer::CreateVkInstance(VkStructureType _applicationInfo, std::string _applicationName, int _applicationVersion, std::string _engineName, int _engineVersion, int _apiVersion)
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = _applicationInfo;
		appInfo.pApplicationName = _applicationName.c_str();
		appInfo.applicationVersion = _applicationVersion;
		appInfo.pEngineName = _engineName.c_str();
		appInfo.engineVersion = _engineVersion;
		appInfo.apiVersion = _apiVersion;

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		std::vector<const char*> extensions = GetRequiredExtensions();
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.enabledLayerCount = 0;

		if (enableValidationLayers)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
			createInfo.enabledLayerCount = 0;

		VkResult vk_result = vkCreateInstance(&createInfo, nullptr, &vkInstance);

		return vk_result;
	}

	VkResult VulkanRenderer::CreateVkPhyscialDevice()
	{
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(vkInstance, &deviceCount, nullptr);
		if (deviceCount == 0)
			throw std::runtime_error("failed to locate GPU's with Vulkan Support");

		std::vector<VkPhysicalDevice> devices(deviceCount);
		VkResult vk_result = vkEnumeratePhysicalDevices(vkInstance, &deviceCount, devices.data());

		for (const auto& device : devices)
		{
			if (IsPhysicalDeviceSuitable(device))
			{
				vkPhysicalDevice = device;
				break;
			}
		}

		if (vkPhysicalDevice == VK_NULL_HANDLE)
			throw std::runtime_error("Failed to Find Suitable GPU");

		return vk_result;
	}

	bool VulkanRenderer::IsPhysicalDeviceSuitable(VkPhysicalDevice _device)
	{
		VkPhysicalDeviceProperties deviceProperties;
		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceProperties(_device, &deviceProperties);
		vkGetPhysicalDeviceFeatures(_device, &deviceFeatures);

		QueueFamilyIndices indices = FindQueueFamilies(_device);

		bool extensionsSupported = CheckDeviceExtensionSupport(_device);

		bool swapChainAdequate = false;
		if (extensionsSupported)
		{
			SwapChainSupportDetails swapChainSupport = QuerySwapChainSupport(_device);
			swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
		}

		return indices.isComplete() && extensionsSupported && swapChainAdequate;
	}

	VkSurfaceFormatKHR VulkanRenderer::ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats)
	{
		if (availableFormats.size() == 1 && availableFormats[0].format == VK_FORMAT_UNDEFINED)
			return { VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };

		for (const auto& availableFormat : availableFormats)
			if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
				return availableFormat;

		return availableFormats[0];
	}

	VkPresentModeKHR VulkanRenderer::ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes)
	{
		VkPresentModeKHR bestMode = VK_PRESENT_MODE_FIFO_KHR;

		for (const auto& availablePresentMode : availablePresentModes)
		{
			if (availablePresentMode == VK_PRESENT_MODE_FIFO_KHR)
				return availablePresentMode;
			else if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR)
				return bestMode = availablePresentMode;
		}

		return bestMode;
	}

	VkExtent2D VulkanRenderer::ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities)
	{
		if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max())
			return capabilities.currentExtent;
		else
		{
			int windowWidth = 0;
			int windowHeight = 0;
			glfwGetWindowSize(glfwWindow, &windowWidth, &windowHeight);
			VkExtent2D actualExtent = { windowWidth, windowHeight };
			actualExtent.width = std::max(capabilities.minImageExtent.width, capabilities.minImageExtent.width);
			actualExtent.height = std::max(capabilities.minImageExtent.height, capabilities.minImageExtent.height);

			return actualExtent;
		}
	}

	VkResult VulkanRenderer::CreateSemaphores()
	{
		VkSemaphoreCreateInfo semaphoreInfo = {};
		semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

		VkResult vk_result = vkCreateSemaphore(vkLogicalDevice, &semaphoreInfo, nullptr, &vkImageAvailable);

		IS_VK_SUCCESS(vk_result, "Failed to Create Image Semaphore");

		vk_result = vkCreateSemaphore(vkLogicalDevice, &semaphoreInfo, nullptr, &vkRenderFinished);

		IS_VK_SUCCESS(vk_result, "Failed to Create Render Semaphore");

		return vk_result;
	}

	VkResult VulkanRenderer::CreateBuffer(VkDeviceSize _deviceSize, VkBufferUsageFlags _usageFlags, VkMemoryPropertyFlags _propertyFlags, VkBuffer& _buffer, VkDeviceMemory& _bufferMemory)
	{
		VkBufferCreateInfo bufferInfo = {};
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size = _deviceSize;
		bufferInfo.usage = _usageFlags;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		VkResult vk_result = vkCreateBuffer(vkLogicalDevice, &bufferInfo, nullptr, &_buffer);
		IS_VK_SUCCESS(vk_result, "Failed to Create Buffer!");

		VkMemoryRequirements memRequirements;
		vkGetBufferMemoryRequirements(vkLogicalDevice, _buffer, &memRequirements);

		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = FindMemoryType(memRequirements.memoryTypeBits, _propertyFlags);

		vk_result = vkAllocateMemory(vkLogicalDevice, &allocInfo, nullptr, &_bufferMemory);
		IS_VK_SUCCESS(vk_result, "Failed to Allocate Buffer Memory!");

		vk_result = vkBindBufferMemory(vkLogicalDevice, _buffer, _bufferMemory, 0);

		return vk_result;
	}

	VkResult VulkanRenderer::CopyBuffer(VkBuffer _srcBuffer, VkBuffer _destBuffer, VkDeviceSize _size)
	{
		VkResult vk_result;

		VkCommandBufferAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = vkCommandPool;
		allocInfo.commandBufferCount = 1;

		VkCommandBuffer commandBuffer;
		vk_result = vkAllocateCommandBuffers(vkLogicalDevice, &allocInfo, &commandBuffer);
		IS_VK_SUCCESS(vk_result, "Failed to Allocate Command Buffers");

		VkCommandBufferBeginInfo beginInfo = {};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

		vk_result = vkBeginCommandBuffer(commandBuffer, &beginInfo);
		IS_VK_SUCCESS(vk_result, "Failed to Begin Command Buffers");

		VkBufferCopy copyRegion = {};
		copyRegion.srcOffset = 0;
		copyRegion.dstOffset = 0;
		copyRegion.size = _size;
		vkCmdCopyBuffer(commandBuffer, _srcBuffer, _destBuffer, 1, &copyRegion);

		vk_result = vkEndCommandBuffer(commandBuffer);
		IS_VK_SUCCESS(vk_result, "Failed to End Command Buffers");

		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffer;

		vk_result = vkQueueSubmit(vkGraphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
		IS_VK_SUCCESS(vk_result, "Failed to Submit Buffer to Queue");
		vk_result = vkQueueWaitIdle(vkGraphicsQueue);
		IS_VK_SUCCESS(vk_result, "Queue Wait Idle Failed");

		vkFreeCommandBuffers(vkLogicalDevice, vkCommandPool, 1, &commandBuffer);

		return vk_result;
	}

	void VulkanRenderer::UpdateUniformBuffer(uint32_t _currentImage)
	{
		std::vector<Entity*> entities = HazeEngine::Instance()->GetEntityManager()->FindEntitiesByType<Model>();
		HazeCam* camera = HazeEngine::Instance()->GetEntityManager()->FindEntityByType<HazeCam>()->GetComponent<HazeCam>();

		void* data;
		for (int i = 0; i < entities.size(); i++)
		{
			UniformBufferObject ubo = {};
			ubo.model = entities[i]->GetComponent<Model>()->BuildModelMatrix();
			ubo.proj = camera->GetProjMatrix();
			ubo.view = camera->GetViewMatrix();
			ubo.proj[1][1] *= -1;

			vkMapMemory(vkLogicalDevice, vkUniformBuffersMemory[_currentImage], sizeof(UniformBufferObject) * i, sizeof(ubo), 0, &data);
			memcpy(data, &ubo, sizeof(ubo));
			vkUnmapMemory(vkLogicalDevice, vkUniformBuffersMemory[_currentImage]);
		}
	}

	VkResult VulkanRenderer::CreateVertexBuffer()
	{
		VkResult vk_result;

		VkDeviceSize bufferSize = 0;
		std::vector<Entity*> entities = HazeEngine::Instance()->GetEntityManager()->FindEntitiesByType<Model>();
		for (int i = 0; i < entities.size(); i++)
		{
			bufferSize += sizeof(VkVertex) * entities[i]->GetComponent<Model>()->GetVertices()->size();
		}

		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		vk_result = CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
		IS_VK_SUCCESS(vk_result, "Failed to Create Staging Buffer");

		void* data;
		for (int i = 0; i < entities.size(); i++)
		{
			Model* model = entities[i]->GetComponent<Model>();
			size_t modelVertAllocation = sizeof(VkVertex) * model->GetVertices()->size();
			size_t offset = sizeof(VkVertex) * model->GetVertices()->size() * i;

			vkMapMemory(vkLogicalDevice, stagingBufferMemory, offset, modelVertAllocation, 0, &data);
			memcpy(data, model->GetVertices()->data(), (size_t)modelVertAllocation);
			vkUnmapMemory(vkLogicalDevice, stagingBufferMemory);
		}

		vk_result = CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vkVertexBuffer, vkVertexBufferMemory);
		IS_VK_SUCCESS(vk_result, "Failed to Create Vertex Buffer");

		vk_result = CopyBuffer(stagingBuffer, vkVertexBuffer, bufferSize);
		IS_VK_SUCCESS(vk_result, "Failed to Copy Buffer");

		vkDestroyBuffer(vkLogicalDevice, stagingBuffer, nullptr);
		vkFreeMemory(vkLogicalDevice, stagingBufferMemory, nullptr);

		return vk_result;
	}

	VkResult VulkanRenderer::CreateIndexBuffer()
	{
		VkResult vk_result;

		std::vector<Entity*> entities = HazeEngine::Instance()->GetEntityManager()->FindEntitiesByType<Model>();
		VkDeviceSize bufferSize = 0;
		for (int i = 0; i < entities.size(); i++)
		{
			bufferSize += sizeof(VkVertex) * entities[i]->GetComponent<Model>()->GetIndices()->size();
		}

		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		vk_result = CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
		IS_VK_SUCCESS(vk_result, "Failed to Create Staging Index Buffer");

		void* data;
		for (int i = 0; i < entities.size(); i++)
		{
			Model* model = entities[i]->GetComponent<Model>();
			size_t modelIndexAllocation = sizeof(VkVertex) * model->GetIndices()->size();
			size_t offset = sizeof(VkVertex) * model->GetIndices()->size() * i;

			vkMapMemory(vkLogicalDevice, stagingBufferMemory, offset, modelIndexAllocation, 0, &data);
			memcpy(data, entities[i]->GetComponent<Model>()->GetIndices()->data(), (size_t)modelIndexAllocation);
			vkUnmapMemory(vkLogicalDevice, stagingBufferMemory);
		}

		vk_result = CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vkIndexBuffer, vkIndexBufferMemory);
		IS_VK_SUCCESS(vk_result, "Failed to Create Index Buffer");

		vk_result = CopyBuffer(stagingBuffer, vkIndexBuffer, bufferSize);
		IS_VK_SUCCESS(vk_result, "Failed to Copy Buffer");

		vkDestroyBuffer(vkLogicalDevice, stagingBuffer, nullptr);
		vkFreeMemory(vkLogicalDevice, stagingBufferMemory, nullptr);

		return vk_result;
	}

	VkResult VulkanRenderer::CreateUniformBuffer()
	{
		VkResult vk_result;
		VkDeviceSize bufferSize = sizeof(UniformBufferObject);

		vkUniformBuffers.resize(vkSwapChainImages.size());
		vkUniformBuffersMemory.resize(vkSwapChainImages.size());

		for (int i = 0; i < vkSwapChainImages.size(); i++)
			vk_result = CreateBuffer(bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, vkUniformBuffers[i], vkUniformBuffersMemory[i]);

		IS_VK_SUCCESS(vk_result, "Failed to Create Uniform Buffer");

		return vk_result;
	}

	VkResult VulkanRenderer::CreateDescriptorPool()
	{
		VkResult vk_result;

		std::array<VkDescriptorPoolSize, 2> poolSizes = {};
		poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		poolSizes[0].descriptorCount = static_cast<uint32_t>(vkSwapChainImages.size());
		poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		poolSizes[1].descriptorCount = static_cast<uint32_t>(vkSwapChainImages.size());

		VkDescriptorPoolCreateInfo poolInfo = {};
		poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		poolInfo.pPoolSizes = poolSizes.data();
		poolInfo.maxSets = static_cast<uint32_t>(vkSwapChainImages.size());

		vk_result = vkCreateDescriptorPool(vkLogicalDevice, &poolInfo, nullptr, &vkDescriptorPool);

		return vk_result;
	}

	VkResult VulkanRenderer::CreateDescriptorSet()
	{
		VkResult vk_result;

		std::vector<VkDescriptorSetLayout> layouts(vkSwapChainImages.size(), vkDescriptorSetLayout);
		VkDescriptorSetAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		allocInfo.descriptorPool = vkDescriptorPool;
		allocInfo.descriptorSetCount = static_cast<uint32_t>(vkSwapChainImages.size());
		allocInfo.pSetLayouts = layouts.data();

		vkDescriptorSets.resize(vkSwapChainImages.size());
		vk_result = vkAllocateDescriptorSets(vkLogicalDevice, &allocInfo, &vkDescriptorSets[0]);
		IS_VK_SUCCESS(vk_result, "Failed to Allocate Command Buffers!");

		for (size_t i = 0; i < vkSwapChainImages.size(); i++)
		{
			VkDescriptorBufferInfo bufferInfo = {};
			bufferInfo.buffer = vkUniformBuffers[i];
			bufferInfo.offset = 0;
			bufferInfo.range = sizeof(UniformBufferObject);

			//VkDescriptorImageInfo imageInfo = {};
			//imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
			//imageInfo.imageView = vkTextureImageView;
			//imageInfo.sampler = textureSampler;

			std::array<VkWriteDescriptorSet, 1> descriptorWrites = {};

			descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			descriptorWrites[0].dstSet = vkDescriptorSets[i];
			descriptorWrites[0].dstBinding = 0;
			descriptorWrites[0].dstArrayElement = 0;
			descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
			descriptorWrites[0].descriptorCount = 1;
			descriptorWrites[0].pBufferInfo = &bufferInfo;

			//descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			//descriptorWrites[1].dstSet = vkDescriptorSets[i];
			//descriptorWrites[1].dstBinding = 1;
			//descriptorWrites[1].dstArrayElement = 0;
			//descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
			//descriptorWrites[1].descriptorCount = 1;
			////descriptorWrites[1].pImageInfo = &imageInfo;

			vkUpdateDescriptorSets(vkLogicalDevice, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
		}

		return vk_result;
	}

	uint32_t VulkanRenderer::FindMemoryType(uint32_t _typeFilter, VkMemoryPropertyFlags _properties)
	{
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(vkPhysicalDevice, &memProperties);

		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++)
			if (_typeFilter & (1 << i) && (memProperties.memoryTypes[i].propertyFlags & _properties) == _properties)
				return i;

		throw std::runtime_error("failed to find suitable memory type!");
	}

	bool VulkanRenderer::CheckDeviceExtensionSupport(VkPhysicalDevice _device)
	{
		uint32_t extensionCount;
		vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, availableExtensions.data());

		std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

		for (const auto& extension : availableExtensions)
			requiredExtensions.erase(extension.extensionName);

		return requiredExtensions.empty();
	}

	VkResult VulkanRenderer::CreateVkLogicalDevice()
	{
		QueueFamilyIndices indices = FindQueueFamilies(vkPhysicalDevice);

		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
		std::set<int> uniqueQueueFamilies = { indices.graphicsFamily, indices.presentFamily };

		float queuePriority = 1.0f;

		for (int queueFamily : uniqueQueueFamilies)
		{
			VkDeviceQueueCreateInfo queueCreateInfo = {};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.queueFamilyIndex = indices.graphicsFamily;
			queueCreateInfo.queueCount = 1;
			queueCreateInfo.pQueuePriorities = &queuePriority;
			queueCreateInfos.push_back(queueCreateInfo);
		}

		VkPhysicalDeviceFeatures deviceFeatures = { VK_FALSE };

		VkDeviceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.pQueueCreateInfos = queueCreateInfos.data();
		createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
		createInfo.pEnabledFeatures = &deviceFeatures;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
		createInfo.ppEnabledExtensionNames = deviceExtensions.data();

		if (enableValidationLayers)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
			createInfo.enabledLayerCount = 0;

		VkResult vk_result = vkCreateDevice(vkPhysicalDevice, &createInfo, nullptr, &vkLogicalDevice);

		IS_VK_SUCCESS(vk_result, "Failed to Create Logical Device!");

		vkGetDeviceQueue(vkLogicalDevice, indices.presentFamily, 0, &vkPresentationQueue);
		vkGetDeviceQueue(vkLogicalDevice, indices.graphicsFamily, 0, &vkGraphicsQueue);

		return vk_result;
	}

	VkResult VulkanRenderer::CreateSwapChain()
	{
		SwapChainSupportDetails swapChainSupport = QuerySwapChainSupport(vkPhysicalDevice);

		VkSurfaceFormatKHR surfaceFormat = ChooseSwapSurfaceFormat(swapChainSupport.formats);
		VkPresentModeKHR presentMode = ChooseSwapPresentMode(swapChainSupport.presentModes);
		VkExtent2D extent = ChooseSwapExtent(swapChainSupport.capabilities);

		uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
		if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount)
			imageCount = swapChainSupport.capabilities.maxImageCount;

		VkSwapchainCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		createInfo.surface = vkSurfaceKHR;
		createInfo.minImageCount = imageCount;
		createInfo.imageFormat = surfaceFormat.format;
		vkSwapChainImageFormat = surfaceFormat.format;
		createInfo.imageColorSpace = surfaceFormat.colorSpace;
		createInfo.imageExtent = extent;
		vkSwapChainExtent = extent;
		createInfo.imageArrayLayers = 1;
		createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

		QueueFamilyIndices indices = FindQueueFamilies(vkPhysicalDevice);
		uint32_t queueFamilyIndices[] = { (uint32_t)indices.graphicsFamily, (uint32_t)indices.presentFamily };

		if (indices.graphicsFamily != indices.presentFamily)
		{
			createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
			createInfo.queueFamilyIndexCount = 2;
			createInfo.pQueueFamilyIndices = queueFamilyIndices;
		}
		else
		{
			createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
			createInfo.queueFamilyIndexCount = 0;
			createInfo.pQueueFamilyIndices = nullptr;
		}

		createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
		createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		createInfo.presentMode = presentMode;
		createInfo.clipped = VK_TRUE;
		createInfo.oldSwapchain = VK_NULL_HANDLE;

		VkResult vk_result = vkCreateSwapchainKHR(vkLogicalDevice, &createInfo, nullptr, &vkSwapChain);

		IS_VK_SUCCESS(vk_result, "Failed to Create Swap Chain!");

		vkGetSwapchainImagesKHR(vkLogicalDevice, vkSwapChain, &imageCount, nullptr);
		if (imageCount != 0)
		{
			vkSwapChainImages.resize(imageCount);
			vkGetSwapchainImagesKHR(vkLogicalDevice, vkSwapChain, &imageCount, vkSwapChainImages.data());
		}

		return vk_result;
	}

	void VulkanRenderer::CleanupSwapChain()
	{
		for (size_t i = 0; i < vkSwapChainFrameBuffers.size(); i++)
			vkDestroyFramebuffer(vkLogicalDevice, vkSwapChainFrameBuffers[i], nullptr);

		vkFreeCommandBuffers(vkLogicalDevice, vkCommandPool, static_cast<uint32_t>(vkCommandBuffers.size()), vkCommandBuffers.data());
		vkDestroyPipeline(vkLogicalDevice, vkGraphicsPipeline, nullptr);
		vkDestroyPipelineLayout(vkLogicalDevice, vkPipelineLayout, nullptr);
		vkDestroyRenderPass(vkLogicalDevice, vkRenderPass, nullptr);

		for (size_t i = 0; i < vkSwapChainImageViews.size(); i++)
			vkDestroyImageView(vkLogicalDevice, vkSwapChainImageViews[i], nullptr);

		vkDestroySwapchainKHR(vkLogicalDevice, vkSwapChain, nullptr);
	}

	VkResult VulkanRenderer::ReCreateSwapChain()
	{
		VkResult vk_result;
		vkDeviceWaitIdle(vkLogicalDevice);

		CleanupSwapChain();

		vk_result = CreateSwapChain();
		vk_result = CreateImageViews();
		vk_result = CreateRenderPass();
		vk_result = CreateGraphicsPipeline();
		vk_result = CreateFrameBuffers();
		vk_result = CreateCommandBuffers();

		return vk_result;
	}

	VkResult VulkanRenderer::CreateImageViews()
	{
		VkResult vk_result;
		vkSwapChainImageViews.resize(vkSwapChainImages.size());

		for (size_t i = 0; i < vkSwapChainImages.size(); i++)
		{
			VkImageViewCreateInfo createInfo = {};
			createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			createInfo.image = vkSwapChainImages[i];
			createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			createInfo.format = vkSwapChainImageFormat;
			createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			createInfo.subresourceRange.baseMipLevel = 0;
			createInfo.subresourceRange.levelCount = 1;
			createInfo.subresourceRange.baseArrayLayer = 0;
			createInfo.subresourceRange.layerCount = 1;

			vk_result = vkCreateImageView(vkLogicalDevice, &createInfo, nullptr, &vkSwapChainImageViews[i]);

			IS_VK_SUCCESS(vk_result, "Failed to Create Image Views!");
		}

		return vk_result;
	}

	SwapChainSupportDetails VulkanRenderer::QuerySwapChainSupport(VkPhysicalDevice _device)
	{
		SwapChainSupportDetails details;

		VkResult vk_result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_device, vkSurfaceKHR, &details.capabilities);

		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(_device, vkSurfaceKHR, &formatCount, details.formats.data());
		if (formatCount != 0)
		{
			details.formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(_device, vkSurfaceKHR, &formatCount, details.formats.data());
		}

		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(_device, vkSurfaceKHR, &presentModeCount, nullptr);
		if (presentModeCount != 0)
		{
			details.presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(_device, vkSurfaceKHR, &presentModeCount, details.presentModes.data());
		}

		return details;
	}

	VkResult VulkanRenderer::CreateVulkanWindowSurface()
	{
		VkResult vk_result = glfwCreateWindowSurface(vkInstance, glfwWindow, nullptr, &vkSurfaceKHR);

		IS_VK_SUCCESS(vk_result, "Failed to Create Window Surface!");

		return vk_result;
	}

	VkResult VulkanRenderer::CreateGraphicsPipeline()
	{
		VkShaderModule vertShaderModule;
		auto vertShaderCode = ReadShaderFile("vert.spv");
		vertShaderModule = CreateShaderModule(vertShaderCode);

		VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
		vertShaderStageInfo.module = vertShaderModule;
		vertShaderStageInfo.pName = "main";

		VkShaderModule fragShaderModule;
		auto fragShaderCode = ReadShaderFile("frag.spv");
		fragShaderModule = CreateShaderModule(fragShaderCode);

		VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragShaderModule;
		fragShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

		VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

		auto bindingDescription = VkVertex::GetBindingDescription();
		auto attributeDescriptions = VkVertex::GetAttributeDescriptions();

		vertexInputInfo.vertexBindingDescriptionCount = 1;
		vertexInputInfo.pVertexBindingDescriptions = &bindingDescription;

		vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

		VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		inputAssembly.primitiveRestartEnable = VK_FALSE;

		VkViewport viewport = {};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)vkSwapChainExtent.width;
		viewport.height = (float)vkSwapChainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		VkRect2D scissor = {};
		scissor.offset = { 0,0 };
		scissor.extent = vkSwapChainExtent;

		VkPipelineViewportStateCreateInfo viewportState = {};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = &viewport;
		viewportState.scissorCount = 1;
		viewportState.pScissors = &scissor;

		VkPipelineRasterizationStateCreateInfo rasterizer = {};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;
		rasterizer.rasterizerDiscardEnable = VK_FALSE;
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
		rasterizer.depthBiasEnable = VK_FALSE;
		rasterizer.depthBiasConstantFactor = 0.0f;
		rasterizer.depthBiasClamp = 0.0f;
		rasterizer.depthBiasSlopeFactor = 0.0f;

		VkPipelineMultisampleStateCreateInfo multisampling = {};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisampling.minSampleShading = 1.0f;
		multisampling.pSampleMask = nullptr;
		multisampling.alphaToCoverageEnable = VK_FALSE;
		multisampling.alphaToOneEnable = VK_FALSE;

		VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;
		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO;
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;

		VkPipelineColorBlendStateCreateInfo colorBlending = {};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.logicOp = VK_LOGIC_OP_COPY;
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f;
		colorBlending.blendConstants[1] = 0.0f;
		colorBlending.blendConstants[2] = 0.0f;
		colorBlending.blendConstants[3] = 0.0f;

		VkDynamicState dynamicStates[] = { VK_DYNAMIC_STATE_VIEWPORT,VK_DYNAMIC_STATE_LINE_WIDTH };
		VkPipelineDynamicStateCreateInfo dynamicState = {};
		dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamicState.dynamicStateCount = 2;
		dynamicState.pDynamicStates = dynamicStates;

		VkDescriptorSetLayout setLayouts[] = { vkDescriptorSetLayout };
		VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 1;
		pipelineLayoutInfo.pSetLayouts = setLayouts;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = 0;

		VkResult vk_result = vkCreatePipelineLayout(vkLogicalDevice, &pipelineLayoutInfo, nullptr, &vkPipelineLayout);

		IS_VK_SUCCESS(vk_result, "Failed to Create Pipeline Layout");

		VkGraphicsPipelineCreateInfo pipelineInfo = {};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineInfo.stageCount = 2;
		pipelineInfo.pStages = shaderStages;
		pipelineInfo.pVertexInputState = &vertexInputInfo;
		pipelineInfo.pInputAssemblyState = &inputAssembly;
		pipelineInfo.pViewportState = &viewportState;
		pipelineInfo.pRasterizationState = &rasterizer;
		pipelineInfo.pMultisampleState = &multisampling;
		pipelineInfo.pDepthStencilState = nullptr;
		pipelineInfo.pColorBlendState = &colorBlending;
		pipelineInfo.pDynamicState = nullptr;
		pipelineInfo.layout = vkPipelineLayout;
		pipelineInfo.renderPass = vkRenderPass;
		pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;
		pipelineInfo.basePipelineIndex = -1;

		vk_result = vkCreateGraphicsPipelines(vkLogicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &vkGraphicsPipeline);

		IS_VK_SUCCESS(vk_result, "Failed to Create Graphics Pipeline");

		vkDestroyShaderModule(vkLogicalDevice, vertShaderModule, nullptr);
		vkDestroyShaderModule(vkLogicalDevice, fragShaderModule, nullptr);

		return vk_result;
	}

	std::vector<char> VulkanRenderer::ReadShaderFile(const std::string& _filename)
	{
		std::ifstream file(_filename, std::ios::ate | std::ios::binary);
		if (!file.is_open())
			throw std::runtime_error("Failed to Open: " + _filename);

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	VkShaderModule	VulkanRenderer::CreateShaderModule(const std::vector<char>& code)
	{
		VkShaderModuleCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		VkShaderModule shaderModule;
		VkResult vk_result = vkCreateShaderModule(vkLogicalDevice, &createInfo, nullptr, &shaderModule);
		IS_VK_SUCCESS(vk_result, "Failed to Create Shader Module");

		return shaderModule;
	}

	VkResult VulkanRenderer::CreateFrameBuffers()
	{
		VkResult vk_result;

		vkSwapChainFrameBuffers.resize(vkSwapChainImageViews.size());

		for (size_t i = 0; i < vkSwapChainImageViews.size(); i++)
		{
			VkImageView attachments[] = { vkSwapChainImageViews[i] };

			VkFramebufferCreateInfo frameBufferInfo = {};
			frameBufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			frameBufferInfo.renderPass = vkRenderPass;
			frameBufferInfo.attachmentCount = 1;
			frameBufferInfo.pAttachments = attachments;
			frameBufferInfo.width = vkSwapChainExtent.width;
			frameBufferInfo.height = vkSwapChainExtent.height;
			frameBufferInfo.layers = 1;

			vk_result = vkCreateFramebuffer(vkLogicalDevice, &frameBufferInfo, nullptr, &vkSwapChainFrameBuffers[i]);

			IS_VK_SUCCESS(vk_result, "Failed to Create FrameBuffer!");
		}

		return vk_result;
	}

	VkResult VulkanRenderer::CreateCommandPool()
	{
		QueueFamilyIndices queueFamilyIndices = FindQueueFamilies(vkPhysicalDevice);

		VkCommandPoolCreateInfo poolInfo = {};
		poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
		poolInfo.flags = 0;

		VkResult vk_result = vkCreateCommandPool(vkLogicalDevice, &poolInfo, nullptr, &vkCommandPool);

		IS_VK_SUCCESS(vk_result, "Failed to Create Command Pool");

		return vk_result;
	}

	VkResult VulkanRenderer::CreateCommandBuffers()
	{
		vkCommandBuffers.resize(vkSwapChainFrameBuffers.size());

		VkCommandBufferAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.commandPool = vkCommandPool;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandBufferCount = (uint32_t)vkCommandBuffers.size();

		VkResult vk_result = vkAllocateCommandBuffers(vkLogicalDevice, &allocInfo, vkCommandBuffers.data());

		IS_VK_SUCCESS(vk_result, "Failed to Allocate Command Buffers!");

		for (size_t i = 0; i < vkCommandBuffers.size(); i++)
		{
			VkCommandBufferBeginInfo beginInfo = {};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
			beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
			beginInfo.pInheritanceInfo = nullptr;
			vkBeginCommandBuffer(vkCommandBuffers[i], &beginInfo);

			VkRenderPassBeginInfo renderPassInfo = {};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = vkRenderPass;
			renderPassInfo.framebuffer = vkSwapChainFrameBuffers[i];

			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = vkSwapChainExtent;

			VkClearValue clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };
			renderPassInfo.clearValueCount = 1;
			renderPassInfo.pClearValues = &clearColor;

			vkCmdBeginRenderPass(vkCommandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
			vkCmdBindPipeline(vkCommandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, vkGraphicsPipeline);

			VkBuffer vertexBuffers[] = { vkVertexBuffer };
			VkDeviceSize offsets[] = { 0 };
			vkCmdBindVertexBuffers(vkCommandBuffers[i], 0, 1, vertexBuffers, offsets);

			vkCmdBindIndexBuffer(vkCommandBuffers[i], vkIndexBuffer, 0, VK_INDEX_TYPE_UINT16);
			vkCmdBindDescriptorSets(vkCommandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, vkPipelineLayout, 0, 1, &vkDescriptorSets[i], 0, nullptr);

			std::vector<Entity*> entities = HazeEngine::Instance()->GetEntityManager()->FindEntitiesByType<Model>();
			for (int j = 0; j < entities.size(); j++)
				vkCmdDrawIndexed(vkCommandBuffers[i], static_cast<uint16_t>(entities[j]->GetComponent<Model>()->GetIndices()->size()), 1, 0, 0, 0);
			//vkCmdDraw(vkCommandBuffers[i], static_cast<uint32_t>(vertices.size()), 1, 0, 0);

			vkCmdEndRenderPass(vkCommandBuffers[i]);

			vk_result = vkEndCommandBuffer(vkCommandBuffers[i]);
			IS_VK_SUCCESS(vk_result, "Failed to Record Command Buffer!");
		}

		return vk_result;
	}

	VkResult VulkanRenderer::CreateDescriptorSetLayout()
	{
		VkResult vk_result;

		VkDescriptorSetLayoutBinding uboLayoutBinding = {};
		uboLayoutBinding.binding = 0;
		uboLayoutBinding.descriptorCount = 1;
		uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		uboLayoutBinding.pImmutableSamplers = nullptr;
		uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;

		VkDescriptorSetLayoutCreateInfo layoutInfo = {};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = 1;
		layoutInfo.pBindings = &uboLayoutBinding;

		vk_result = vkCreateDescriptorSetLayout(vkLogicalDevice, &layoutInfo, nullptr, &vkDescriptorSetLayout);
		IS_VK_SUCCESS(vk_result, "Failed to Create Descriptor Set Layout");

		return vk_result;
	}

	VkResult VulkanRenderer::CreateRenderPass()
	{
		VkAttachmentDescription colorAttachment = {};
		colorAttachment.format = vkSwapChainImageFormat;
		colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
		colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
		colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

		VkAttachmentReference colorAttachmentRef = {};
		colorAttachmentRef.attachment = 0;
		colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		VkSubpassDescription subpass = {};
		subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
		subpass.colorAttachmentCount = 1;
		subpass.pColorAttachments = &colorAttachmentRef;

		VkRenderPassCreateInfo renderPassInfo = {};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		renderPassInfo.attachmentCount = 1;
		renderPassInfo.pAttachments = &colorAttachment;
		renderPassInfo.subpassCount = 1;
		renderPassInfo.pSubpasses = &subpass;

		VkSubpassDependency dependency = {};
		dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
		dependency.dstSubpass = 0;
		dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.srcAccessMask = 0;
		dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

		renderPassInfo.dependencyCount = 1;
		renderPassInfo.pDependencies = &dependency;

		VkResult vk_result = vkCreateRenderPass(vkLogicalDevice, &renderPassInfo, nullptr, &vkRenderPass);

		IS_VK_SUCCESS(vk_result, "Failed to Create Render Pass");

		return vk_result;
	}

	std::vector<const char*> VulkanRenderer::GetRequiredExtensions()
	{
		std::vector<const char*> extensions;

		unsigned int glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		for (unsigned int i = 0; i < glfwExtensionCount; i++)
			extensions.push_back(glfwExtensions[i]);

		if (enableValidationLayers)
			extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);

		return extensions;
	}

	QueueFamilyIndices VulkanRenderer::FindQueueFamilies(VkPhysicalDevice _device)
	{
		QueueFamilyIndices indices;

		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(_device, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(_device, &queueFamilyCount, queueFamilies.data());

		VkBool32 presentSupport = false;

		int i = 0;
		for (const auto& queueFamily : queueFamilies)
		{

			vkGetPhysicalDeviceSurfaceSupportKHR(_device, i, vkSurfaceKHR, &presentSupport);

			if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				indices.graphicsFamily = i;

			if (queueFamily.queueCount > 0 && presentSupport)
				indices.presentFamily = i;

			if (indices.isComplete())
				break;

			i++;
		}

		return indices;
	}

	void VulkanRenderer::SetupDebugCallback()
	{
		if (!enableValidationLayers)
			return;

		VkDebugReportCallbackCreateInfoEXT createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		createInfo.flags = VK_DEBUG_REPORT_DEBUG_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
		createInfo.pfnCallback = DebugCallback;

		VkResult vk_result = CreateDebugReportCallbackEXT(vkInstance, &createInfo, nullptr, &vkDebugCallback);
	}

	bool VulkanRenderer::CheckValidationLayerSupport()
	{
		uint32_t layerCount;

		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char * layerName : validationLayers)
		{
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound)
				return false;
		}

		return true;
	}

	VkResult VulkanRenderer::CreateDebugReportCallbackEXT(VkInstance _instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback)
	{
		auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(_instance, "vkCreateDebugReportCallbackEXT");
		if (func != nullptr) {
			return func(_instance, pCreateInfo, pAllocator, pCallback);
		}
		else {
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
	}

	void VulkanRenderer::DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator)
	{
		auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
		if (func != nullptr) {
			func(instance, callback, pAllocator);
		}
	}

	VKAPI_ATTR VkBool32 VKAPI_CALL VulkanRenderer::DebugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData)
	{
		std::cerr << "Validation Layer: " << msg << std::endl;
		return VK_FALSE;
	}

	void VulkanRenderer::CreateGlfwWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //Create Window without OpenGL context
		glfwVidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		vkWindowHeight = glfwVidMode->height;
		vkWindowWidth = glfwVidMode->width;
		glfwWindow = glfwCreateWindow(glfwVidMode->width, glfwVidMode->height, "Vulkan Renderer Window", nullptr, nullptr);

		glfwSetWindowUserPointer(glfwWindow, this);
		glfwSetWindowSizeCallback(glfwWindow, OnWindowResized);
	}

	void VulkanRenderer::OnWindowResized(GLFWwindow* _window, int _width, int _height)
	{
		if (_width == 0 || _height == 0)
			return;

		VulkanRenderer* app = reinterpret_cast<VulkanRenderer*>(glfwGetWindowUserPointer(_window));
		app->ReCreateSwapChain();
	}

	float VulkanRenderer::GetAspectRatio()
	{
		return glfwVidMode->width / glfwVidMode->height;
	}
}

