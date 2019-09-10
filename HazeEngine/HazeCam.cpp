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
		float deltaTime = HazeEngine::Instance()->DeltaTime();
		yaw += _yawRadians;
		pitch += _pitchRadians;
		roll += _rollRadians;

		Haze_Functions_STD::clamp(pitch, -89.0f, 89.0f);
		Transform* t = HazeEngine::Instance()->GetEntityManager()->FindEntity(1)->GetComponent<Transform>();
		t->Rotate(yaw, t->GetUp());
		t->Rotate(pitch, t->GetRight());
		//worldRotation.y += yaw;
		//worldRotation.x += pitch;
		//worldRotation.x = Haze_Functions_STD::clamp(pitch, glm::radians(90.0f), glm::radians(270.0f)); //std::clamp(pitch, Maths::Radians(90.0f), Maths::Radians(270.0f));

		Haze_Functions_STD::console(worldRotation);
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
