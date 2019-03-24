/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<HazeCam.cpp>
Generic Camera class used for main camera in Haze Engine application
<Haze Cam Class Implementation>
*/

#include "stdafx.h"
#include "HazeCam.h"

#include "HazeEngine.h"

#include "Haze_Functions_STD.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(Transform, HazeCam)

	HazeCam::~HazeCam()
	{
	}

	void HazeCam::hzCameraInit(HazeEngine* _hzEngine)
	{
		hzEngine = _hzEngine;

		origin = vec3(0.0f, 0.0f, 0.0f);

		LocalPosition(0.0f, 0.0f, 0.0f);
		WorldPosition(0.0f, 0.0f, -3.0f);

		CalculateFront();
		CalculateRight();
		CalculateUp();

		glfwSetInputMode(HazeEngine::Instance()->GetVulkanRenderer()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		SetPerspective();
	}

	void HazeCam::hzCameraUpdate(float _deltaTime)
	{
		deltaTime = _deltaTime;
		Haze_Functions_STD::console(worldPosition);
		Haze_Functions_STD::console(forward);
		UpdateViewMatrix();
	}

	void HazeCam::MoveForward()
	{
		Translate(GetForward() * cameraMoveSpeed * deltaTime);
	}

	void HazeCam::MoveBackward()
	{
		Translate(-GetForward() * cameraMoveSpeed * deltaTime);
	}

	void HazeCam::MoveLeft()
	{
		right = GetRight();
		Translate(-normalize(GetRight() * cameraMoveSpeed * deltaTime));
	}

	void HazeCam::MoveRight()
	{
		Translate(normalize(GetRight() * cameraMoveSpeed * deltaTime));
	}

	void HazeCam::MoveVerticalPos()
	{
		Translate(vec3(0.0f, 1.0f, 0.0f) * cameraMoveSpeed * deltaTime);
	}

	void HazeCam::MoveVerticalNeg()
	{
		Translate(vec3(0.0f, -1.0f, 0.0f) * cameraMoveSpeed * deltaTime);
	}

	void HazeCam::YawPitchRoll(float _yawRadians, float _pitchRadians, float _rollRadians)
	{
		yaw += radians(_yawRadians * hzEngine->GetInput()->GetMouseXSensitivity());
		pitch += radians(_pitchRadians * hzEngine->GetInput()->GetMouseYSensitivity());
		roll += _rollRadians;

		clamp(pitch, -89.0f, 89.0f);
	}

	void HazeCam::SetPerspective()
	{
		perspectiveMatrix = perspective(radians(fieldOfView), HazeEngine::Instance()->GetVulkanRenderer()->GetAspectRatio(), zNear, zFar);
	}

	void HazeCam::UpdateViewMatrix()
	{
		vec3 worldPosition = GetWorldPosition();
		vec3 forward = GetForward();
		vec3 up = GetUp();
		viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + GetForward(), vec3(0.0f ,1.0f, 0.0f));
		//viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + GetForward(), GetUp());
		//CalculateTranslationMatrix();
		//CalculateRotationMatrix();
		//viewMatrix = translationMatrix * rotationMatrix;
	}
}
