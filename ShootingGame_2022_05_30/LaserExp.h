#pragma once
#include "Animation.h"

class LaserExp : public Animation
{
private:
public:
	LaserExp(float px, float py);
	~LaserExp();

	void Start();
	void Update();

	//애니메이션 마지막 그림..이벤트 가상함수... 오버라이딩
	void OnAnimationEnd();
};

