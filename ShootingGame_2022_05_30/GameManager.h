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

	//���� ��ź����
	int bombCount; 

	//�÷��̾� ü��
	float hp;  

public:

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();

	void RespawnPlayer();

	//isPause ����/����
	bool GetPause();
	void SetPause(bool pause);

	//playerCounter ����
	int GetPlayerCount();

	int  GetBombCount();
	void DecBombCount();
	void IncBombCount();

	void  DoDamage(float amount);
	float GetHP();

	static GameManager* Instance();
};

