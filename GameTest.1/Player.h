#pragma once

#include "game.h"
#include "DxLib.h"

struct Player
{
public:
	Player();
	virtual ~Player();

	void init();
	void update();
	void draw();

private:
	float posX;
	float posY;
	float sizeOutside;
	float sizeInside;

	float speed;

};

