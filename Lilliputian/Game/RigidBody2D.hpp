#pragma once

#include "../Utilities/Aliases.hpp"
#include "../Utilities/Vector2.hpp"
#include "../Utilities/Constants.hpp"

namespace Lilliputian
{
	class RigidBody2D
	{
	private:
	public:
		EntityID entityID = NO_ENTITY;

		double mass_kg = 1.0;
		double friction_ratio = 1.0;
		double angularDrag_ratio = 1.0;
		double angularVelocity_rad_per_s = 0.0;
		double gravity_scale = 1.0;
		double elasticity_ratio = 0.01;
		Vector2 drag_ratio;
		Vector2 velocity_px_per_s;

		RigidBody2D()
		{
			this->drag_ratio.x = 0.0001;
			this->drag_ratio.y = 1.0;
		}
	};
}