#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:
public:

	//플레이어 카운트 변수
	int playerCount;

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();
};

