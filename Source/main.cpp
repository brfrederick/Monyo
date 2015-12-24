#include <Windows.h>
#include "Core\Game.h"
#include "Core\GameWindow.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd) {
	WindowSettings settings;
	settings.width = 1360;
	settings.height = 768;
	settings.minimized = false;
	settings.maximized = false;
	settings.resizing = false;
	settings.title = "Monyo App Title";

	Game game;

	if (game.InitWindow(settings, hInstance) != 0) {
		return -1;
	}

	return game.Run();
}
