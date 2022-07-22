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
	BMP::ReadBMP("Asset/UI/Menu/normal.bmp", &normalImg);  //버튼의 기본이미지 로드
	BMP::ReadBMP("Asset/UI/Menu/hover.bmp",  &hoverImg);   //버튼의 호버이미지 로드
	BMP::ReadBMP("Asset/UI/Menu/active.bmp", &pressImg);   //버튼의 눌림이미지 로드
}

void Button::Update()
{
	switch (state)
	{
		case State::normal:
		{
			//cout << "normal 상태" << endl;

			if (CheckMouseInRect() == true)
			{
				state = State::hover;
			}
		}
		break;

		case State::hover:
		{
			//cout << "hover 상태 " << endl;

			if (Input::GetMouseButtonDown(0) == true) //마우스가 눌리면..press 상태
			{
				state = State::press;

				//이미지의 눌림효과를 위해서..좌표 이동시켜보기///
				Translate(0, 1);
			}
			
			if (CheckMouseInRect() == false) //마우스가 영역밖으로..나가면..normal 상태
			{
				state = State::normal;
			}		
		}
		break;

		case State::press:
		{
			//cout << "Press 상태 " << endl;

			if (Input::GetMouseButtonUp(0) == true)
			{
				state = State::release;

				//이미지 놓임 효과를 위해서..좌표 이동시키기///
				Translate(0, -1);
			}

			if (CheckMouseInRect() == false) //마우스가 영역밖으로..나가면..normal 상태
			{
				state = State::normal;

				//이미지 놓임 효과를 위해서..좌표 이동시키기///
				Translate(0, -1);
			}
		}
		break;

		case State::release:
		{
			//cout << "Release 상태 " << endl;
		
			//버튼 클릭 동작..실행하기//
			cout << "이미지 버튼 클릭 .. 동작 실행하기" << endl;

			//버튼의 상태를..처음부터 다시 동작 시키기
			state = State::normal;
		}

		break;
	}
}

void Button::Draw()
{
	float px, py;
	GetPosition(px, py);

	if (state == State::normal || state == State::release )
	{
		BMP::DrawBMP(px, py, &normalImg);
	}
	else if (state == State::hover)
	{
		BMP::DrawBMP(px, py, &hoverImg);
	}
	else if (state == State::press)
	{
		BMP::DrawBMP(px, py, &pressImg);
	}
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

void Button::SetNormalImg(const char* fileName)
{
	BMP::ReadBMP(fileName, &normalImg);
}

void Button::SetHoverImg(const char* fileName)
{
	BMP::ReadBMP(fileName, &hoverImg);
}

void Button::SetPressImg(const char* fileName)
{
	BMP::ReadBMP(fileName, &pressImg);
}