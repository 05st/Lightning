#pragma once

#ifdef LN_PLATFORM_WINDOWS
extern Lightning::Application* Lightning::CreateApplication();

int main(int argc, char** argv) {
	Lightning::Log::Init();

	auto application = Lightning::CreateApplication();
	application->Run();
	delete application;
}
#endif