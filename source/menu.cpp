#include "menu.h"

Menu::Menu(std::vector<std::string> _songs)
	: songs(_songs)
{
	selection = 0;
}

void Menu::print()
{
	// width of the console is 40 characters, the selection things take 2 and some other character is there so this is the max length of the song before it wraps around onto the next line
	int consoleWidth = 37;

	for (int i = 0; i < (int)(songs.size()); i++)
	{
		std::string songName = songs[i];

		for (int j = 0; j < (int)(songName.length()); j += consoleWidth)
		{
			std::string line = songName.substr(j, consoleWidth);
			if (selection == i && j == 0) 	printf("> %s\n", line.c_str());
			else 							printf("  %s\n", line.c_str());
		}
	}
}

void Menu::update()
{
	u32 kDown = hidKeysDown();

	if ((kDown & KEY_UP) && selection > 0)
	{
		selection -= 1;
	}
	else if ((kDown & KEY_DOWN) && selection < (int)(songs.size() - 1))
	{
		selection += 1;
	}
}