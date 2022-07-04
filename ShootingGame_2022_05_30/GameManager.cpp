#include "ShootingGame.h"

GameManager::GameManager(float px, float py) : GameObject("", "", true, px, py)
{
	this->playerCount = 3; //플레이어 갯수 초기화
}

GameManager::~GameManager()
{}

void GameManager::Start()
{}

void GameManager::Update()
{}