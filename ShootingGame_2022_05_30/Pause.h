#pragma once
#include "Button.h"

class Pause : public Button
{
private:
	bool isPause; //�������� ���� ����
	              //true(����), false(����)

public:
	Pause(float px, float py);
	~Pause();

	void Start();	

	//OnClick �������̵�//
	void OnClick();
};

