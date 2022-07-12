#include "ShootingGame.h"

Wing::Wing(int x, int y, int width, int height, float px, float py) : Sprite("", "", true, px, py, 2)
{
	this->x = x;
	this->y = y;
	this->width  = width;
	this->height = height;
}

Wing::~Wing()
{}

void Wing::Start()
{
	//날개 이미지 로드하기//
	SetSprite("Asset/보스.bmp", x, y, width, height);
}

void Wing::Update()
{}