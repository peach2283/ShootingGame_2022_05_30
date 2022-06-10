#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->index = 0;
	this->clip  = 0;

	this->animTimer = 0;
	this->animDelay = 1 / 15.0f;
}

Animation::~Animation()
{}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height, int clipId)
{
	Image img;

	BMP::ReadBMP(fileName, x, y, width, height, &img);
	sprites[clipId].push_back(img);
}

void Animation::Play(int clipId)
{
	this->clip  = clipId;//애니메이션 변경하기
	this->index = 0;      //애니메이션의..이미지를 0 번부터..시작
}

void Animation::Draw()
{
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px, py, &sprites[   clip   ][ index ]);

	//이미지 인덱스..변경..시간 측정//
	animTimer = animTimer + Time::deltaTime;

	if (animTimer >= animDelay)
	{
		index++;

		if ( index >= sprites[    clip     ].size() )
		{
			index = 0;
		}

		animTimer = 0;  //타이머..리셋
	}
}