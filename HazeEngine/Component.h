#ifndef COMPONENT_H
#define COMPONENT_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<Component.h>
<Component Class Declaration>
*/

namespace ECS
{ 

#define CLASS_DECLARATION( classname )										\
public:																		\
	static const std::size_t Type;											\
	virtual bool isClassType(const std::size_t classType) const override;	\

#define CLASS_DEFINITION( parentclass, childclass )										\
const std::size_t childclass::Type = std::hash< std::string >()(TO_STRING(childclass)); \
bool childclass::isClassType(const std::size_t classType) const							\
{																						\
		if (classType == childclass::Type)                                              \
			return true;                                                                \
			return parentclass::isClassType(classType);                                 \
}																						\

	class Entity;

	class Component
	{

	public:

		Component(Entity* _owner);
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



