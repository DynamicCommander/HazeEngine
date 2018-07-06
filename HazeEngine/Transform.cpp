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
		normalize(worldRotation);
	}

	void Transform::Rotate(float _x, float _y, float _z)
	{
		worldRotation *= vec3(_x, _y, _z);
		normalize(worldRotation);
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
		rotationMatrix = rotate(rotationMatrix, radians(worldRotation.x), vec3(1.0f, 0.0f, 0.0f));
		rotationMatrix = rotate(rotationMatrix, radians(worldRotation.y), vec3(0.0f, 1.0f, 0.0f));
		rotationMatrix = rotate(rotationMatrix, radians(worldRotation.z), vec3(0.0f, 0.0f, 1.0f));
		return rotationMatrix;
	}

	void Transform::CalculateFront()
	{
		forward.x = cos(radians(yaw)) * cos(radians(pitch));
		forward.y = sin(radians(pitch));
		forward.z = sin(radians(yaw)) * cos(radians(pitch));
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
