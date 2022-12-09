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

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�C���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;

	Virus virus;

	Shot shot;
	
	
	

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();
		

		
		

		// ����ʂ�\��ʂɓ���ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fps���U�O�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
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