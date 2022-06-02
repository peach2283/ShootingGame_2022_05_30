#include "ObjectManager.h"

vector<GameObject*> ObjectManager::gameObjects;

void ObjectManager::Instantiate(GameObject* o)
{
	o->Start();
	gameObjects.push_back(o);
}

void ObjectManager::Destroy(GameObject* o)
{
	for (int i = 0  ; i < gameObjects.size()  ; i++)
	{
		if (gameObjects[i] == o)
		{
			gameObjects.erase( gameObjects.begin() + i ); //목록에서 제거
			delete o;                                     //객체..제거

			i--;
		}
	}
}

void ObjectManager::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

void ObjectManager::Draw()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw();
	}
}

void ObjectManager::Clear()
{
	//게임객체 삭제하기
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	gameObjects.clear();
}