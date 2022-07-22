#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button("", "", true, px, py)
{}

Pause::~Pause()
{}

void Pause::Start()
{
	//버튼 이미지 로드하기
	SetNormalImg("Asset/UI/Button/Pause.bmp");
	SetHoverImg ("Asset/UI/Button/Pause.bmp");
	SetPressImg ("Asset/UI/Button/Pause.bmp");
}
