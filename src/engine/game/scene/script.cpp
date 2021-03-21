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

#include "script.hpp"

Lilliputian::Script::Script(ScriptingAPIs* scriptingAPIs, const char* scriptName)
{
	this->scriptingAPIs = scriptingAPIs;
	this->name = scriptName;

	this->startLogic = nullptr;
	this->inputLogic = nullptr;
	this->frameLogic = nullptr;
	this->computeLogic = nullptr;
	this->lateLogic = nullptr;
	this->finalLogic = nullptr;
}

void Lilliputian::Script::addStartLogic(ScriptLogicCallback startLogic)
{
	this->startLogic = startLogic;
}

void Lilliputian::Script::addInputLogic(ScriptLogicCallback inputLogic)
{
	this->inputLogic = inputLogic;
}

void Lilliputian::Script::addFrameLogic(ScriptLogicCallback frameLogic)
{
	this->frameLogic = frameLogic;
}

void Lilliputian::Script::addComputeLogic(ScriptLogicCallback computeLogic)
{
	this->computeLogic = computeLogic;
}

void Lilliputian::Script::addLateLogic(ScriptLogicCallback lateLogic)
{
	this->lateLogic = lateLogic;
}
void Lilliputian::Script::addFinalLogic(ScriptLogicCallback finalLogic)
{
	this->finalLogic = finalLogic;
}

void Lilliputian::Script::executeStartLogic()
{
	if (this->startLogic != nullptr)
		this->startLogic(*this->scriptingAPIs);
}

void Lilliputian::Script::executeInputLogic()
{
	if (this->inputLogic != nullptr)
		this->inputLogic(*this->scriptingAPIs);
}

void Lilliputian::Script::executeFrameLogic()
{
	if (this->frameLogic != nullptr)
		this->frameLogic(*this->scriptingAPIs);
}

void Lilliputian::Script::executeComputeLogic()
{
	if (this->computeLogic != nullptr)
		this->computeLogic(*this->scriptingAPIs);
}

void Lilliputian::Script::executeLateLogic()
{
	if (this->lateLogic != nullptr)
		this->lateLogic(*this->scriptingAPIs);
}

void Lilliputian::Script::executeFinalLogic()
{
	if (this->finalLogic != nullptr)
		this->finalLogic(*this->scriptingAPIs);
}