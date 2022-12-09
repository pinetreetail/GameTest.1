#pragma once

#include "game.h"
#include "DxLib.h"

#include "Shot.h"

struct Player
{
public:
	Player();
	virtual ~Player();

	void init();
	void update(Shot shot);
	void draw();

private:
	float posX;
	float posY;
	float sizeOutside;
	float sizeInside;

	float speedMax;
	float Acc;
	float currSpeedX;
	float currSpeedY;

	bool Dead;

};

