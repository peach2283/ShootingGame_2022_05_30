#include "ShootingGame.h"

GameBG::GameBG(string tag, string name, bool active, float px, float py)
		:Sprite(tag, name, active, px, py)
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
