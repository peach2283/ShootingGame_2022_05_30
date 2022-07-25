#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button("", "", true, px, py)
{
	this->isPause = false; //���� ������(�Ͻ����� �ƴ�)
}

Pause::~Pause()
{}

void Pause::Start()
{
	//��ư �̹��� �ε��ϱ�
	SetNormalImg("Asset/UI/Button/Pause.bmp");
	SetHoverImg ("Asset/UI/Button/Pause.bmp");
	SetPressImg ("Asset/UI/Button/Pause.bmp");
}

void Pause::OnClick()
{
	cout << "���� �Ͻ����� ��ư" << endl;

	if (isPause == true)  //�Ͻ�����
	{
		Time::timeScale = 1;
		isPause = false;    //���ӵ�����
	}
	else //������
	{
		Time::timeScale = 0; //�Ͻ� ����
		isPause = true;      //���� �Ͻ� ����
	}
}