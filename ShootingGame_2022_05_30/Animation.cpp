#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py, int layer)
		 :GameObject(tag, name, active, px, py, layer)
{
	this->index = 0;
	this->clip  = 0;

	this->animTimer = 0;
	this->animDelay = 1 / 15.0f;
	this->speed     = 1;

	this->loop = true; //�ִϸ��̼� ���� ����
}

Animation::~Animation()
{
	//�ε��..�ִϸ��̼� �̹�����..�޸� ����//
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < sprites[i].size(); j++)
		{
			delete[] sprites[i][j].argb;  //i ��° �迭��...j ��° vector ���(�̹���)�� �޸� ����
		}
	}
}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height, int clipId, float pvx, float pvy)
{
	Image img;

	//�̹��� �ε�
	BMP::ReadBMP(fileName, x, y, width, height, &img);

	//�Ǻ� �Ű����� ����
	img.pvx = pvx;
	img.pvy = pvy;

	//�ִϸ��̼� �̹�����..�߰���
	sprites[clipId].push_back(img);
}

void Animation::AddSprite(const char* fileName, int clipId, float pvx, float pvy)
{
	Image img;

	//�̹���..�ε��ϱ�
	BMP::ReadBMP(fileName, &img);

	//�Ǻ� �Ű����� ����
	img.pvx = pvx;
	img.pvy = pvy;

	//�ִϸ��̼� �̹�����..�߰�
	sprites[clipId].push_back(img);
}

void Animation::Play(int clipId)
{
	if (this->clip != clipId)  //����..������� �ִϸ��̼ǰ� �ٸ��ɷ�..�ٲܰ�츸
	{
		this->clip = clipId;  //�ִϸ��̼� �����ϱ�
		this->index = 0;      //�ִϸ��̼���..�̹����� 0 ������..����
	}
}

void Animation::SetLoop(bool loop)
{
	this->loop = loop;
}

void Animation::SetSpeed(float speed)
{
	this->speed = speed;
}

void Animation::Draw()
{
	//�̹���..�Ǻ�
	float pvx = sprites[clip][index].pvx;
	float pvy = sprites[clip][index].pvy;

	//���� ��ü ��ǥ(position)
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px - pvx, py - pvy, &sprites[   clip   ][ index ]);

	//�̹��� �ε���..����..�ð� ����//
	animTimer = animTimer + Time::deltaTime * speed;

	if (animTimer >= animDelay)
	{
		index++;

		if ( index >= sprites[ clip ].size() )  //������..�̹����� ����
		{
			//�ִϸ��̼���..������..�̹����� ��������...�˷��ִ� �̺�Ʈ �����//
			OnAnimationEnd();

			if (loop == true)  //������ �� ���
			{
				index = 0; //ó�� �̹�����..��
			}
			else {
				index = sprites[clip].size() - 1; //������ �̹����� ..������
			}
		}

		animTimer = 0;  //Ÿ�̸�..����
	}
}

void Animation::OnAnimationEnd()
{
}