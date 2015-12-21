#include <Windows.h>
#include "Core\App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd) {
	WindowSettings settings;
	settings.width = 800;
	settings.height = 600;
	settings.minimized = false;
	settings.maximized = false;
	settings.resizing = false;
	settings.title = "Monyo App Title";

	App app(settings, hInstance);

	if (app.Init() != 0) {
		return -1;
	}

	return app.Run();
}
