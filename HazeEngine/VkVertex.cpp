#include "stdafx.h"
#include "VkVertex.h"

namespace Vulkan_Renderer
{
	VkVertex::VkVertex()
	{
	}

	VkVertex::VkVertex(vec3 _position, vec3 _color)
	{
		position = _position;
		_color = _color;
	}

	VkVertex::~VkVertex()
	{
	}

	VkVertexInputBindingDescription VkVertex::GetBindingDescription()
	{
		VkVertexInputBindingDescription bindingDescription = {};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(VkVertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		return bindingDescription;
	}

	std::array<VkVertexInputAttributeDescription, 2> VkVertex::GetAttributeDescriptions()
	{
		std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions = {};

		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(VkVertex, position);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(VkVertex, color);

		return attributeDescriptions;
	}
}
