#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->index = 0;
}

Animation::~Animation()
{}

void Animation::Start()
{
	//�ִϸ��̼� �̹��� �ε��ϱ�//
	BMP::ReadBMP("Asset/����.bmp", 1 + 200 * 0 , 141, 190, 137, &sprites[0]);
	BMP::ReadBMP("Asset/����.bmp", 1 + 200 * 1 , 141, 190, 137, &sprites[1]);
	BMP::ReadBMP("Asset/����.bmp", 1 + 200 * 2 , 141, 190, 137, &sprites[2]);
	BMP::ReadBMP("Asset/����.bmp", 1 + 200 * 3 , 141, 190, 137, &sprites[3]);
}

void Animation::Draw()
{
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px, py, &sprites[ index ]);

	index++;

	if (index >= 4)
	{
		index = 0;
	}
}