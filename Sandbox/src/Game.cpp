#include <Lightning.h>

using namespace Lightning;

Application* myApplication;

void DrawStuff() {
	Lightning::Rectangle ok = Lightning::Rectangle(new Vector2(0.2f, 0.5f), new Vector2(0.5f, 0.2f), new Color(1.0f, 0.0f, 0.0f, 0.0f), myApplication->GetRenderer());
	Lightning::Rectangle ok2 = Lightning::Rectangle(new Vector2(0.3f, 0.2f), new Vector2(0.1f, 0.3f), new Color(1.0f, 0.0f, 0.0f, 0.0f), myApplication->GetRenderer());
}

Application* Lightning::CreateApplication() {
	myApplication = new Application("yeeeeeeeeeeeeeeeeeeeeeet");
	DrawStuff();
	return myApplication;
}