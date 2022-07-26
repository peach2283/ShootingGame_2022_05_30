#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:

	static GameManager* instance;

	//�÷��̾� ī��Ʈ ����
	int playerCount;

	//�������� ���� ����
	bool isPause;

public:

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();

	void RespawnPlayer();

	//isPause ����/����
	bool GetPause();
	void SetPause(bool pause);

	static GameManager* Instance();
};

