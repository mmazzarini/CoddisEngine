#include <CoddisEngine.h>

//This class derives from Coddis::Application, so we include Coddis
//libraries to derive it and create a new one
class Sandbox : public CoddisEngine::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

CoddisEngine::Application* CoddisEngine::CreateApplication()
{
	return new Sandbox;
}