#include "ShootingGame.h"

PlayerIcon::PlayerIcon(float px, float py) : Sprite("", "", true, px, py, 5)
{}

PlayerIcon::~PlayerIcon()
{}

void PlayerIcon::Start()
{
	SetSprite("Asset/UI/Icon/PlayerIcon.bmp");
}

void PlayerIcon::Update()
{}
