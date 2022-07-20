#include "ShootingGame.h"

Button::Button(string tag, string name, bool active, float px, float py, int layer)
	   :GameObject(tag, name, active, px, py, layer)
{}

Button::~Button()
{}

void Button::Start()
{
	//�̹��� ��ư..�ε��ϱ�
	BMP::ReadBMP("Asset/UI/Button/Pause.bmp", &normalImg);  //��ư�� �⺻�̹��� �ε�
}

void Button::Update()
{
	//���콺 ���� �˻��ϱ�//
	if (Input::GetMouseButtonDown(0) == true)
	{
		cout << "���콺 ��ư ����" << endl;
	}
}

void Button::Draw()
{
	float px, py;
	GetPosition(px, py);

	BMP::DrawBMP(px, py, &normalImg);
}