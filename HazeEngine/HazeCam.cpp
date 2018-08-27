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

	void HazeCam::hzCameraInit()
	{
		origin = vec3(0.0f, 0.0f, 0.0f);

		WorldPosition(vec3(0.0f, 0.0f, 0.0f));

		glfwSetInputMode(HazeEngine::Instance()->GetVulkanRenderer()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		SetPerspective();
	}

	void HazeCam::hzCameraUpdate(float _deltaTime)
	{
		deltaTime = _deltaTime;
		Haze_Functions_STD::console("World Position");
		Haze_Functions_STD::console(worldPosition);
		Haze_Functions_STD::console("World Rotation");
		Haze_Functions_STD::console(worldRotation);
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
		yaw += _yawRadians * HazeEngine::Instance()->GetInput()->GetMouseXSensitivity() * deltaTime;
		pitch += _pitchRadians * HazeEngine::Instance()->GetInput()->GetMouseYSensitivity() * deltaTime;
		roll += _rollRadians;

		clamp(pitch, -89.0f, 89.0f);

		Rotate(yaw, up);
		Rotate(pitch, right);
		Rotate(roll, forward);
	}

	void HazeCam::SetPerspective()
	{
		perspectiveMatrix = perspective(radians(fieldOfView), HazeEngine::Instance()->GetVulkanRenderer()->GetAspectRatio(), zNear, zFar);
	}

	void HazeCam::UpdateViewMatrix()
	{
		//viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + GetForward(), GetUp());
		CalculateTranslationMatrix();
		CalculateRotationMatrix();
		viewMatrix = translationMatrix * rotationMatrix;
	}

}
