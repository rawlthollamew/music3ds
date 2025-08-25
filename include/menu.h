#pragma once

#include <3ds.h>
#include <citro2d.h>
#include <citro3d.h>
#include <stdio.h>
#include <vector>
#include <string>

class Menu
{
public:
	Menu(std::vector<std::string> _songs);
	void print();
	void update();
private:
	std::vector<std::string> songs;
	int selection;
};