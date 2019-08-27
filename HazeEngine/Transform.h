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

		Transform() : Component(){ }

		Transform(ECS::Entity* _owner) : Component(_owner) 
		{ 
			parent = nullptr;
			children = std::vector<Transform*>();

			localPosition = vec3(0.0f, 0.0f, 0.0f);
			worldPosition = vec3(0.0f, 0.0f, 0.0f);

			localRotation = vec3(0.0f, 0.0f, 0.0f);
			worldRotation = vec3(0.0f, 1.0f, 0.0f);

			localScale = vec3(1.0f, 1.0f, 1.0f);
			worldScale = vec3(1.0f, 1.0f, 1.0f);

			right = normalize(vec3(1.0f, 0.0f, 0.0f));
			up = normalize(vec3(0.0f, 1.0f, 0.0f));

			translationMatrix = mat4(1.0f);
			rotationMatrix = mat4(1.0f);
			scaleMatrix = mat4(1.0f);
		};

		~Transform();

		void Initialize();
		void Update(float _deltaTime);

		void Translate(vec3 _direction, bool _isWorld = true);
		void Translate(float _x, float _y, float _z, bool _isWorld = true);

		void Rotate(vec3 _rotationbool, bool _isWorld = true);
		void Rotate(float _x, float _y, float _z, bool _isWorld = true);

		void Scale(vec3 _scale);
		void Scale(float _x, float _y, float _z);

		vec3 GetLocalPosition()	{ return localPosition; }
		vec3 GetWorldPosition() { return worldPosition; }

		void LocalPosition(vec3 _localPosition) { localPosition = _localPosition; }
		void LocalPosition(float _x, float _y, float _z) { localPosition = vec3(_x, _y, _z); }
		void WorldPosition(vec3 _worldPosition) { worldPosition = _worldPosition; }
		void WorldPosition(float _x, float _y, float _z) { worldPosition = vec3(_x, _y, _z); }
		
		vec3 GetLocalRotation() { return localRotation; }
		vec3 GetWorldRotation() { return worldRotation; }

		void LocalRotation(vec3 _localRotation) { localRotation = _localRotation; }
		void LocalRotation(float _x, float _y, float _z, float _w) { localRotation = vec3(_x, _y, _z); }
		void WorldRotation(vec3 _worldRotation) { worldRotation = _worldRotation; }
		void WorldRotation(float _x, float _y, float _z, float _w) { worldRotation = vec3(_x, _y, _z); }

		vec3 GetLocalScale()	{ return localScale; }
		vec3 GetWorldScale()	{ return worldScale; }

		void LocalScale(vec3 _localScale) { localScale = _localScale; }
		void LocalScale(float _x, float _y, float _z) { localScale = vec3(_x, _y, _z); }
		void WorldScale(vec3 _worldScale) { worldScale = _worldScale; }
		void WorldScale(float _x, float _y, float _z) { worldScale = vec3(_x, _y, _z); }

		mat4 GetTranslationMatrix() { return CalculateTranslationMatrix(); }
		mat4 GetRotationMatrix() { return CalculateRotationMatrix(); }
		mat4 GetScaleMatrix() { return CalculateScaleMatrix(); }

		mat4 CalculateTranslationMatrix();
		mat4 CalculateRotationMatrix();
		mat4 CalculateScaleMatrix();

		void CalculateAxis();			

		vec3 GetForward()	{ CalculateAxis(); return worldRotation; }
		vec3 GetUp() { return up; }
		vec3 GetRight() { return right; }

		Transform*	GetParent() { return parent; }
		void		SetParent(Transform* _parent) { parent = _parent; }

	protected:

		vec3 localPosition;
		vec3 worldPosition;
			 
		vec3 localRotation;
		vec3 worldRotation;
			 
		vec3 localScale;
		vec3 worldScale;
			
		vec3 right;
		vec3 up;
			  
		float yaw;
		float pitch;
		float roll;

		mat4 translationMatrix;
		mat4 rotationMatrix;
		mat4 scaleMatrix;

		bool isDirty = false;

	private:

		CLASS_DECLARATION(Transform)

		Transform*				parent;
		std::vector<Transform*> children;
	};

}

