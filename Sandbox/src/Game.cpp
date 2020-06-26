#include <Lightning.h>

Lightning::Application* Lightning::CreateApplication() {
	return new Lightning::Application("My Test Game", 1200, 900);
}