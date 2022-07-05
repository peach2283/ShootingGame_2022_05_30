#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:

	static GameManager* instance;

	//�÷��̾� ī��Ʈ ����
	int playerCount;
public:

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();

	void RespawnPlayer();

	static GameManager* Instance();
};

