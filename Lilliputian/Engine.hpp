#pragma once

#include "Utilities/Collections/Vector.hpp"
#include "Utilities/String.hpp"
#include "Game/Game.hpp"
#include "Engines/AIEngine/AIEngine.hpp"
#include "Engines/AnimationEngine/AnimationEngine.hpp"
#include "Engines/AudioEngine/AudioEngine.hpp"
#include "Engines/HapticEngine/HapticEngine.hpp"
#include "Engines/PhysicsEngine/PhysicsEngine.hpp"
#include "Engines/RenderingEngine/RenderingEngine.hpp"
#include "OSWindow.hpp"
#include "Platform.hpp"
#include "EngineState.hpp"
#include "Profiler.hpp"

namespace Lilliputian
{
	using SceneDefinerCallback = void(*)(Lilliputian::EditorAPI*);

	class Engine
	{
	private:
		Vector<SceneDefinerCallback> sceneDefinerCallbacks;
		Game* game;
		AIEngine* aiEngine;
		AnimationEngine* animationEngine;
		AudioEngine* audioEngine;
		HapticEngine* hapticEngine;
		PhysicsEngine* physicsEngine;
		RenderingEngine* renderingEngine;
		OSWindow* osWindow;
		Platform* platform;
		Profiler* profiler;
		uint64_t frameCount;
		uint16_t FPS;
		EngineState state;
		uint32_t msPerComputeUpdate;
		uint32_t targetFPS;
		String gameTitle;
		uint16_t windowHeight;
		uint16_t windowWidth;
		bool isStartingFullscreen;

		void initialize();
		void input();
		void logic();
		void compute();
		void output();
		void sleep();
		void shutdown();
	public:
		Engine();
		~Engine();

		void runGame();
		void setGameTitle(const char* gameTitle);
		void setWindowDimensions(uint16_t width, uint16_t height);
		void setMillisecondsPerComputeUpdate(uint32_t msPerComputeUpdate);
		void setTargetFPS(uint32_t targetFPS);
		void setFullscreenStart(bool value);
		void addSceneDefiner(SceneDefinerCallback sceneInitializerCallback);
	};
}

