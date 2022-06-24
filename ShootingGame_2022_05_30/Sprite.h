#pragma once
#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image sprite;

public:

	Sprite(string tag, string name, bool active, float px, float py, int layer=0);
	~Sprite();

	void SetSprite(const char* fileName);
	void SetSprite(const char* fileName, int x, int y, int width, int height);

	void Draw();
};

