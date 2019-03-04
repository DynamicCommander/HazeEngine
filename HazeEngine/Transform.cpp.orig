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

		forward = normalize(worldPosition - vec3(0, 0, 0));
		right = cross(forward, vec3(0, 1, 0));
		up = cross(forward, right);

>>>>>>> Stashed changes
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

	void Transform::Rotate(vec3 _rotation, float _angle)
	{
<<<<<<< Updated upstream
		worldRotation = _rotation + worldRotation;
=======
		worldRotation.w += cosf(_angle / 2);
		worldRotation.x = _rotation.x * sinf(_angle / 2);
		worldRotation.y = _rotation.y * sinf(_angle / 2);
		worldRotation.z = _rotation.z * sinf(_angle / 2);
>>>>>>> Stashed changes
	}

	void Transform::Rotate(float _x, float _y, float _z, float _w)
	{
<<<<<<< Updated upstream
		quat toRotation(_w, _x, _y, _z);
		worldRotation = toRotation + worldRotation;
=======
		worldRotation.x = worldRotation.x + _x;
		worldRotation.y = worldRotation.y + _y;
		worldRotation.z = worldRotation.z + _z;
		worldRotation.w = worldRotation.w + _w;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		float x = 2.0f * (worldRotation.x * worldRotation.z + worldRotation.w * worldRotation.y);
		float y = 2.0f * (worldRotation.y * worldRotation.z - worldRotation.w * worldRotation.x);
		float z = 1.0f - 2.0f * (worldRotation.x * worldRotation.x + worldRotation.y * worldRotation.y);
		forward = vec3(x, y, z);
=======
		forward.x = cos(glm::radians(yaw)) * sin(glm::radians(pitch));
		forward.y = sin(glm::radians(pitch));
		forward.z = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		forward = glm::normalize(forward);
>>>>>>> Stashed changes
	}

	void Transform::CalculateRight()
	{
<<<<<<< Updated upstream
		float x = -(1.0f - 2.0f * (worldRotation.y * worldRotation.y + worldRotation.z * worldRotation.z));
		float y = -(2.0f * (worldRotation.x * worldRotation.y + worldRotation.w * worldRotation.z));
		float z = -(2.0f *(worldRotation.x * worldRotation.z - worldRotation.w * worldRotation.y));
		right = vec3(x, y, z);
=======
		right = vec3(sin(GetWorldRotation().y - 3.14 / 2.0f), 0, cos(GetWorldRotation().y - 3.14f / 2.0f));
>>>>>>> Stashed changes
	}

	void Transform::CalculateUp()
	{
<<<<<<< Updated upstream
		float x = 2.0f * (worldRotation.x * worldRotation.y - worldRotation.w * worldRotation.z);
		float y = 1.0f - 2.0f * (worldRotation.x * worldRotation.z + worldRotation.z * worldRotation.z);
		float z = 2.0f * (worldRotation.y * worldRotation.z + worldRotation.w * worldRotation.x);
		up = vec3(x, y, z);
=======
		up = cross(GetRight(), GetForward());
>>>>>>> Stashed changes
	}

}
