#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(float px, float py) : GameObject("", "", true, px, py)
{
	this->playerCount = 3;      //�÷��̾� ���� �ʱ�ȭ
	this->isPause     = false;  //������ ��������
	this->bombCount   = 3;      //��ź ���� �ʱ�ȭ
	this->hp	      = 100;    //�÷��̾� ü�� �ʱ�ȭ
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