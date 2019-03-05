#pragma once

#include "stdafx.h"

#include "Component.h"

#include "Haze_Functions_STD.h"

#include <vector>

namespace Haze_Engine
{

	class Transform : public ECS::Component
	{
	public:

		Transform(ECS::Entity* _owner) : Component(_owner) 
		{ 
			parent = nullptr;
			children = std::vector<Transform*>();

			localPosition = vec3(0.0f, 0.0f, 0.0f);
			worldPosition = vec3(0.0f, 0.0f, 0.0f);

			localRotation = vec3(0.0f, 0.0f, 0.0f);
			worldRotation = vec3(0.0f, 0.0f, 0.0f);

			localScale = vec3(1.0f, 1.0f, 1.0f);
			worldScale = vec3(1.0f, 1.0f, 1.0f);

			forward = vec3(0.0f, 0.0f, -1.0f);
			right = vec3(1.0f, 0.0f, 0.0f);
			up = vec3(0.0f, 1.0f, 0.0f);

			translationMatrix = mat4();
			rotationMatrix = mat4(1.0f);

			yaw = 0.0f;
			pitch = 0.0f;
			roll = 0.0f;
		};

		~Transform();

		void Translate(vec3 _direction);
		void Translate(float _x, float _y, float _z);

		void Rotate(vec3 _rotation);
		void Rotate(float _x, float _y, float _z);
		void Rotate(float _x, float _y, float _z, float _w);

		void Rotate(float _angleByRadians, vec3 _rotationAxis);
		void Rotate(float _angleByRadians, float _x, float _y, float _z);

		void Scale(vec3 _scale);
		void Scale(float _x, float _y, float _z);

		vec3 GetLocalPosition()	{ return localPosition; }
		vec3 GetWorldPosition() { return worldPosition; }

		void LocalPosition(vec3 _localPosition) { localPosition = _localPosition; }
		void LocalPosition(float _x, float _y, float _z) { localPosition = vec3(_x, _y, _z); }
		void WorldPosition(vec3 _worldPosition) { worldPosition = _worldPosition; }
		void WorldPosition(float _x, float _y, float _z) { worldPosition = vec3(_x, _y, _z); }
		
		quat GetLocalRotation()	{ return quat(localRotation); }
		quat GetWorldRotation() { return quat(worldRotation); }

		void LocalRotation(quat _localRotation) { localRotation = _localRotation; }
		void LocalRotation(float _x, float _y, float _z, float _w) { localRotation = quat(_w, _x, _y, _z); }
		void WorldRotation(quat _worldRotation) { worldRotation = _worldRotation; }
		void WorldRotation(float _x, float _y, float _z, float _w) { worldRotation = quat(_w, _x, _y, _z); }

		vec3 GetLocalScale()	{ return localScale; }
		vec3 GetWorldScale()	{ return worldScale; }

		void LocalScale(vec3 _localScale) { localScale = _localScale; }
		void LocalScale(float _x, float _y, float _z) { localScale = vec3(_x, _y, _z); }
		void WorldScale(vec3 _worldScale) { worldScale = _worldScale; }
		void WorldScale(float _x, float _y, float _z) { worldScale = vec3(_x, _y, _z); }

		mat4 CalculateTranslationMatrix();
		mat4 CalculateRotationMatrix();

		void CalculateFront();																
		void CalculateRight();																
		void CalculateUp();																	

		vec3 GetForward()	{ CalculateFront(); return forward; }
		vec3 GetRight()		{ CalculateRight(); return right; }
		vec3 GetUp()		{ CalculateUp(); return up; }

		Transform*	GetParent() { return parent; }
		void		SetParent(Transform* _parent) { parent = _parent; }

	protected:

		vec3					localPosition;
		vec3					worldPosition;

		quat					localRotation;
		quat					worldRotation;

		vec3					localScale;
		vec3					worldScale;

		vec3					forward;
		vec3					right;
		vec3					up;

		float					yaw;
		float					pitch;
		float					roll;

		mat4 translationMatrix;
		mat4 rotationMatrix;

	private:

		CLASS_DECLARATION(Transform)

		Transform*				parent;
		std::vector<Transform*> children;
	};

}

