#include "stdafx.h"
#include "Transform.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(ECS::Component, Transform)

	Transform::Transform()
	{
		parent = nullptr;
		children = std::vector<Transform*>();
	}

	Transform::~Transform()
	{

	}

	void Transform::Translate(vec3 _direction)
	{
		worldPosition += _direction;
	}

	void Transform::Translate(float _x, float _y, float _z)
	{
		worldPosition.x += _x;
		worldPosition.y += _y;
		worldPosition.z += _z;
	}

	void Transform::Rotate(quat _rotation)
	{
		worldRotation = worldRotation * _rotation;
	}

	void Transform::Rotate(float _x, float _y, float _z, float _w)
	{
		worldRotation.x = worldRotation.x * _x;
		worldRotation.y = worldRotation.y * _y;
		worldRotation.z = worldRotation.z * _z;
		worldRotation.w = worldRotation.w * _w;
	}

	void Transform::Scale(vec3 _scale)
	{
		worldScale += _scale;
	}

	void Transform::Scale(float _x, float _y, float _z)
	{
		worldScale.x += _x;
		worldScale.y += _y;
		worldScale.z += _z;
	}

	vec3 Transform::CalculateFront()
	{
		glm::vec3 camFront;
		camFront.x = cos(glm::radians(worldRotation.x)) * sin(glm::radians(worldRotation.y));
		camFront.y = sin(glm::radians(worldRotation.x));
		camFront.z = cos(glm::radians(worldRotation.x)) * cos(glm::radians(worldRotation.y));
		camFront = glm::normalize(camFront);

		return camFront;
	}

	vec3 Transform::CalculateRight()
	{
		glm::vec3 camRight;
		camRight = vec3(sin(GetWorldRotation().y - 3.14 / 2.0f), 0, cos(GetWorldRotation().y - 3.14f / 2.0f));
		return camRight;
	}

	vec3 Transform::CalculateUp()
	{
		glm::vec3 camUp;
		camUp = cross(GetRight(), GetForward());
		return camUp;
	}

}
