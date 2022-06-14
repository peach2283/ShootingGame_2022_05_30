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

				//coli, colj 좌표 가져오기//
				float x, y, width, height;

				float a0, b0, a1, b1;  //coli의 좌표
				float x0, y0, x1, y1;  //colj의 좌표

				coli.GetBox(x, y, width, height);
				
				a0 = x;
				b0 = y;
				a1 = x + width;
				b1 = y + height;

				colj.GetBox(x, y, width, height);

				x0 = x;
				y0 = y;
				x1 = x + width;
				y1 = y + height;

				if (y0 < b1 && y1 > b0 && x1 > a0 && a1 > x0)
				{
					obji->OnTriggerStay2D();  //obji에 충돌 정보 알림
					objj->OnTriggerStay2D();  //objj에 충돌 정보 알림
					
				}
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