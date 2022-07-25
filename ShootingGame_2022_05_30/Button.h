#pragma once

#include "GameObject.h"
#include "BMP.h"

class Button : public GameObject
{
	////��ư ���� ������////
	enum class State {normal=0, hover=1, press=2, release=3 };

private:

	//��ư �̹��� �ε� ����ü
	Image normalImg;  //��ư�� �⺻ �̹���
	Image hoverImg;   //��ư�� ���콺�� �ö�����... �̹���
	Image pressImg;   //��ư�� ���콺�� ��������  ... �̹���

	//��ư ���� ����
	State state;

public:

	Button(string tag, string name, bool active, float px, float py, int layer = 5);
	~Button();

	void Start();
	void Update();
	void Draw();

	//���콺 ��ǥ��..�̹��� �����ȿ� �ִ����� �˻��ϴ� �Լ�
	bool CheckMouseInRect();

	//��ư �̹��� ����
	void SetNormalImg(const char* fileName);
	void SetHoverImg (const char* fileName);
	void SetPressImg (const char* fileName);

	//Ŭ�� ���� �Լ�
	virtual void OnClick();
};

