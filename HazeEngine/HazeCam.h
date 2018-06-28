#ifndef HAZE_CAM_H
#define HAZE_CAM_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<HazeCam.h>
Generic Camera class used for main camera in Haze Engine application
<Haze Cam Class Declaration>
*/

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/matrix_transform.hpp>
using namespace glm;

#include "Component.h"

namespace Haze_Engine
{
	class HazeEngine;

	class HazeCam : public ECS::Component
	{

	CLASS_DECLARATION( HazeCam ) 

	public:
		HazeCam();
		~HazeCam();

		////////////////////////////////////////HAZE CAMERA ROUTINES//////////////////////////////////////////
		void			hzCameraInit(HazeEngine* _hzEngine);												//Camera Initialization
		void			hzCameraUpdate(float _deltaTime);													//Camera Update

		void			MoveForward();																		//Move in camera direction
		void			MoveBackward();																		//Move in opposite camera direction
		void			MoveRight();																		//Move in camera right direction
		void			MoveLeft();																			//Move in opposite camera right direction
		
		void			MoveVerticalPos();																	//Move in absolute world up
		void			MoveVerticalNeg();																	//Move in absolute world down

		void			YawPitchRoll(float _yawRadians, float _pitchRadians, float _rollRadians);			//Applies mouse movement to Yaw/Pitch/Roll

		mat4			GetProjMatrix() { return perspectiveMatrix; }										//Builds Projection Matrix using FOV and Depth
		mat4			GetViewMatrix() { return viewMatrix; }												//Builds View Matrix using camera position rotation
		////////////////////////////////////////HAZE CAMERA ROUTINES//////////////////////////////////////////

		////////////////////////////////////////HAZE CAMERA MEMBERS///////////////////////////////////////////
		vec3			rotation = vec3();																	//Camera Rotation
		vec3			position = vec3();																	//Camera Position

		float			cameraMoveSpeed = 3.0f;																//Camera Move Speed
		////////////////////////////////////////HAZE CAMERA MEMBERS///////////////////////////////////////////
                                                                                  
	private:

		////////////////////////////////////////HAZE CAMERA MEMBERS///////////////////////////////////////////
		HazeEngine *	hzEngine;																			//Haze Engine Instance

		vec3			origin;																				//Origin point in world (0,0,0)

		mat4			perspectiveMatrix;																	//Matrix built from FOV, Near, and Far planes
		mat4			viewMatrix;																			//Matrix built from position, rotation

		vec3			forward;																			//Facing direction of camera
		vec3			right;																				//Right direction of camera
		vec3			up;																					//Up direction of camera

		float			yaw;																				//Yaw(X) rotation of camera
		float			pitch;																				//Pitch(Y) rotation of camera
		float			roll;																				//Roll(Z) rotation of camera

		float			fieldOfView = 60.0f;																//FOV
		float			zNear = .01f;																		//Near clipping plane distance
		float			zFar = 100.0f;																		//Far clipping plane distance

		float			deltaTime = 0.0f;																	//delta time between frames
		////////////////////////////////////////HAZE CAMERA MEMBERS///////////////////////////////////////////

		////////////////////////////////////////HAZE CAMERA ROUTINES//////////////////////////////////////////
		void			SetPerspective();																	//Sets Perspective Matrix
		void			UpdateViewMatrix();																	//Updates View Matrix

		vec3			CalculateCamFront();																//Calculates Camera Forward
		vec3			CalculateCamRight();																//Calculates Camera Right
		vec3			CalculateCamUp();																	//Calculates Camera Up
		////////////////////////////////////////HAZE CAMERA ROUTINES//////////////////////////////////////////
	};
}

#endif

