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
	//�̹��� ��ư..�ε��ϱ�
	BMP::ReadBMP("Asset/UI/Button/Pause.bmp", &normalImg);  //��ư�� �⺻�̹��� �ε�
}

void Button::Update()
{
	switch (state)
	{
		case State::normal:
		{
			cout << "normal ����" << endl;

			if (CheckMouseInRect() == true)
			{
				state = State::hover;
			}

		}
		break;

		case State::hover:
		{
			cout << "hover ���� " << endl;

			if (Input::GetMouseButtonDown(0) == true)
			{
				state = State::press;
			}
		
		}
		break;

		case State::press:
		{
			cout << "Press ���� " << endl;

			if (Input::GetMouseButtonUp(0) == true)
			{
				state = State::release;
			}

		}
		break;

		case State::release:
		{
			cout << "Release ���� " << endl;
		
			//��ư�� ���¸�..ó������ �ٽ� ���� ��Ű��
			state = State::normal;
		}

		break;
	}

	//���콺 ���� �˻��ϱ�//
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
	//���콺 ��ǥ ��������
	int mx = Input::mousePosition.x;
	int my = Input::mousePosition.y;

	//�̹����� ���ʻ�� ��ǥ
	float px, py;
	GetPosition(px, py);

	//�̹��� ����/���� ũ��
	int width  = normalImg.width;
	int height = normalImg.height;

	//���콺 �̹��� �����˻�
	if (px < mx && mx < px + width && py < my && my < py + height)
	{
		return true;
	}
	else {
		return false;
	}
}
