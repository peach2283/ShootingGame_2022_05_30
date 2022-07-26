#pragma once
#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//GameMenu 객체 포인터//
	GameObject* gameMenu;

public:
	UIManager(float px, float py);
	~UIManager();

	void Start();
	void Update();
};

