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
#include "Model.h"

#include <iostream>
using namespace std;

//Entry point of program, creates instance of Haze Engine
int main()
{
	HazeEngine::Instance()->HazeInit();

	while (!HazeEngine::Instance()->IsShutDown())
	{
		HazeEngine::Instance()->HazeUpdate();
	}

	return 0;
}

//Haze_Engine namespace, anything associated with the functionality of the engine is placed within this namespace, including helper functions.
namespace Haze_Engine
{
	//Haze Engine Destructor
	HazeEngine::~HazeEngine()
	{
		delete vkr;
	}

	//Initialization of Haze Engine, creates all systems.
	void HazeEngine::HazeInit()
	{
		entityManager = CreateSystem<EntityManager>();
		vkr = CreateSystem<VulkanRenderer>();
		input = CreateSystem<HazeInput>();

		entityManager->Initialize(this);
		vkr->Initialize(this);
		input->Initialize(this);

		Entity* mainCam = entityManager->CreateEntity("Main Camera");
		camera = new HazeCam(mainCam);
		camera->hzCameraInit();
		mainCam->AddComponent<HazeCam>(camera);

		std::vector<Vertex> *vertices = new std::vector<Vertex>(
		{
			{ { -1.0f, -1.0f, -1.0f }	,{ 1.0f, 0.0f, 0.0f } },
			{ { 1.0f, -1.0f, -1.0f }	,{ 0.0f, 1.0f, 0.0f } },
			{ { 1.0f, 1.0f, -1.0f }	,{ 0.0f, 0.0f, 1.0f } },
			{ { -1.0f, 1.0f, -1.0f }	,{ 1.0f, 1.0f, 1.0f } },
			{ { -1.0f, -1.0f, 1.0f }	,{ 1.0f, 0.0f, 0.0f } },
			{ { 1.0f, -1.0f, 1.0f }	,{ 0.0f, 1.0f, 0.0f } },
			{ { 1.0f, 1.0f, 1.0f }	,{ 0.0f, 0.0f, 1.0f } },
			{ { -1.0f, 1.0f, 1.0f }	,{ 1.0f, 1.0f, 1.0f } }
		});

		std::vector<uint16_t> *indices = new std::vector<uint16_t>(
		{
			0, 1, 3, 3, 1, 2,
			1, 5, 2, 2, 5, 6,
			5, 4, 6, 6, 4, 7,
			4, 0, 7, 7, 0, 3,
			3, 2, 7, 7, 2, 6,
			4, 5, 0, 0, 5, 1
		});

		Entity* cube = entityManager->CreateEntity("Cube");
		Model* model = new Model(Active_Renderer::VULKAN, cube);
		model->SetVertices(vertices);
		model->SetIndices(indices);
		cube->GetComponent<Transform>().WorldPosition(vec3(0.0f, 0.0f, 3.0f));
		cube->AddComponent<Model>(model);

		if (!Haze_Functions_STD::null(vkr->GetGLFWWindow()))
		{
			glfwSetKeyCallback(vkr->GetGLFWWindow(), key_callback);
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

	template <class T>
	T* HazeEngine::FindSystemByType(T _system)
	{
		return systems.find(_system);
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
		HazeEngine::Instance()->GetInput()->hzTakeKeyInput(key);
	}

	void mouse_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		HazeEngine::Instance()->GetInput()->hzTakeMouseDirectionInput(window, xpos, ypos);
	}
#pragma endregion
}

