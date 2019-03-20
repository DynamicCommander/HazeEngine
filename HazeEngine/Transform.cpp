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
		translationMatrix = translate(translationMatrix, _direction);
		worldPosition = translationMatrix[3];
		/*
		mat4 t = translate(mat4(1.0f), _direction);
		worldPosition += vec3(t[3]);
		*/
	}

	void Transform::Translate(float _x, float _y, float _z)
	{
		Translate(vec3(_x,_y,_z));
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

	void Transform::Scale(vec3 _scale)
	{
		scaleMatrix = scale(scaleMatrix, _scale);
		worldScale += _scale;
	}

	void Transform::Scale(float _x, float _y, float _z)
	{
		Scale(vec3(_x, _y, _z));
	}

	mat4 Transform::CalculateRotationMatrix()
	{
		rotationMatrix = mat4(worldRotation);
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
		right = normalize(cross(forward, vec3(0,1.0f,0)));
	}

	void Transform::CalculateUp()
	{
		up = normalize(cross(right, forward));
	}

}
