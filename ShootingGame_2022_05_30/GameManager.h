#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:
public:

	//�÷��̾� ī��Ʈ ����
	int playerCount;

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();
};

