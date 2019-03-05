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

		forward = normalize(vec3(0.0f, 0.0f, 1.0f));
		right = normalize(vec3(1.0f, 0.0f, 0.0f));
		up = normalize(vec3(0.0f, 1.0f, 0.0f));
	}

	Transform::~Transform()
	{

	}

	void Transform::Translate(vec3 _direction)
	{
		mat4 t = translate(mat4(1.0f), _direction);
		worldPosition += vec3(t[3]);
	}

	void Transform::Translate(float _x, float _y, float _z)
	{
		vec3 direction = vec3();
		direction.x += _x;
		direction.y += _y;
		direction.z += _z;
		Translate(direction);
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

	void Transform::Rotate(float _angleByRadians, vec3 _rotation)
	{
		worldRotation = rotate(worldRotation, _angleByRadians, _rotation);
		rotationMatrix = rotate(rotationMatrix, _angleByRadians, _rotation);
	}

	void Transform::Rotate(float _angleByRadians, float _x, float _y, float _z)
	{
		quat toRotation(_w, _x, _y, _z);
		worldRotation = inverse(worldRotation) * toRotation * worldRotation;
		vec3 rotation = vec3(_x, _y, _z);
		worldRotation = rotate(worldRotation, _angleByRadians, rotation);
		rotationMatrix = rotate(rotationMatrix, _angleByRadians, rotation);
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

	mat4 Transform::CalculateTranslationMatrix()
	{
		translationMatrix = translate(mat4(1.0), worldPosition);
		return translationMatrix;
	}

	mat4 Transform::CalculateRotationMatrix()
	{
		return rotationMatrix;
	}

	void Transform::CalculateFront()
	{
		forward.x = cos(radians(pitch)) * sin(radians(yaw));
		forward.y = sin(radians(pitch));
		forward.z = cos(radians(pitch)) * cos(radians(yaw));
		forward = normalize(forward);
	}

	void Transform::CalculateRight()
	{
		if (up.length() == NAN)
			up = vec3(0.0f, 1.0f, 0.0f);

		right = cross(forward, vec3(0,1,0));
	}

	void Transform::CalculateUp()
	{
		if (right.length() <= 0.0f)
			right = vec3(1.0f, 0.0f, 0.0f);

		up = cross(forward, right);
	}

}
