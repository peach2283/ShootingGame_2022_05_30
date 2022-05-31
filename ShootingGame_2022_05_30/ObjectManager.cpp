#include "ObjectManager.h"

vector<GameObject*> ObjectManager::gameObjects;

void ObjectManager::Instantiate(GameObject* o)
{
	o->Start();
	gameObjects.push_back(o);
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
	//���Ӱ�ü �����ϱ�
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	gameObjects.clear();
}