#pragma once
#include "GameObject.h"

class GameMenu : public GameObject
{
private:
public:
	GameMenu(float px, float py);
	~GameMenu();

	void Start();
	void Update();
};

