#include "ShootingGame.h"

Button::Button(string tag, string name, bool active, float px, float py, int layer)
	   :GameObject(tag, name, active, px, py, layer)
{}

Button::~Button()
{}

void Button::Start()
{
	//이미지 버튼..로드하기
	BMP::ReadBMP("Asset/UI/Button/Pause.bmp", &normalImg);  //버튼의 기본이미지 로드
}

void Button::Update()
{
	//마우스 눌림 검사하기//
	if (Input::GetMouseButtonDown(0) == true)
	{
		cout << "마우스 버튼 눌림" << endl;
	}
}

void Button::Draw()
{
	float px, py;
	GetPosition(px, py);

	BMP::DrawBMP(px, py, &normalImg);
}