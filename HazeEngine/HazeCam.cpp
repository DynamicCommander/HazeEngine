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

	void HazeCam::Initialize()
	{
		origin = vec3(0.0f, 0.0f, 0.0f);

		LocalPosition(0.0f, 0.0f, 0.0f);
		WorldPosition(0.0f, 0.0f, -3.0f);
		WorldRotation(0.0f, 0.0f, 1.0f, 0);

		glfwSetInputMode(HazeEngine::Instance()->GetVulkanRenderer()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		SetPerspective();
	}

	void HazeCam::Update(float _deltaTime)
	{
		Transform::Update(_deltaTime);
		UpdateViewMatrix();
	}

	void HazeCam::MoveForward()
	{	
		Translate(cameraMoveSpeed * GetForward() * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::MoveBackward()
	{
		Translate(cameraMoveSpeed * -GetForward() * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::MoveLeft()
	{
		Translate(cameraMoveSpeed * -GetRight() * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::MoveRight()
	{
		Translate(cameraMoveSpeed * GetRight() * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::MoveVerticalPos()
	{
		Translate((cameraMoveSpeed * GetUp()) * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::MoveVerticalNeg()
	{
		Translate((cameraMoveSpeed * -GetUp()) * HazeEngine::Instance()->DeltaTime());
	}

	void HazeCam::YawPitchRoll(float _yawRadians, float _pitchRadians, float _rollRadians)
	{
		Haze_Functions_STD::console(HazeEngine::Instance()->DeltaTime());
		yaw += _yawRadians * HazeEngine::Instance()->DeltaTime();
		pitch += _pitchRadians * HazeEngine::Instance()->DeltaTime();
		roll += _rollRadians * HazeEngine::Instance()->DeltaTime();

		Rotate(_yawRadians, WORLD_UP);
		Rotate(_pitchRadians, WORLD_RIGHT);
		Rotate(_rollRadians, WORLD_FORWARD);

		Haze_Functions_STD::clamp(pitch, -89.0f, 89.0f);
	}

	void HazeCam::SetPerspective()
	{
		perspectiveMatrix = perspective(radians(fieldOfView), HazeEngine::Instance()->GetVulkanRenderer()->GetAspectRatio(), zNear, zFar);
	}

	void HazeCam::UpdateViewMatrix()
	{
		viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + GetWorldRotation(), GetUp());
	}
}
