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

#include "ui_viewport.hpp"
#include <os/os.hpp>

Lilliputian::UIViewport::UIViewport()
{
	this->dimensions = OS::getWindow().getWindowSize();
}

Lilliputian::EntityID Lilliputian::UIViewport::getCameraEntityID()
{
	return this->cameraEntityID;
}

void Lilliputian::UIViewport::setCameraEntity(EntityID cameraEntityID)
{
	this->cameraEntityID = cameraEntityID;
}

Lilliputian::Rectangle Lilliputian::UIViewport::getDimensions()
{
	return  this->dimensions;
}

bool Lilliputian::UIViewport::getIsVisibleToOtherCameras()
{
	return this->isVisibleToOtherCameras;
}

bool Lilliputian::UIViewport::getIsVisible()
{
	return this->isVisible;
}

void Lilliputian::UIViewport::setDimensions(uint32_t width, uint32_t height)
{
	this->dimensions.width = width;
	this->dimensions.height = height;
}

void Lilliputian::UIViewport::setVisibleToOtherCameras()
{
	this->isVisibleToOtherCameras = true;
}

void Lilliputian::UIViewport::setInvisibleToOtherCameras()
{
	this->isVisibleToOtherCameras = false;
}

void Lilliputian::UIViewport::setVisible()
{
	this->isVisible = true;
}

void Lilliputian::UIViewport::setInvisible()
{
	this->isVisible = false;
}