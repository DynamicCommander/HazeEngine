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

	void Model::Initialize()
	{

	}

	void Model::Update(float _deltaTime)
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

	mat4 Model::BuildModelMatrix()
	{
		Transform* t = owner->GetComponent<Transform>();
		modelMatrix = t->GetTranslationMatrix() * t->GetRotationMatrix() * t->GetScaleMatrix();
		return modelMatrix;
	}
}
