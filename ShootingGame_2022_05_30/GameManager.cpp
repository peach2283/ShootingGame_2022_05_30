#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(float px, float py) : GameObject("", "", true, px, py)
{
	this->playerCount = 3; //�÷��̾� ���� �ʱ�ȭ
}

GameManager::~GameManager()
{}

void GameManager::Start()
{
	//[����] ����Ƽ Awake���� ���۽�Ŵ
	instance = this;
}

void GameManager::Update()
{}

void GameManager::RespawnPlayer()
{
	playerCount--;

	if (playerCount > 0)
	{
		//���ο� �÷��̾� ������
		ObjectManager::Instantiate(new Player(240 - 34, 850));
	}
	else {
		//���ӿ��� ��ü ȭ�鿡 �߰�
		ObjectManager::Instantiate(new GameOver(30, 250));
	}
}

GameManager* GameManager::Instance()
{
	return instance;
}