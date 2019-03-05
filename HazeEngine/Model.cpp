#include "stdafx.h"
#include "Model.h"
#include "HazeCam.h"
#include "Haze_Functions_STD.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(Component, Model)

	Model::~Model()
	{
	}

	void Model::SetVertices(std::vector<Vertex>* _vertices)
	{ 
		vertices = _vertices; 
	}

	void Model::SetVertices(std::vector<VkVertex>* _vertices)
	{
		std::vector<Vertex> temp(_vertices->begin(), _vertices->end());
		SetVertices(&temp);
	}

	mat4 Model::BuildMVPMatrix()
	{
		Haze_Functions_STD::console("Model: ");
		Haze_Functions_STD::console(owner->GetComponent<Transform>().GetWorldPosition());
		mat4 view = HazeEngine::Instance()->GetCamera()->GetViewMatrix();
		mat4 proj = HazeEngine::Instance()->GetCamera()->GetProjMatrix();
		modelViewProjection = proj * view * owner->GetComponent<Transform>().CalculateTranslationMatrix();
		return modelViewProjection;
	}
}
