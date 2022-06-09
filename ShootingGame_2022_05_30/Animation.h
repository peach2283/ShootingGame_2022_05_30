#pragma once

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:	
	Image sprites[4];
	int   index;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void Start();
	void Draw();
};

