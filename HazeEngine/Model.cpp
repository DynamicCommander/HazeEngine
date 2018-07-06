#include "stdafx.h"
#include "Model.h"
#include "HazeCam.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(Component, Model)

	Model::~Model()
	{
	}

	mat4 Model::BuildMVPMatrix()
	{
		mat4 view = hazeEngine->GetCamera()->GetViewMatrix();
		mat4 proj = hazeEngine->GetCamera()->GetProjMatrix();
		modelViewProjection = proj * view * owner->GetComponent<Transform>().CalculateTranslationMatrix();
		return modelViewProjection;
	}
}
