#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button("", "", true, px, py)
{
	this->isPause = false; //게임 동작중(일시정지 아님)
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
	cout << "게임 일시정지 버튼" << endl;

	if (isPause == true)  //일시정지
	{
		Time::timeScale = 1;
		isPause = false;    //게임동작중
	}
	else //동작중
	{
		Time::timeScale = 0; //일시 정지
		isPause = true;      //게임 일시 정지
	}
}