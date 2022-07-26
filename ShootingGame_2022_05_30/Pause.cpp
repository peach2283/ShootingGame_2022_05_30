#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button("", "", true, px, py)
{	
}

Pause::~Pause()
{}

void Pause::Start()
{
	//버튼 이미지 로드하기
	SetNormalImg("Asset/UI/Button/Pause.bmp");
	SetHoverImg ("Asset/UI/Button/Pause.bmp");
	SetPressImg ("Asset/UI/Button/Pause.bmp");
}

void Pause::OnClick()
{
	GameManager* manager = GameManager::Instance();

	if (manager->GetPause() == true)  //일시정지
	{
		Time::timeScale = 1;
		manager->SetPause(false);    //게임동작중
	}
	else //동작중
	{
		Time::timeScale = 0; //일시 정지
		manager->SetPause(true);     //게임 일시 정지
	}
}