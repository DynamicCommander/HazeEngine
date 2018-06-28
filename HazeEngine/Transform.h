#pragma once

#include "stdafx.h"

#include "Component.h"

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\quaternion.hpp>
using namespace glm;

#include <vector>

namespace Haze_Engine
{

	class Transform : public ECS::Component
	{
		CLASS_DEFINITION(Transform)

	public:
		Transform();
		~Transform();

		vec3 GetLocalPosition()	{ return localPosition; }
		vec3 GetWorldPosition() { return worldPosition; }

		void LocalPosition(vec3 _localPosition) { localPosition = _localPosition; }
		void LocalPosition(float _x, float _y, float _z) { localPosition = vec3(_x,_y,_z); }
		void WorldPosition(vec3 _worldPosition) { worldPosition = _worldPosition; }
		void WorldPosition(float _x, float _y, float _z) { worldPosition = vec3(_x, _y, _z); }
		
		quat GetLocalRotation()	{ return localRotation; }
		quat GetWorldRotation() { return worldRotation; }

		void LocalRotation(vec3 _localRotation) { localRotation = _localRotation; }
		void LocalRotation(float _x, float _y, float _z) { localRotation = vec3(_x, _y, _z); }
		void WorldRotation(vec3 _worldRotation) { worldRotation = _worldRotation; }
		void WorldRotation(float _x, float _y, float _z) { worldRotation = vec3(_x, _y, _z); }

		vec3 GetLocalScale()	{ return localScale; }
		vec3 GetWorldScale()	{ return worldScale; }

		void LocalScale(vec3 _localScale) { localScale = _localScale; }
		void LocalScale(float _x, float _y, float _z) { localScale = vec3(_x, _y, _z); }
		void WorldScale(vec3 _worldScale) { worldScale = _worldScale; }
		void WorldScale(float _x, float _y, float _z) { worldScale = vec3(_x, _y, _z); }

		vec3 GetForward()	{ return forward; }
		vec3 GetRight()		{ return right; }
		vec3 GetUp()		{ return up; }

	private:

		vec3					localPosition;
		vec3					worldPosition;

		quat					localRotation;
		quat					worldRotation;

		vec3					localScale;
		vec3					worldScale;

		vec3					forward;
		vec3					right;
		vec3					up;

		Transform*				parent;
		std::vector<Transform*> children;
	};

}

