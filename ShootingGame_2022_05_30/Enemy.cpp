#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Sprite("","", true, px, py)
{}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	//�̹��� �ε��ϱ�
	SetSprite("Asset/����.bmp");
}

void Enemy::Update()
{}
