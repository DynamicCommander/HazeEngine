#ifndef MODEL_H
#define MODEL_H

#include "HazeEngine.h"
#include "VulkanRenderer.h"

#include "Component.h"

#include <vector>

namespace Haze_Engine
{
	class Model : public ECS::Component
	{

		CLASS_DECLARATION(Model);

	public:

		Model(Active_Renderer _rendererType, Entity* _owner) : Component(_owner) 
		{ 
			owner = _owner;
			if (Haze_Functions_STD::null(&owner->GetComponent<Transform>()))
			{
				Transform t = Transform(owner);
				owner->AddComponent<Transform>(&t);
			}
			rendererType = _rendererType;
		};

		~Model();

		std::vector<Vertex> GetVertices() { return vertices; }
		void SetVertices(std::vector<Vertex> _vertices) { vertices = _vertices; }

		std::vector<uint16_t> GetIndices() { return indices; }
		void SetIndices(std::vector<uint16_t> _indices) { indices = _indices; }

		mat4 BuildMVPMatrix();

	private:

		Active_Renderer rendererType;

		std::vector<Vertex> vertices;
		std::vector<uint16_t> indices;

		mat4 modelViewProjection;
	};
}
#endif

