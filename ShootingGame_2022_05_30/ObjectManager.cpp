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
			gameObjects.erase( gameObjects.begin() + i ); //��Ͽ��� ����
			delete o;                                     //��ü..����

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
				GameObject* obji = gameObjects[i];  //����
				GameObject* objj = gameObjects[j];  //�÷��̾�

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

		//���ӿ�����Ʈ ����׿� �׸��� �Լ�//
		gameObjects[i]->DebugDraw();
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