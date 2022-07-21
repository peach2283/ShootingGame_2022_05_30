#include "ShootingGame.h"

Button::Button(string tag, string name, bool active, float px, float py, int layer)
	   :GameObject(tag, name, active, px, py, layer)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::Start()
{
	//이미지 버튼..로드하기
	BMP::ReadBMP("Asset/UI/Button/Pause.bmp", &normalImg);  //버튼의 기본이미지 로드
}

void Button::Update()
{
	switch (state)
	{
		case State::normal:
		{
			cout << "normal 상태" << endl;

			if (CheckMouseInRect() == true)
			{
				state = State::hover;
			}

		}
		break;

		case State::hover:
		{
			cout << "hover 상태 " << endl;

			if (Input::GetMouseButtonDown(0) == true)
			{
				state = State::press;
			}
		
		}
		break;

		case State::press:
		{
			cout << "Press 상태 " << endl;

			if (Input::GetMouseButtonUp(0) == true)
			{
				state = State::release;
			}

		}
		break;

		case State::release:
		{
			cout << "Release 상태 " << endl;
		
			//버튼의 상태를..처음부터 다시 동작 시키기
			state = State::normal;
		}

		break;
	}

	//마우스 눌림 검사하기//
	/*************************************************
	if (Input::GetMouseButtonDown(0) == true)
	{
		
	}
	*****************************************************/
}

void Button::Draw()
{
	float px, py;
	GetPosition(px, py);

	BMP::DrawBMP(px, py, &normalImg);
}

bool Button::CheckMouseInRect()
{
	//마우스 좌표 가져오기
	int mx = Input::mousePosition.x;
	int my = Input::mousePosition.y;

	//이미지의 왼쪽상단 좌표
	float px, py;
	GetPosition(px, py);

	//이미지 가로/세로 크기
	int width  = normalImg.width;
	int height = normalImg.height;

	//마우스 이미지 영역검사
	if (px < mx && mx < px + width && py < my && my < py + height)
	{
		return true;
	}
	else {
		return false;
	}
}
