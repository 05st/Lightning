#include <Lightning.h>

using namespace Lightning;

Application* Lightning::CreateApplication() {
	Application* myApplication = new Application("My Test Game", 1200, 900);
	Rectangle ok = Rectangle(new Vector2(0.2f, 0.5f), new Vector2(0.5f, 0.2f), new Color(1.0f, 0.0f, 0.0f, 0.0f), myApplication->GetRenderer());
	Rectangle ok2 = Rectangle(new Vector2(0.3f, 0.2f), new Vector2(0.1f, 0.3f), new Color(1.0f, 0.0f, 0.0f, 0.0f), myApplication->GetRenderer());
	return myApplication;
}