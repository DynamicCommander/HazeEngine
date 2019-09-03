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

	public:

		Model(Active_Renderer _rendererType) : Component()
		{
			rendererType = _rendererType;
		}

		Model(Active_Renderer _rendererType, Entity* _owner) : Component(_owner)
		{
			owner = _owner;
			if (Haze_Functions_STD::null(owner->GetComponent<Transform>()))
			{
				Transform* t = new Transform(owner);
				owner->AddComponent<Transform>(t);
			}
			rendererType = _rendererType;
			vertices = new std::vector<Vertex>();
			indices = new std::vector<uint16_t>();
			HazeEngine::Instance()->GetVulkanRenderer()->SetVkRebuildBuffers(true);
		};

		~Model();

		void Initialize();
		void Update(float _deltaTime);

		std::vector<Vertex>* GetVertices() { return vertices; }
		void SetVertices(std::vector<Vertex> *_vertices);
		void SetVertices(std::vector<VkVertex> *_vertices);

		std::vector<uint16_t>* GetIndices() { return indices; }
		void SetIndices(std::vector<uint16_t> *_indices) { indices = _indices; }

		mat4 GetModelMatrix() { return modelMatrix;  }
		mat4 BuildModelMatrix();

	private:
		CLASS_DECLARATION(Model)

		Active_Renderer rendererType;

		std::vector<Vertex> *vertices;
		std::vector<uint16_t> *indices;

		mat4 modelMatrix;
	};
}
#endif

