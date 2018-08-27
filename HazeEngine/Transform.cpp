#include "stdafx.h"
#include "Transform.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(ECS::Component, Transform)

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

	void Transform::Rotate(float _angleByRadians, vec3 _rotation)
	{
		worldRotation = rotate(worldRotation, _angleByRadians, _rotation);
		rotationMatrix = rotate(rotationMatrix, _angleByRadians, _rotation);
	}

	void Transform::Rotate(float _angleByRadians, float _x, float _y, float _z)
	{
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
		static const vec3 z(0.0f, 0.0f, -1.0f);
		conjugate(worldRotation) * z;
	}

	void Transform::CalculateRight()
	{
		static const vec3 z(1.0f, 0.0f, 0.0f);
		conjugate(worldRotation) * right;
	}

	void Transform::CalculateUp()
	{
		static const vec3 z(0.0f, 1.0f, 0.0f);
		conjugate(worldRotation) * up;
	}

}
