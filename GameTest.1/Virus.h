#pragma once

#include "game.h"
#include "DxLib.h"

class Virus
{
public:
	Virus();
	virtual ~Virus();

	void init();
	void update();
	void draw();

private:
	float posX;
	float posY;
	float sizeOutside;
	float sizeInside;

	float speed;

	int ColorOutside;
	int ColorInside;

	bool Dead;

};

