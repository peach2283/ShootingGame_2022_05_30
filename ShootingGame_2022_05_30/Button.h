#pragma once

#include "GameObject.h"
#include "BMP.h"

class Button : public GameObject
{
private:

	//��ư �̹��� �ε� ����ü
	Image normalImg;  //��ư�� �⺻ �̹���
	Image hoverImg;   //��ư�� ���콺�� �ö�����... �̹���
	Image pushImg;    //��ư�� ���콺�� ��������  ... �̹���

public:

	Button(string tag, string name, bool active, float px, float py, int layer = 5);
	~Button();

	void Start();
	void Update();
	void Draw();
};

