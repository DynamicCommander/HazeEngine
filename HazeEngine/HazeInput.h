#ifndef HAZE_INPUT_H
#define HAZE_INPUT_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<HazeInput.h>
Generic Input class for Haze Engine
<Haze Input Class Declaration>
*/
#include "stdafx.h"
#include "CSystem.h"

#include "Haze_Functions_STD.h"

namespace Haze_Engine
{
	class HazeEngine;

	class HazeInput : public CSystem
	{
	public:
		HazeInput();
		~HazeInput();

		void Initialize();
		void Update(float _deltaTime);
		void ShutDown();

		////////////////////////////////////////HAZE INPUT ROUTINES//////////////////////////////////////////
		void						hzTakeKeyInput(int _key);												//Keyboard Input
		void						hzTakeMouseDirectionInput(GLFWwindow* _window, double _mouseX, double _mouseY);	//Mouse Input

		float						GetMouseXSensitivity() { return mouseXSensitivity; }					//Public Access Mouse X Speed
		float						GetMouseYSensitivity() { return mouseYSensitivity; }					//Public Access Mouse Y Speed
		////////////////////////////////////////HAZE INPUT ROUTINES//////////////////////////////////////////

	private:

		////////////////////////////////////////HAZE INPUT MEMBERS///////////////////////////////////////////

		float						mouseXSensitivity = 0.05f;												//Mouse X Speed
		float						mouseYSensitivity = 0.05f;												//Mouse Y Speed

		vec2						oldMousePosition;														//Old mouse position, used to calculate new offset

		bool						bufferFirstMouse = true;												//Buffer first mouse input
		////////////////////////////////////////HAZE INPUT MEMBERS///////////////////////////////////////////
	};

}
#endif
