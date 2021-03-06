// MIT License
// 
// Copyright (c) 2020 Jean-Louis Haywood
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "physics_system.hpp"
#include "application/scene/scene.hpp"
#include <utilities/constants.hpp>
#include <os/os.hpp>

Lilliputian::PhysicsSystem::PhysicsSystem()
{

}

Lilliputian::PhysicsSystem::~PhysicsSystem()
{

}

void Lilliputian::PhysicsSystem::process(Scene& scene, uint32_t msPerComputeUpdate)
{
	this->updateTimers(scene, msPerComputeUpdate);
}

void Lilliputian::PhysicsSystem::updateTimers(Scene& scene, uint32_t msPerComputeUpdate)
{
	std::vector<ComponentVariant>& componentVariants = scene.getComponentVariants();
	ComponentVariant* componentVariantsData = componentVariants.data();
	int componentVariantCount = componentVariants.size();

	for (int j = 0; j < componentVariantCount; j++)
	{
		ComponentVariant* componentVariant = &componentVariantsData[j];
		if (componentVariant->getType() == ComponentVariant::Type::COUNTDOWN_TIMER)
		{
			componentVariant->getCountdownTimer()->update(msPerComputeUpdate * (1.0 / MS_IN_S));
		}
	}
}