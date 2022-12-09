#include "DxLib.h"

#include "game.h"

struct Player
{
	float posX;
	float posY;
	float sizeOutside;
	float sizeInside;

	float speedMax;
	float Acc;
	float currSpeedX;
	float currSpeedY;

	bool Dead;

	int space;
	int ShotStop;
};

class Virus
{
	float posX;
	float posY;
	float sizeOutside;
	float sizeInside;

	float speed;

	int ColorOutside;
	int ColorInside;

	bool Dead;
};

class Shot
{
	float posX;
	float posY;
	float size;

	float speed;

	bool Dead;
};

void PlayerInit(Player& player);
void PlayerUpdate(Player& player);
void PlayerDraw(Player& player);

void VirusInit(Virus& virus);
void VirusUpdate(Virus& virus);
void VirusDraw(Virus& virus);

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;

	Virus virus;

	Shot shot;
	
	
	

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();
		

		
		

		// 裏画面を表画面に入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fpsを６０に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void PlayerInit(Player& player)
{
	player.sizeOutside = 70;
	player.sizeInside = 20;

	player.posX = (Game::kScreenWidth / 2) - (player.sizeOutside / 2);
	player.posY = (Game::kScreenHeight / 2) - (player.sizeOutside / 2);

	player.speedMax = 7;
	player.Acc = 4;

	player.Dead = false;

	player.space = 0;
	player.ShotStop = 30;
}

void PlayerUpdate(Player& player)
{
	if (player.Dead)	return;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	{
		if (padState & PAD_INPUT_LEFT)
		{
			player.currSpeedX -= player.Acc;
			if (player.currSpeedX < -player.speedMax)	player.currSpeedX = -player.speedMax;
		}
		else if (padState & PAD_INPUT_RIGHT)
		{
			player.currSpeedX += player.Acc;
			if (player.currSpeedX > player.speedMax)	player.currSpeedX = player.speedMax;
		}
		if (padState & PAD_INPUT_UP)
		{
			player.currSpeedY -= player.Acc;
			if (player.currSpeedY < -player.speedMax)	player.currSpeedY = -player.speedMax;
		}
		else if (padState & PAD_INPUT_DOWN)
		{
			player.currSpeedY += player.Acc;
			if (player.currSpeedY > player.speedMax)	player.currSpeedY = player.speedMax;
		}
		else
		{
			player.currSpeedX *= 0.9f;
			player.currSpeedY *= 0.9f;
		}

		player.posX += player.currSpeedX;
		player.posY += player.currSpeedY;

		if (player.posX < 0)	player.posX = 0;
		if (player.posX > Game::kScreenWidth - player.sizeOutside)	player.posX = (Game::kScreenWidth - player.sizeOutside);
		if (player.posY < 0)	player.posY = 0;
		if (player.posY > Game::kScreenHeight - player.sizeOutside)	player.posY = (Game::kScreenHeight - player.sizeOutside);
	}

	player.ShotStop--;

	if (padState & PAD_INPUT_START && player.ShotStop == 0)
	{
		if (player.space > 0)
		{
			player.space = -1;
			for (int i = 0; i < 10; i++)
			{





			}

			player.ShotStop = 30;
		}
		else
		{
			player.space = 0;
		}
	}

}