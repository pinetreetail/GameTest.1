#pragma once

#include "game.h"
#include "DxLib.h"

#include "Player.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void init();
	void update();
	void draw();

private:
	float posX;
	float posY;
	float size;

	float speed;

	bool Dead;

};

