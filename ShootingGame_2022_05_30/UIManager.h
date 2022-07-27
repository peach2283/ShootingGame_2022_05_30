#pragma once
#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//GameMenu ��ü ������//
	GameObject* gameMenu;

	//PlayerIcon ��ü ������ �迭//
	GameObject* playerIcon[3];

	//BombIcon ��ü ������ �迭
	GameObject* bombIcon[6];

public:
	UIManager(float px, float py);
	~UIManager();

	void Start();
	void Update();
};

