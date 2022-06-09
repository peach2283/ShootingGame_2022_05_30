#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->index		= 0;

	this->animTimer = 0;
	this->animDelay = 1 / 15.0f;
}

Animation::~Animation()
{}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height)
{
	Image img;

	BMP::ReadBMP(fileName, x, y, width, height, &img);
	sprites.push_back(img);
}

void Animation::Draw()
{
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px, py, &sprites[ index ]);

	//이미지 인덱스..변경..시간 측정//
	animTimer = animTimer + Time::deltaTime;

	if (animTimer >= animDelay)
	{
		index++;

		if ( index >= sprites.size() )
		{
			index = 0;
		}

		animTimer = 0;  //타이머..리셋
	}
}