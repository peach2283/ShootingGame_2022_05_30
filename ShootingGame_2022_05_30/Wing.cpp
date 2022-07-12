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
	//���� �̹��� �ε��ϱ�//
	SetSprite("Asset/����.bmp", x, y, width, height);
}

void Wing::Update()
{}