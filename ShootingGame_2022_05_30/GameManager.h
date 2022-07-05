#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:

	static GameManager* instance;

	//플레이어 카운트 변수
	int playerCount;
public:

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();

	void RespawnPlayer();

	static GameManager* Instance();
};

