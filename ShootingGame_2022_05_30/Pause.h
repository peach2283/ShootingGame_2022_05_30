#pragma once
#include "Button.h"

class Pause : public Button
{
private:
	bool isPause; //정지상태 지정 변수
	              //true(정지), false(동작)

public:
	Pause(float px, float py);
	~Pause();

	void Start();	

	//OnClick 오버라이딩//
	void OnClick();
};

