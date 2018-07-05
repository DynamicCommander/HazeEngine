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

		localRotation = vec3(0.0f, 0.0f, 0.0f);
		worldRotation = vec3(0.0f, 0.0f, 0.0f);

		localScale = vec3(1.0f, 1.0f, 1.0f);
		worldScale = vec3(1.0f, 1.0f, 1.0f);

		forward = vec3(0.0f, 0.0f, 1.0f);
		right = vec3(1.0f, 0.0f, 0.0f);
		up = vec3(0.0f, 1.0f, 0.0f);

		yaw = 0.0f;
		pitch = 0.0f;
		roll = 0.0f;
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

	void Transform::Rotate(vec3 _rotation)
	{
		worldRotation *= _rotation;
	}

	void Transform::Rotate(float _x, float _y, float _z)
	{
		worldRotation *= vec3(_x, _y, _z);
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
		forward.x = -sin(radians(yaw)) * cos(radians(pitch));
		forward.y = sin(radians(pitch));
		forward.z = cos(radians(yaw)) * cos(radians(pitch));
		forward = normalize(forward);
	}

	void Transform::CalculateRight()
	{
		right = normalize(cross(forward, up));
	}

	void Transform::CalculateUp()
	{
		up = -normalize(cross(right, forward));
	}

}
