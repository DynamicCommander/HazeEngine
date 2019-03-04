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

		localScale = vec3(1.0f, 1.0f, 1.0f);
		worldScale = vec3(1.0f, 1.0f, 1.0f);

		forward = normalize(worldPosition - vec3(0.0f, 0.0f, 0.0f));
		right = cross(forward, vec3(0.0f, 1.0f, 0.0f));
		up = cross(forward, right);
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
		quat toRotation = quat(_rotation);
		worldRotation *= inverse(worldRotation) * toRotation * worldRotation;
	}

	void Transform::Rotate(float _x, float _y, float _z)
	{
		//Rotate(vec3(_x, _y, _z));
	}

	void Transform::Rotate(float _x, float _y, float _z, float _w)
	{
		quat toRotation(_w, _x, _y, _z);
		worldRotation = inverse(worldRotation) * toRotation * worldRotation;
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
		forward.x = cos(radians(yaw)) * cos(radians(pitch));
		forward.y = sin(radians(pitch));
		forward.z = sin(radians(yaw)) * cos(radians(pitch));
	}

	void Transform::CalculateRight()
	{
		if (up.length() == NAN)
			up = vec3(0.0f, 1.0f, 0.0f);

		right = cross(forward, up);
	}

	void Transform::CalculateUp()
	{
		if (right.length() <= 0.0f)
			right = vec3(1.0f, 0.0f, 0.0f);

		up = cross(forward, right);
	}

}
