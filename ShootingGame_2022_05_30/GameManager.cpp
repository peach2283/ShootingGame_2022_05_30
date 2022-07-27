#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(float px, float py) : GameObject("", "", true, px, py)
{
	this->playerCount = 3;      //플레이어 갯수 초기화
	this->isPause     = false;  //게임이 동작중임
	this->bombCount   = 3;      //폭탄 갯수 초기화
	this->hp	      = 100;    //플레이어 체력 초기화
}

GameManager::~GameManager()
{}

void GameManager::Start()
{
	//[참고] 유니티 Awake에서 동작시킴
	instance = this;
}

void GameManager::Update()
{}

void GameManager::RespawnPlayer()
{
	playerCount--;

	if (playerCount > 0)
	{
		//새로운 플레이어 리스폰
		ObjectManager::Instantiate(new Player(240 - 34, 850));
	}
	else {
		//게임오버 객체 화면에 추가
		ObjectManager::Instantiate(new GameOver(30, 250));
	}
}

bool GameManager::GetPause()
{
	return isPause;
}

void GameManager::SetPause(bool pause)
{
	this->isPause = pause;
}

int GameManager::GetPlayerCount()
{
	return playerCount;
}

int GameManager::GetBombCount()
{
	return bombCount;
}

void GameManager::DecBombCount()
{
	bombCount--;
}

void GameManager::IncBombCount()
{
	bombCount++;

	if (bombCount > 6)
	{
		bombCount = 6;
	}
}

void GameManager::DoDamage(float amount)
{
	hp = hp - amount;
}

float GameManager::GetHP()
{
	return hp;
}

GameManager* GameManager::Instance()
{
	return instance;
}