/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<HazeCam.cpp>
Generic Camera class used for main camera in Haze Engine application
<Haze Cam Class Implementation>
*/

#include "stdafx.h"

#include "HazeEngine.h"
#include "HazeCam.h"

#include "Haze_Functions_STD.h"

namespace Haze_Engine
{
	CLASS_DEFINITION(Component, HazeCam)

		HazeCam::HazeCam()
	{
		this->viewMatrix = mat4();
		this->perspectiveMatrix = mat4();
	}

	HazeCam::~HazeCam()
	{
	}

	void HazeCam::hzCameraInit(HazeEngine* _hzEngine)
	{
		hzEngine = _hzEngine;

		origin = vec3(0.0f, 0.0f, 0.0f);

		WorldPosition(vec3(0.0f, 0.0f, 3.0f));

		glfwSetInputMode(hzEngine->GetVulkanRenderer()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		SetPerspective();
	}

	void HazeCam::hzCameraUpdate(float _deltaTime)
	{
		deltaTime = _deltaTime;

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
		yaw += _yawRadians * hzEngine->GetInput()->GetMouseXSensitivity();
		pitch += _pitchRadians * hzEngine->GetInput()->GetMouseYSensitivity();
		roll += _rollRadians;

		clamp(pitch, -89.0f, 89.0f);

		Rotate(yaw, pitch, roll);
	}

	void HazeCam::SetPerspective()
	{
		perspectiveMatrix = perspective(radians(fieldOfView), hzEngine->GetVulkanRenderer()->GetAspectRatio(), zNear, zFar);
	}

	void HazeCam::UpdateViewMatrix()
	{
		viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + GetForward(), GetUp());
	}

}
