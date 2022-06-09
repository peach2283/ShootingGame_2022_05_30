#pragma once

#include <vector>

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:	

	vector<Image> sprites;
	int   index;

	float animTimer;
	float animDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void Draw();

	//애니메이션 이미지 로드 함수//
	void AddSprite(const char* fileName, int x, int y, int width, int height);
};

