#include "ShootingGame.h"

GameBG::GameBG(float px, float py) : Sprite("", "", true, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::Start()
{
	//���ö�����Ʈ �̹���..�ε��ϱ�
	SetSprite("Asset/���ӹ��.bmp");
}

void GameBG::Update()
{}
