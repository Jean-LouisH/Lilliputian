#pragma once

#include "../../ScriptingAPIs/ScriptingAPIs.hpp"
#include "../../Utilities/String.hpp"

namespace Lilliputian
{
	using ScriptLogicCallback = void(*)(Lilliputian::ScriptingAPIs&);

	class Script
	{
	private:
		ScriptingAPIs* scriptingAPIs;

		ScriptLogicCallback startLogic;
		ScriptLogicCallback inputLogic;
		ScriptLogicCallback frameLogic;
		ScriptLogicCallback computeLogic;
		ScriptLogicCallback lateLogic;
		ScriptLogicCallback finalLogic;
	public:
		Script(ScriptingAPIs* scriptingAPI, const char* scriptName);

		String name;

		void addStartLogic(ScriptLogicCallback startLogic);
		void addInputLogic(ScriptLogicCallback inputLogic);
		void addFrameLogic(ScriptLogicCallback frameLogic);
		void addComputeLogic(ScriptLogicCallback computeLogic);
		void addLateLogic(ScriptLogicCallback lateLogic);
		void addFinalLogic(ScriptLogicCallback finalLogic);

		void executeStartLogic();
		void executeInputLogic();
		void executeFrameLogic();
		void executeComputeLogic();
		void executeLateLogic();
		void executeFinalLogic();
	};
}