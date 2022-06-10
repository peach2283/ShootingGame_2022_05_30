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
	this->clip  = clipId;//�ִϸ��̼� �����ϱ�
	this->index = 0;      //�ִϸ��̼���..�̹����� 0 ������..����
}

void Animation::Draw()
{
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px, py, &sprites[   clip   ][ index ]);

	//�̹��� �ε���..����..�ð� ����//
	animTimer = animTimer + Time::deltaTime;

	if (animTimer >= animDelay)
	{
		index++;

		if ( index >= sprites[    clip     ].size() )
		{
			index = 0;
		}

		animTimer = 0;  //Ÿ�̸�..����
	}
}