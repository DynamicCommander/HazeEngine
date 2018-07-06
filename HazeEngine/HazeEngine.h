#ifndef HAZE_ENGINE_H
#define HAZE_ENGINE_H

/*
<Dylan Higbee>
<June 27th, 2018>
<9:09AM>
<HazeEngine.cpp>
<Haze Engine Class Declaration>
*/

#include "stdafx.h"

#include "CSystem.h"

#include "VulkanRenderer.h"
using namespace Vulkan_Renderer;

#include "HazeCam.h"
#include "HazeInput.h"

#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"
using namespace ECS;

#include <time.h>
#include <set>

static Haze_Engine::HazeEngine* hazeEngine;

enum Active_Renderer {DIRECTX, VULKAN, OPENGL};

namespace Haze_Engine
{
	class HazeEngine
	{
	protected:
		////////////////////////////////////////HAZE ENGINE MEMBERS//////////////////////////////////////////
		HazeCam*		camera;																				//Haze Camera, allows the user to move through the scene
		HazeInput*		input;																				//Haze Input, takes input from user and applies functionality to various classes

		VulkanRenderer* vkr;																				//Vulkan Renderer Object, renders objects to screen.
		EntityManager*	entityManager;																		//Entity Manager Object, creates new Entities
		////////////////////////////////////////HAZE ENGINE MEMBERS//////////////////////////////////////////
	
	public:

		HazeEngine();																						//Haze Engine Constructor
		~HazeEngine();																						//Haze Engine Destructor

		////////////////////////////////////////HAZE ENGINE MEMBERS//////////////////////////////////////////
		HazeCam*					GetCamera()				{ return this->camera; }						//Public access to Camera Object.
		HazeInput*					GetInput()				{ return this->input; }							//Public access to Input Object
		VulkanRenderer*				GetVulkanRenderer()		{ return this->vkr; }							//Public access to Vulkan Renderer
		EntityManager*				GetEntityManager()		{ return this->entityManager; }					//Public acceess to Entity Manager
		////////////////////////////////////////HAZE ENGINE MEMBERS//////////////////////////////////////////

		////////////////////////////////////////HAZE ENGINE ROUTINES//////////////////////////////////////////
		void						HazeInit();																//Initialization of Haze Engine, creates all systems.
		void						HazeUpdate();															//Update of Haze Engine, calculates dt then passes it to all object updates.

		template <class T>
		T*							CreateSystem();

		template <class T>
		T*							FindSystemByType(T _system);

		const bool					IsShutDown() { return shutDown; }										//Status of Engine
		////////////////////////////////////////HAZE ENGINE ROUTINES//////////////////////////////////////////
	
	private:

		////////////////////////////////////////HAZE ENGINE MEMBERS///////////////////////////////////////////
		std::set<CSystem*>			systems;																//Systems list

		bool						shutDown = false;														//Controls whether Haze Engine should shut down and clean up all data

		int							framesPerSecond = 0;													//Frames that happen every second of application run time
		float						fpsTimer = 0.0f;														//Timer that controls when the fps counter resets
		float						deltaTime = 0.0f;														//Difference in time between update frames.
		////////////////////////////////////////HAZE ENGINE MEMBERS//////////////////////////////////////////


		////////////////////////////////////////HAZE ENGINE ROUTINES/////////////////////////////////////////
		void						SetShutDown(const bool _shutDown) { shutDown = _shutDown; }				//Set Engine Status

		void						CheckFPS();																//Checks to see if FPS needs reset
		////////////////////////////////////////HAZE ENGINE ROUTINES/////////////////////////////////////////
	};
	
#pragma region ////////////////////////////////////////HAZE ENGINE HELPER FUNCTIONS////////////////////////////////////////
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_position_callback(GLFWwindow* window, double xpos, double ypos);
#pragma endregion
}

#endif
