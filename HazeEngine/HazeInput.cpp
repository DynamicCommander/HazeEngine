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
			camera->WorldPosition(0, 0, 0);
	}

	void HazeInput::hzTakeMouseDirectionInput(GLFWwindow* _window, double _mouseX, double _mouseY)
	{
		if (bufferFirstMouse)
		{
			oldMousePosition.x = _mouseX;
			oldMousePosition.y = _mouseY;
			bufferFirstMouse = false;
		}

		float xoffset = _mouseX - oldMousePosition.x;
		float yoffset = oldMousePosition.y - _mouseY;

		oldMousePosition = vec2(xoffset, yoffset);
		glfwSetCursorPos(_window, 0, 0);

		HazeEngine::Instance()->GetEntityManager()->FindEntityByType<HazeCam>()->GetComponent<HazeCam>()->YawPitchRoll(xoffset * mouseXSensitivity, -yoffset * mouseYSensitivity, 0.0f);
	}
}
