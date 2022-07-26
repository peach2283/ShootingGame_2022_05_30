#pragma once
#include "Button.h"

class Pause : public Button
{
private:
public:
	Pause(float px, float py);
	~Pause();

	void Start();	

	//OnClick 오버라이딩//
	void OnClick();
};

