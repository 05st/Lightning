#include <Lightning.h>

class Game : public Lightning::Application {
public:
	Game() {

	}

	~Game() {

	}
};

Lightning::Application* Lightning::CreateApplication() {
	return new Game();
}