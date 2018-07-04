#ifndef HAZE_FUNCTIONS_STD_H
#define HAZE_FUNCTIONS_STD_H

#include "stdafx.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\quaternion.hpp>
using namespace glm;

#include <iostream>
using namespace std;

namespace Haze_Functions_STD
{
#pragma region ////////////////////////////////////////HAZE ENGINE HELPER FUNCTIONS////////////////////////////////////////

	//cleaner NULL checks
	inline bool null(void* _object)
	{
		if (_object == NULL)
			return true;
		return false;
	}

	//print to console
	inline void console(char * _param) { cout << _param << endl; }
	inline void console(string _param) { cout << _param << endl; }
	inline void console(int	_param) { cout << _param << endl; }
	inline void console(vec3	_param) { cout << "X: " << _param.x << " , " << "Y: " << _param.y << " , " << "Z: " << _param.z << endl; }

	inline float clamp(float& _input, float _min, float _max)
	{
		if (_input <= _min)
			_input = _min;
		else if (_input >= _max)
			_input = _max;

		return _input;
	}

#pragma endregion
}

#endif
