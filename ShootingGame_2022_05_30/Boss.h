#pragma once
#include "Sprite.h"

class Boss : public Sprite
{
private:
	float speed;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//자식객체가..파괴됨을 알리는 이벤트 함수//
	void OnChildDestroy(string name);

};

