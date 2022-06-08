#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Sprite("","", true, px, py)
{}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	//이미지 로드하기
	SetSprite("Asset/적기.bmp", 201, 141, 190, 137);
}

void Enemy::Update()
{}
