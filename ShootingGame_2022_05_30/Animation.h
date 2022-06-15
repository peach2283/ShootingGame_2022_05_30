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

	bool  loop;    //애니메이션 반복실행(loop) 결정
	float speed;   //애니메이션 재생 속도 조절

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void Draw();

	//애니메이션 이미지 로드 함수//
	void AddSprite(const char* fileName, int x, int y, int width, int height, int clipId);

	//재생중인..애니메이션 클립 변경함수//
	void Play(int clipId);

	//애니메이션 루프 지정 함수
	void SetLoop(bool loop);

	//애니메이션 속도 지정 함수
	void SetSpeed(float speed);

	//애니메이션 마지막 그림 나옴을..알려주는..부모 가상함수
	virtual void OnAnimationEnd();
};

