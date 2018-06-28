#pragma once

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<CSystem.cpp>
<CSystem Class Declaration>
*/

namespace Haze_Engine
{
	class HazeEngine;

	class CSystem
	{
	public:

		CSystem();
		virtual ~CSystem();

		virtual void Initialize(HazeEngine* _engine) = 0;
		virtual void Update(float _deltaTime) = 0;
		virtual void ShutDown() = 0;
	};

}

