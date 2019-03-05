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

namespace Haze_Engine
{
	HazeInput::HazeInput()
	{
	}


	HazeInput::~HazeInput()
	{
	}

	void HazeInput::Initialize(HazeEngine* _engine)
	{
		hzEngine = _engine;
	}

	void HazeInput::Update(float _deltaTime)
	{

	}

	void HazeInput::ShutDown()
	{

	}

	void HazeInput::hzTakeKeyInput(int _key)
	{
		if (_key == GLFW_KEY_W)
			this->hzEngine->GetCamera()->MoveForward();
		else if (_key == GLFW_KEY_S)
			hzEngine->GetCamera()->MoveBackward();
		else if (_key == GLFW_KEY_A)
			hzEngine->GetCamera()->MoveLeft();
		else if (_key == GLFW_KEY_D)
			hzEngine->GetCamera()->MoveRight();
		else if (_key == GLFW_KEY_Q)
			hzEngine->GetCamera()->MoveVerticalNeg();
		else if (_key == GLFW_KEY_E)
			hzEngine->GetCamera()->MoveVerticalPos();
		else if (_key == GLFW_KEY_ESCAPE)
			hzEngine->GetVulkanRenderer()->ShutDown();
		else if (_key == GLFW_KEY_SPACE)
			hzEngine->GetCamera()->WorldPosition(0, 0, 0);
	}

	void HazeInput::hzTakeMouseDirectionInput(GLFWwindow* _window, double _mouseX, double _mouseY)
	{
		//glfwGetCursorPos(_window, &_mouseX, &_mouseY);

		if (bufferFirstMouse)
		{
			oldMousePosition.x = _mouseX;
			oldMousePosition.y = _mouseY;
			bufferFirstMouse = false;
		}

		float xoffset = _mouseX - oldMousePosition.x;
		float yoffset = oldMousePosition.y - _mouseY;
		oldMousePosition = vec2(xoffset, yoffset);

		hzEngine->GetCamera()->YawPitchRoll(xoffset, yoffset, 0.0f);
	}
}
