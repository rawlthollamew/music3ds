#pragma once
#include <string>
#include <3ds.h>
#include <citro2d.h>

struct Vector2f
{
	float x;
	float y;
};

struct Vector2i
{
	int x;
	int y;
};

const Vector2i topScreen    = { 400, 240 };
const Vector2i bottomScreen = { 320, 240 };