#include "ShootingGame.h"

GameBG::GameBG(float px, float py) : Sprite("���ӹ��", "", true, px, py, 0)
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
