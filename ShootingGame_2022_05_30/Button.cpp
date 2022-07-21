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
	BMP::ReadBMP("Asset/UI/Menu/normal.bmp", &normalImg);  //��ư�� �⺻�̹��� �ε�
	BMP::ReadBMP("Asset/UI/Menu/hover.bmp",  &hoverImg);   //��ư�� ȣ���̹��� �ε�
	BMP::ReadBMP("Asset/UI/Menu/active.bmp", &pressImg);   //��ư�� �����̹��� �ε�
}

void Button::Update()
{
	switch (state)
	{
		case State::normal:
		{
			//cout << "normal ����" << endl;

			if (CheckMouseInRect() == true)
			{
				state = State::hover;
			}
		}
		break;

		case State::hover:
		{
			//cout << "hover ���� " << endl;

			if (Input::GetMouseButtonDown(0) == true) //���콺�� ������..press ����
			{
				state = State::press;
			}
			
			if (CheckMouseInRect() == false) //���콺�� ����������..������..normal ����
			{
				state = State::normal;
			}		
		}
		break;

		case State::press:
		{
			//cout << "Press ���� " << endl;

			if (Input::GetMouseButtonUp(0) == true)
			{
				state = State::release;
			}

			if (CheckMouseInRect() == false) //���콺�� ����������..������..normal ����
			{
				state = State::normal;
			}
		}
		break;

		case State::release:
		{
			//cout << "Release ���� " << endl;
		
			//��ư Ŭ�� ����..�����ϱ�//
			cout << "�̹��� ��ư Ŭ�� .. ���� �����ϱ�" << endl;

			//��ư�� ���¸�..ó������ �ٽ� ���� ��Ű��
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
