#pragma once
#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//GameMenu 객체 포인터//
	GameObject* gameMenu;

	//PlayerIcon 객체 포인터 배열//
	GameObject* playerIcon[3];

	//BombIcon 객체 포인터 배열
	GameObject* bombIcon[6];

public:
	UIManager(float px, float py);
	~UIManager();

	void Start();
	void Update();
};

