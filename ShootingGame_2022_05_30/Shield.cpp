#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("방패", "방패", true, px, py, 3)
{}

Shield::~Shield()
{}

void Shield::Start()
{
	//애니메이션 이미지 추가하기
	AddSprite("Asset/보호방패1.bmp", 0);
	AddSprite("Asset/보호방패2.bmp", 0);
	AddSprite("Asset/보호방패3.bmp", 0);

	//방패 충돌체 추가하기
	AddBoxCollider2D(0, 0, 86, 90);
}

void Shield::Update()
{}
