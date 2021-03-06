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

#include "rendering_context.hpp"
#include <os/os.hpp>
#include <string>

Lilliputian::RenderingContext::RenderingContext(Window& window)
{
	this->glContext = SDL_GL_CreateContext(window.getSDLWindow());

	if (!gladLoadGL())
	{
		OS::getLogger().write("GLAD failed to initialize.");
	}
	else
	{
		Window& window = OS::getWindow();
		Rectangle windowDimensions = window.getWindowSize();
		glViewport(0, 0, windowDimensions.width, windowDimensions.height);
		std::string renderinContextString = "Rendering System initialized with ";
		OS::getLogger().write(renderinContextString + "OpenGL " + (char*)glGetString(GL_VERSION));
	}
}

void Lilliputian::RenderingContext::clearBuffers()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Lilliputian::RenderingContext::generate2DTextures(std::vector<Image> images)
{
	size_t imageCount = images.size();
	Image* imageData = images.data();

	for (int i = 0; i < imageCount; i++)
	{
		float borderColour[] = { 1.0, 1.0, 0.0, 1.0 };
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE, texture);
		this->glTextureIDs.push_back(texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		uint64_t format = 0;
		Image* currentImage = &imageData[i];

		switch (currentImage->getBytesPerPixel())
		{
		case 3: format = GL_RGB; break;
		case 4: format = GL_RGBA; break;
		}

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			currentImage->getWidth(),
			currentImage->getHeight(),
			0,
			format,
			GL_UNSIGNED_BYTE,
			currentImage->getSDLSurface()->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

void Lilliputian::RenderingContext::delete2DTextures()
{
	int size = this->glTextureIDs.size();

	for (int i = 0; i < size; i++)
		glDeleteTextures(1, &glTextureIDs.at(i));

	this->glTextureIDs.clear();
}

void Lilliputian::RenderingContext::drawArrays()
{
	glBindVertexArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}