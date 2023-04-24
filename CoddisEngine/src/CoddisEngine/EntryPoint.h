#pragma once

#ifdef CODDIS_PLATFORM_WINDOWS

extern CoddisEngine::Application* CoddisEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Li mortacci, benvenuto in Coddis Engine!\n");
	auto App = CoddisEngine::CreateApplication();
	App->Run();
	delete App;
}
#endif 