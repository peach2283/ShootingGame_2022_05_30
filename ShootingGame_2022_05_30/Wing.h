#pragma once
#include "sprite.h"

class Wing : public Sprite
{
private:
	int x;
	int y;
	int width;
	int height;

public:
	Wing(int x, int y, int width, int height, float px, float py);
	~Wing();

	void Start();
	void Update();
};

