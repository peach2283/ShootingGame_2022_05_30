#pragma once
#include "sprite.h"

class Wing : public Sprite
{
private:
	int x;
	int y;
	int width;
	int height;

	float hp;

public:
	Wing(int x, int y, int width, int height, float px, float py);
	~Wing();

	void Start();
	void Update();

	void OnTriggerStay2D(Collider2D collision);
	void Explode();

	//Destroy 이벤트..함수
	void OnDestroy();
};

