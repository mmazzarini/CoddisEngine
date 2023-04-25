#pragma once

#ifdef CODDIS_PLATFORM_WINDOWS

extern CoddisEngine::Application* CoddisEngine::CreateApplication();

int main(int argc, char** argv)
{ 
	CoddisEngine::Log::Init();
	CODDIS_CORE_WARN("Initialized log!\n");
	int a = 6;
	APP_CLIENT_INFO("Hello from Client! Var={0}\n",a);
	//printf("Li mortacci, benvenuto in Coddis Engine!\n");
	auto App = CoddisEngine::CreateApplication();
	App->Run();
	delete App;
}
#endif 