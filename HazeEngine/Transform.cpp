#include "stdafx.h"
#include "Transform.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(ECS::Component, Transform)

	Transform::Transform()
	{
		parent = nullptr;
		children = std::vector<Transform*>();

		localPosition = vec3(0.0f, 0.0f, 0.0f);
		worldPosition = vec3(0.0f, 0.0f, 0.0f);

		localRotation = quat(1.0f, 0.0f, 0.0f, 0.0f);
		worldRotation = quat(1.0f, 0.0f, 0.0f, 0.0f);

		localScale = vec3(0.0f, 0.0f, 0.0f);
		worldScale = vec3(0.0f, 0.0f, 0.0f);

		forward = vec3(0.0f, 0.0f, 1.0f);
		right =	vec3(1.0f, 0.0f, 0.0f);
		up = vec3(0.0f, 1.0f, 0.0f);
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
		worldRotation = _rotation + worldRotation;
	}

	void Transform::Rotate(float _x, float _y, float _z, float _w)
	{
		quat toRotation(_w, _x, _y, _z);
		worldRotation = toRotation + worldRotation;
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

	void Transform::CalculateFront()
	{
		float x = 2.0f * (worldRotation.x * worldRotation.z + worldRotation.w * worldRotation.y);
		float y = 2.0f * (worldRotation.y * worldRotation.z - worldRotation.w * worldRotation.x);
		float z = 1.0f - 2.0f * (worldRotation.x * worldRotation.x + worldRotation.y * worldRotation.y);
		forward = vec3(x, y, z);
	}

	void Transform::CalculateRight()
	{
		float x = -(1.0f - 2.0f * (worldRotation.y * worldRotation.y + worldRotation.z * worldRotation.z));
		float y = -(2.0f * (worldRotation.x * worldRotation.y + worldRotation.w * worldRotation.z));
		float z = -(2.0f *(worldRotation.x * worldRotation.z - worldRotation.w * worldRotation.y));
		right = vec3(x, y, z);
	}

	void Transform::CalculateUp()
	{
		float x = 2.0f * (worldRotation.x * worldRotation.y - worldRotation.w * worldRotation.z);
		float y = 1.0f - 2.0f * (worldRotation.x * worldRotation.z + worldRotation.z * worldRotation.z);
		float z = 2.0f * (worldRotation.y * worldRotation.z + worldRotation.w * worldRotation.x);
		up = vec3(x, y, z);
	}

}
