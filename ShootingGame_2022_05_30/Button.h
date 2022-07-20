#pragma once

#include "GameObject.h"
#include "BMP.h"

class Button : public GameObject
{
private:

	//버튼 이미지 로드 구조체
	Image normalImg;  //버튼의 기본 이미지
	Image hoverImg;   //버튼에 마우스가 올라갔을때... 이미지
	Image pushImg;    //버튼의 마우스가 눌렸을때  ... 이미지

public:

	Button(string tag, string name, bool active, float px, float py, int layer = 5);
	~Button();

	void Start();
	void Update();
	void Draw();
};

