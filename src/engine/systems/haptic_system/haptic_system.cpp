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

void Lilliputian::HapticSystem::rumble(HapticSignal& hapticSignal, std::vector<SDL_Haptic*> haptics)
{
	if (hapticSignal.getPlayerID() < haptics.size())
	{
		SDL_HapticRumblePlay(haptics.at(hapticSignal.getPlayerID()),
			hapticSignal.getStrength_pct(),
			hapticSignal.getDuration_ms());
	}
}

void Lilliputian::HapticSystem::stopRumble(PlayerID playerID, std::vector<SDL_Haptic*> haptics)
{
	if (playerID < haptics.size())
	{
		SDL_HapticRumbleStop(haptics.at(playerID));
	}
}

void Lilliputian::HapticSystem::process(
	Scene& scene,
	HumanInterfaceDevices& hid)
{
	HapticSignalBuffer& hapticSignalBuffer = scene.getHapticSignalBuffer();
	std::unordered_map<PlayerID, std::queue<HapticSignal>>& hapticSignals = hapticSignalBuffer.getHapticSignals();

	for (auto it = hapticSignals.begin(); it != hapticSignals.end(); it++)
	{
		PlayerID playerID = it->first;

		if (this->hapticPlaybacks.count(playerID))
		{
			HapticPlayback& hapticPlayback = this->hapticPlaybacks.at(playerID);
			std::queue<HapticSignal>& hapticSignalQueue = it->second;

			if (hapticPlayback.isPlaying)
			{
				hapticPlayback.timer.setEnd();

				if (hapticPlayback.timer.getDelta_ms() > hapticPlayback.duration_ms)
				{
					hapticPlayback.isPlaying = false;
					this->stopRumble(playerID, hid.getHaptics());
					hapticSignalQueue.pop();
				}
			}
			else
			{
				if (!hapticSignalQueue.empty())
				{
					HapticSignal& hapticSignal = hapticSignals.at(playerID).front();
					hapticPlayback.duration_ms = hapticSignal.getDuration_ms();
					hapticPlayback.timer.setStart();
					hapticPlayback.isPlaying = true;
					this->rumble(hapticSignal, hid.getHaptics());
				}
			}
		}
		else
		{
			HapticPlayback hapticPlayback;
			hapticPlayback.isPlaying = false;
			this->hapticPlaybacks.emplace(playerID, hapticPlayback);
		}
	}
}