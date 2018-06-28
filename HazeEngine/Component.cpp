/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<Component.h>
<Component Class Implementation>
*/

#include "stdafx.h"
#include "Component.h"

namespace ECS
{
	const std::size_t Component::Type = std::hash<std::string>()(TO_STRING(Component));

	Component::Component()
	{
		
	}

	Component::Component(std::string && initialValue)
	{

	}

	Component::~Component()
	{
	}
}
