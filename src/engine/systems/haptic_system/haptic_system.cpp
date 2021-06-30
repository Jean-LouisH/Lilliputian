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

#include "haptic_system.hpp"
#include <SDL.h>

Lilliputian::HapticSystem::HapticSystem()
{

}

void Lilliputian::HapticSystem::rumble(HapticSignalBuffer& hapticSignalBuffer, std::vector<SDL_Haptic*> haptics)
{
	std::map<ControllerPlayerID, std::queue<HapticSignal>>& hapticSignals = hapticSignalBuffer.getHapticSignals();

	for (auto it = hapticSignals.begin(); it != hapticSignals.end(); it++)
	{
		while (!it->second.empty())
		{
			SDL_HapticRumblePlay(
				haptics.at(it->first),
				it->second.front().getStrength_pct(),
				it->second.front().getDuration_ms());

			it->second.pop();
		}
	}

	hapticSignalBuffer.clear();
}

void Lilliputian::HapticSystem::process(
	Scene& scene,
	HumanInterfaceDevices& hid)
{
	this->rumble(scene.getHapticSignalBuffer(), hid.getHaptics());
}