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

		position = vec3(0.0f, 0.0f, 3.0f);

		forward = normalize(position - origin);
		right = normalize(cross(vec3(0.0f, 1.0f, 0.0f), forward));
		up = cross(forward, right);

		glfwSetInputMode(hzEngine->GetVulkanRenderer()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		SetPerspective();
	}

	void HazeCam::hzCameraUpdate(float _deltaTime)
	{
		deltaTime = _deltaTime;
	}

	void HazeCam::MoveForward()
	{
		position += forward * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}

	void HazeCam::MoveBackward()
	{
		position -= forward * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}

	void HazeCam::MoveLeft()
	{
		position -= normalize(cross(forward, up)) * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}

	void HazeCam::MoveRight() 
	{
		position += normalize(cross(forward, up)) * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}		 

	void HazeCam::MoveVerticalPos()
	{
		position += normalize(vec3(0.0f,1.0f,0.0f)) * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}

	void HazeCam::MoveVerticalNeg()
	{
		position -= normalize(vec3(0.0f,1.0f,0.0f)) * cameraMoveSpeed * deltaTime;
		UpdateViewMatrix();
	}

	void HazeCam::YawPitchRoll(float _yawRadians, float _pitchRadians, float _rollRadians)
	{
		yaw += _yawRadians * hzEngine->GetInput()->GetMouseXSensitivity() * deltaTime;
		pitch += _pitchRadians * hzEngine->GetInput()->GetMouseYSensitivity() * deltaTime;
		roll += _rollRadians;

		clamp(pitch, -89.0f, 89.0f);

		UpdateViewMatrix();
	}

	void HazeCam::SetPerspective()
	{
		perspectiveMatrix = perspective(radians(fieldOfView), hzEngine->GetVulkanRenderer()->GetAspectRatio(), zNear, zFar);
	}

	void HazeCam::UpdateViewMatrix()
	{
		forward = CalculateCamFront();
		right = CalculateCamRight();
		up = CalculateCamUp();

		viewMatrix = lookAt(position, position + forward, up);
	}

	vec3 HazeCam::CalculateCamFront()
	{
		glm::vec3 camFront;
		camFront.x = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		camFront.y = sin(glm::radians(pitch));
		camFront.z = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		camFront = glm::normalize(camFront);

		return camFront;
	}

	vec3 HazeCam::CalculateCamRight()
	{
		glm::vec3 camRight;
		camRight = vec3( sin(rotation.y - 3.14 / 2.0f), 0, cos(rotation.y - 3.14f / 2.0f));
		return camRight;
	}

	vec3 HazeCam::CalculateCamUp()
	{
		glm::vec3 camUp;
		camUp = cross(right, forward);
		return camUp;
	}
}
