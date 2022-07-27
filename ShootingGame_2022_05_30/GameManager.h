#pragma once
#include "GameObject.h"

class GameManager : public GameObject
{
private:
	static GameManager* instance;

	//플레이어 카운트 변수
	int playerCount;

	//게임일지 정지 변수
	bool isPause;

	//남은 폭탄갯수
	int bombCount; 

	//플레이어 체력
	float hp;  

public:

	GameManager(float px, float py);
	~GameManager();

	void Start();
	void Update();

	void RespawnPlayer();

	//isPause 게터/세터
	bool GetPause();
	void SetPause(bool pause);

	//playerCounter 게터
	int GetPlayerCount();

	int  GetBombCount();
	void DecBombCount();
	void IncBombCount();

	void  DoDamage(float amount);
	float GetHP();

	static GameManager* Instance();
};

