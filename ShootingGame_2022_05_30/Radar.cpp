#include "ShootingGame.h"

Radar::Radar(float px, float py) : Sprite("", "", true, px, py, 2)
{}

Radar::~Radar()
{}

void Radar::Start()
{
	SetSprite("Asset/����.bmp", 360, 245, 11, 9);
}

void Radar::Update()
{}
