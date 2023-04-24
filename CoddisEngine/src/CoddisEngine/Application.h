#pragma once
#include "Core.h"

namespace CoddisEngine {

	class CODDIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Defined in client
	Application* CreateApplication();
}
