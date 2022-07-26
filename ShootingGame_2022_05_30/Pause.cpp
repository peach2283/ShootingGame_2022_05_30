#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button("", "", true, px, py)
{	
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
	GameManager* manager = GameManager::Instance();

	if (manager->GetPause() == true)  //�Ͻ�����
	{
		Time::timeScale = 1;
		manager->SetPause(false);    //���ӵ�����
	}
	else //������
	{
		Time::timeScale = 0; //�Ͻ� ����
		manager->SetPause(true);     //���� �Ͻ� ����
	}
}