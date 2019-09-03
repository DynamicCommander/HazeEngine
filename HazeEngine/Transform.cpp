#include "stdafx.h"
#include "Transform.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(ECS::Component, Transform)

	Transform::~Transform()
	{

	}

	void Transform::Initialize()
	{

	}

	void Transform::Update(float _deltaTime)
	{

	}

	void Transform::Translate(vec3 _direction, bool _isWorld)
	{
		if (_isWorld)
			worldPosition += _direction;
		else
			localPosition += _direction;

		isDirty = true;
	}

	void Transform::Translate(float _x, float _y, float _z, bool _isWorld)
	{
		Translate(vec3(_x,_y,_z), _isWorld);
		isDirty = true;
	}

	void Transform::Rotate(vec3 _rotation, bool _isWorld)
	{
		if()
		if (_isWorld)
			worldRotation += _rotation;
		else
			localRotation += _rotation;

		isDirty = true;
	}

	void Transform::Rotate(float _x, float _y, float _z, bool _isWorld)
	{
		Rotate(vec3(_x, _y, _z), _isWorld);
		isDirty = true;
    }

	void Transform::Rotate(float _radians, vec3 _aroundAxis)
	{
		rotationMatrix = glm::rotate(rotationMatrix, _radians, _aroundAxis);
		isDirty = true;
	}

	void Transform::Scale(vec3 _scale)
	{
		worldScale += _scale;
		isDirty = true;
	}

	void Transform::Scale(float _x, float _y, float _z)
	{
		Scale(vec3(_x, _y, _z));
		isDirty = true;
	}

	mat4 Transform::CalculateTranslationMatrix()
	{
		if (isDirty)
			translationMatrix = glm::translate(glm::mat4(1.0f), worldPosition);

		return translationMatrix;
	}

	mat4 Transform::CalculateRotationMatrix()
	{
		if(isDirty)
		{
			CalculateAxis();
			isDirty = false;
		}

		return rotationMatrix;
	}

	mat4 Transform::CalculateScaleMatrix()
	{
		if(isDirty)
			scaleMatrix = glm::scale(glm::mat4(1.0f), worldScale);

		return scaleMatrix;
	}

	void Transform::CalculateAxis()
	{
		worldRotation = glm::inverse(rotationMatrix) * glm::vec4(0, 0, -1, 1);
		right = glm::inverse(rotationMatrix) * glm::vec4(1, 0, 0, 1);
		up = glm::inverse(rotationMatrix) * glm::vec4(0, 1, 0, 1);
	}

}
