#pragma once

#include <vector>

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:	

	vector<Image> sprites[3];

	int   index;  //애니메이션 STL vector의 이미지 인덱스
	int   clip;   //STL vector  배열의 인덱스(애니메이션 클립)

	float animTimer;
	float animDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void Draw();

	//애니메이션 이미지 로드 함수//
	void AddSprite(const char* fileName, int x, int y, int width, int height, int clipId);

	//재생중인..애니메이션 클립 변경함수//
	void Play(int clipId);
};

