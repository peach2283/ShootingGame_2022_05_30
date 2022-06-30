#pragma once
#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image sprite;

public:

	bool  enabled;  //동작 가능(true ... Sprite를 그림)/불가능(false...Sprite를 안그림)

	Sprite(string tag, string name, bool active, float px, float py, int layer=0);
	~Sprite();

	void SetSprite(const char* fileName);
	void SetSprite(const char* fileName, int x, int y, int width, int height);

	void Draw();
};

