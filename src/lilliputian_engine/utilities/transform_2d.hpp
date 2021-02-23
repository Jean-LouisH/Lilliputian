#pragma once

#include "vector2.hpp"

namespace Lilliputian
{
	class Transform2D
	{
	public:
		Vector2 position_px;
		float rotation_rad;
		Vector2 scale;

		Transform2D() :
			rotation_rad(0.0)
		{
			this->scale.x = 1;
			this->scale.y = 1;
		}
	private:
	};
}