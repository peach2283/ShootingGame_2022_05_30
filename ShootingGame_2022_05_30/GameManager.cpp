#include "ShootingGame.h"

GameManager::GameManager(float px, float py) : GameObject("", "", true, px, py)
{
	this->playerCount = 3; //�÷��̾� ���� �ʱ�ȭ
}

GameManager::~GameManager()
{}

void GameManager::Start()
{}

void GameManager::Update()
{}