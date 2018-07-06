#ifndef VERTEX_H
#define VERTEX_H

#include "Haze_Functions_STD.h"

namespace Haze_Engine
{
	class Vertex
	{
	public:
		Vertex();
		~Vertex();

		vec3 GetPosition() { return position; }
		void SetPosition(vec3 _position) { position = _position; }

		vec3 GetColor() { return color; }
		void SetColor(vec3 _color) { color = _color; }

	protected:

		vec3 position;
		vec3 color;
	};
}
#endif
