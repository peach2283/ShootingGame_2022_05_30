#pragma once

#include "GameObject.h"
#include "BMP.h"

class Button : public GameObject
{
	////버튼 상태 열거형////
	enum class State {normal=0, hover=1, press=2, release=3 };

private:

	//버튼 이미지 로드 구조체
	Image normalImg;  //버튼의 기본 이미지
	Image hoverImg;   //버튼에 마우스가 올라갔을때... 이미지
	Image pressImg;   //버튼의 마우스가 눌렸을때  ... 이미지

	//버튼 상태 변수
	State state;

public:

	Button(string tag, string name, bool active, float px, float py, int layer = 5);
	~Button();

	void Start();
	void Update();
	void Draw();

	//마우스 좌표가..이미지 영역안에 있는지를 검사하는 함수
	bool CheckMouseInRect();

	//버튼 이미지 세터
	void SetNormalImg(const char* fileName);
	void SetHoverImg (const char* fileName);
	void SetPressImg (const char* fileName);

	//클릭 가상 함수
	virtual void OnClick();
};

