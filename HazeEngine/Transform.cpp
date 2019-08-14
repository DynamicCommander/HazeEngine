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
		if (_isWorld)
			worldRotation += quat(_rotation);
		else
			localRotation += quat(_rotation);

		isDirty = true;
	}

	void Transform::Rotate(float _x, float _y, float _z, bool _isWorld)
	{
		Rotate(vec3(_x, _y, _z), _isWorld);
		isDirty = true;
    }

	void Transform::Rotate(float _angleByRadians, vec3 _rotation, bool _isWorld)
	{
		if(_isWorld)
			worldRotation = rotate(worldRotation, _angleByRadians, _rotation);
		else
			localRotation = rotate(worldRotation, _angleByRadians, _rotation);

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
			rotationMatrix = glm::rotate(glm::mat4(1.0f), worldRotation.x, WORLD_RIGHT);
			rotationMatrix = glm::rotate(rotationMatrix, worldRotation.y, WORLD_RIGHT);
			rotationMatrix = glm::rotate(rotationMatrix, worldRotation.z, WORLD_RIGHT);
		}

		return rotationMatrix;
	}

	mat4 Transform::CalculateScaleMatrix()
	{
		if(isDirty)
		{
			scaleMatrix = glm::scale(glm::mat4(1.0f), worldScale);
		}

		return scaleMatrix;
	}

	void Transform::CalculateFront()
	{
		forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		forward.y = sin(glm::radians(pitch));
		forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		forward = glm::normalize(forward);
	}

}
