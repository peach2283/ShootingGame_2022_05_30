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

void ObjectManager::CheckCollision()
{
	cout << "---------------------------------" << endl;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		for (int j = 0; j < gameObjects.size(); j++)
		{
			if (i > j)
			{
				GameObject* obji = gameObjects[i];  //적기
				GameObject* objj = gameObjects[j];  //플레이어

				string tagi = obji->GetTag();
				string tagj = objj->GetTag();

				BoxCollider2D coli = obji->GetColliders();
				BoxCollider2D colj = objj->GetColliders();

				cout << "(" << tagi << " ,  " << tagj << ") ";
			}
		}

		cout << endl;
	}

	cout << endl;
	cout << "---------------------------------" << endl;
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

		//게임오브젝트 디버그용 그리기 함수//
		gameObjects[i]->DebugDraw();
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