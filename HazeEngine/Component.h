#ifndef COMPONENT_H
#define COMPONENT_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<Component.h>
<Component Class Declaration>
*/

#define CLASS_DECLARATION( classname ) 
#define CLASS_DEFINITION( parentclass, childclass )

namespace ECS
{ 
	class Entity;

	class Component
	{

	public:

		Component();
		Component(std::string && initialValue);

		~Component();

		static const std::size_t Type;
		virtual bool isClassType(const std::size_t classType) const 
		{
			return classType == Type;
		}

		Entity*		owner;
	};
}

#endif



