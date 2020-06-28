#include <Lightning.h>

using namespace Lightning;

Application* Lightning::CreateApplication() {
	Application* myApplication = new Application("My Test Game", 1200, 900);
	Square square = Square(myApplication->GetRenderer());
	return myApplication;
}