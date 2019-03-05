#include "stdafx.h"

#include "Vertex.h"

namespace Haze_Engine
{
	Vertex::Vertex()
	{
		position = vec3(0.0f, 0.0f, 0.0f);
		color = vec3(0.0f, 0.0f, 0.0f);
	}

	Vertex::Vertex(vec3 _position, vec3 _color)
	{
		position = _position;
		_color = _color;
	}

	Vertex::~Vertex()
	{
	}
}
