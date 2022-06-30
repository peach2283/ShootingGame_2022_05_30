#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("", "", true, px, py)
{}

Shield::~Shield()
{}

void Shield::Start()
{
	//애니메이션 이미지 추가하기
	AddSprite("Asset/보호방패1.bmp", 0);
	AddSprite("Asset/보호방패2.bmp", 0);
	AddSprite("Asset/보호방패3.bmp", 0);
}

void Shield::Update()
{}
