#pragma once
#include "GameObject.h"

class UIManager : public GameObject
{
private:

	//GameMenu ��ü ������//
	GameObject* gameMenu;

public:
	UIManager(float px, float py);
	~UIManager();

	void Start();
	void Update();
};

