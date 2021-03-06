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

#include "audio_stream.hpp"
#include <application/scene/id_counter.hpp>


Lilliputian::AudioStream::AudioStream()
{

}

Lilliputian::AudioStream::AudioStream(const char* filepath)
{
	this->sound = Mix_LoadWAV(filepath);
	this->id = IDCounter::getNewAssetID();
}

Mix_Chunk* Lilliputian::AudioStream::getSDLMixChunk()
{
	return this->sound;
}

Lilliputian::AssetID Lilliputian::AudioStream::getID()
{
	return this->id;
}

void Lilliputian::AudioStream::unload()
{
	Mix_FreeChunk(this->sound);
}