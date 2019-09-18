/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<HazeInput.cpp>
Generic Input class for Haze Engine
<Haze Input Class Implementation>
*/

#include "stdafx.h"
#include "HazeInput.h"
#include "HazeEngine.h"
#include "Model.h"

namespace Haze_Engine
{
	HazeInput::HazeInput()
	{
	}


	HazeInput::~HazeInput()
	{
	}

	void HazeInput::Initialize()
	{
		oldMousePosition = vec2(0, 0);
	}

	void HazeInput::Update(float _deltaTime)
	{

	}

	void HazeInput::ShutDown()
	{

	}

	void HazeInput::hzTakeKeyInput(int _key)
	{
		HazeCam* camera = HazeEngine::Instance()->GetEntityManager()->FindEntityByType<HazeCam>()->GetComponent<HazeCam>();
		Transform* cube = HazeEngine::Instance()->GetEntityManager()->FindEntityByType<Model>()->GetComponent<Transform>();
		
		if (_key == GLFW_KEY_W)
			camera->MoveForward();
		else if (_key == GLFW_KEY_S)
			camera->MoveBackward();
		else if (_key == GLFW_KEY_A)
			camera->MoveLeft();
		else if (_key == GLFW_KEY_D)
			camera->MoveRight();
		else if (_key == GLFW_KEY_Q)
			camera->MoveVerticalNeg();
		else if (_key == GLFW_KEY_E)
			camera->MoveVerticalPos();
		else if (_key == GLFW_KEY_ESCAPE)
			HazeEngine::Instance()->GetVulkanRenderer()->ShutDown();
		else if (_key == GLFW_KEY_SPACE)
		{
			camera->Initialize();
		}
	}

	void HazeInput::hzTakeMouseDirectionInput(GLFWwindow* _window, double _mouseX, double _mouseY)
	{
		float xoffset = _mouseX - HazeEngine::Instance()->GetVulkanRenderer()->GetWindowWidth() / 2;
		float yoffset = HazeEngine::Instance()->GetVulkanRenderer()->GetWindowHeight() / 2 - _mouseY;

		Haze_Functions_STD::console(xoffset);
		Haze_Functions_STD::console(yoffset);

		HazeEngine::Instance()->GetEntityManager()->FindEntityByType<HazeCam>()->GetComponent<HazeCam>()->YawPitchRoll(xoffset * mouseXSensitivity, -yoffset * mouseYSensitivity, 0.0f);
	}
}
