#ifndef VKVERTEX_H
#define VKVERTEX_H

#include "Vertex.h"
#include <array>

namespace Vulkan_Renderer
{
	class VkVertex : public Haze_Engine::Vertex
	{
	public:
		VkVertex();
		VkVertex(vec3 _position, vec3 _color);
		~VkVertex();

		static VkVertexInputBindingDescription GetBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 2> GetAttributeDescriptions();
	};
}

#endif


