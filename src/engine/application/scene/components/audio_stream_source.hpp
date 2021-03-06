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

#pragma once

#include "utilities/aliases.hpp"
#include <set>
#include <queue>
#include "utilities/constants.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include "application/scene/assets/audio_stream.hpp"


namespace Lilliputian
{
	class AudioStreamSource
	{
	public:
		void addAudioStream(AudioStream audioStream);
		void queueAudioToPlay(std::string audioStreamName, uint8_t count);
		void clearAudioStreams();
		std::queue<AudioStream> popEntireAudioPlayQueue();
		void clearAudioPlayQueue();
		void play(std::string audioStreamName);
		void play();
		void pause();
		void stop();
		std::vector<std::string> getAudioStreamNames();
		AudioStream getAudioStreamByName(std::string audioStreamName);
	private:
//		Map<String, AudioStream> audioStreams;
		std::queue<AudioStream> audioPlayQueue;
		bool isPlaying = false;
	};
}