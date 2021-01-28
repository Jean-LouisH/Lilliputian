#pragma once

#include <SDL.h>
#include "utilities/collections/vector.hpp"
#include "utilities/collections/map.hpp"

namespace Lilliputian
{
	class Window
	{
	public:
		Window(const char* title, uint16_t width, uint16_t height, bool isFullscreen);
		void setToWindowed(uint16_t width_px, uint16_t height_px);
		void setToFullscreen(SDL_DisplayMode* mode);
		void toggleWindowedFullscreen();
		void resizeWindow(uint16_t width_px, uint16_t height_px);
		void changeTitle(const char* title);
		void sleep(int time_ms);

		SDL_Window* getSDLWindow();
	private:
		SDL_Window* sdlWindow;
		bool isFullscreen;
	};
}