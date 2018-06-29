/*
<Dylan Higbee>
<June 28th, 2018>
<1:23AM>
<HazeEngine.cpp>
Entry point for Haze Engine
<Haze Engine Implementation>
*/

#include "stdafx.h"
#include "HazeEngine.h"

#include "Transform.h"

#include <iostream>
using namespace std;

static Haze_Engine::HazeEngine* hazeEngine;

//Entry point of program, creates instance of Haze Engine
int main()
{
	hazeEngine = new Haze_Engine::HazeEngine();
	hazeEngine->HazeInit();

	while (!hazeEngine->IsShutDown())
	{
		hazeEngine->HazeUpdate();
	}

	delete hazeEngine;

	return 0;
}

//Haze_Engine namespace, anything associated with the functionality of the engine is placed within this namespace, including helper functions.
namespace Haze_Engine
{
	//Haze Engine Constructor
	HazeEngine::HazeEngine()
	{
		
	}

	//Haze Engine Destructor
	HazeEngine::~HazeEngine()
	{
		delete vkr;
	}

	//Initialization of Haze Engine, creates all systems.
	void HazeEngine::HazeInit()
	{
		entityManager = CreateSystem<EntityManager>();
		entityManager->Initialize(this);

		vkr = CreateSystem<VulkanRenderer>();
		vkr->Initialize(this);

		Entity* mainCam = entityManager->CreateEntity("Main Camera");
		camera = new HazeCam();
		camera->hzCameraInit(this);
		mainCam->AddComponent<HazeCam>(camera);
		entityManager->AddEntity(mainCam);
		
		input = CreateSystem<HazeInput>();
		input->Initialize(this);

		if (!Haze_Functions_STD::null(vkr->GetGLFWWindow()))
		{
			glfwSetKeyCallback(vkr->GetGLFWWindow(), key_callback );
			glfwSetCursorPosCallback(vkr->GetGLFWWindow(), mouse_position_callback);
		}
	}

	//Update of Haze Engine, calculates dt then passes it to all object updates. 
	void HazeEngine::HazeUpdate()
	{
		double prevTime = glfwGetTime();
		double currTime = glfwGetTime();
		while (!vkr->IsWindowClose())
		{
			glfwPollEvents();
			deltaTime = currTime - prevTime;

 			framesPerSecond++;

			fpsTimer += deltaTime;

			prevTime = currTime;
			camera->hzCameraUpdate(deltaTime);
			vkr->Update(deltaTime);
			vkr->Render();
			currTime = glfwGetTime();

			CheckFPS();
		}
		vkr->ShutDown();

		SetShutDown(true);
	}

	template <class T>
	T* HazeEngine::CreateSystem()
	{
		T* system = new T();
		systems.insert(system);
		return system;
	}

	void HazeEngine::CheckFPS()
	{
		if (fpsTimer >= 1.0f)
		{
			Haze_Functions_STD::console("FPS: ");
			Haze_Functions_STD::console(framesPerSecond);
			framesPerSecond = 0;
			fpsTimer = 0.0f;
		}
	}


#pragma region ////////////////////////////////////////HAZE ENGINE HELPER FUNCTIONS////////////////////////////////////////
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		hazeEngine->GetInput()->hzTakeKeyInput(key);
	}

	void mouse_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		hazeEngine->GetInput()->hzTakeMouseDirectionInput(window, xpos, ypos);
	}
#pragma endregion
}

