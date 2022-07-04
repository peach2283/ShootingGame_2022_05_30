#include "framework.h"
#include "ShootingGame.h"

vector<GameObject*> ObjectManager::gameObjects;

bool CmpLayer(GameObject* x, GameObject* y)
{
	//x, y의 레이어를 비교
	if (x->GetLayer()  <  y->GetLayer())
	{
		return true;
	}
	else {
		return false;
	}
}

void ObjectManager::Instantiate(GameObject* o)
{
	o->Start();
	gameObjects.push_back(o);
}

void ObjectManager::SortLayer()
{
	//새로운 게임객체 추가후...레이어에 의해서..정렬//
	sort(gameObjects.begin(), gameObjects.end(), CmpLayer);
}

void ObjectManager::Destroy(GameObject* o)
{
	//삭제..대상으로..대기중이라는...표시//
	o->SetDead();  

	/***********************************************************
	for (int i = 0  ; i < gameObjects.size()  ; i++)
	{
		if (gameObjects[i] == o)
		{
			gameObjects.erase( gameObjects.begin() + i ); //목록에서 제거
			delete o;                                     //객체..제거

			i--;
		}
	}
	*************************************************************/
}

void ObjectManager::CheckCollision()
{	
	for (int i = 0; i < gameObjects.size(); i++)     
	{
		for (int j = 0; j < gameObjects.size(); j++) 
		{
			if (i > j)
			{
				GameObject* obji = gameObjects[i];  //총알
				GameObject* objj = gameObjects[j];  //방패

				//obji도 활성화이고, 그리고, objj도 활성화이어야함..충돌검사를 함
				if (obji->GetActive() == true && objj->GetActive() == true)
				{

					string tagi = obji->GetTag();
					string tagj = objj->GetTag();

					vector<BoxCollider2D> coli = obji->GetColliders();
					vector<BoxCollider2D> colj = objj->GetColliders();

					//int layeri = obji->GetLayer();
					//int layerj = objj->GetLayer();
					//[유니티 에는] ... 옵션 설정에 따라서..layeri에 속한 obji와 layerj에 속한 objj의 충돌검사를 할지 않할지를 결정

					for (int ii = 0; ii < coli.size(); ii++)  //coli의 박스들..반복
					{
						for (int jj = 0; jj < colj.size(); jj++)  //colj의 박스들..반복
						{
							//coli, colj 좌표 가져오기//
							float x, y, width, height;

							float a0, b0, a1, b1;  //coli의 좌표
							float x0, y0, x1, y1;  //colj의 좌표

							coli[ii].GetBox(x, y, width, height);

							a0 = x;
							b0 = y;
							a1 = x + width;
							b1 = y + height;

							colj[jj].GetBox(x, y, width, height);

							x0 = x;
							y0 = y;
							x1 = x + width;
							y1 = y + height;

							if (y0 < b1 && y1 > b0 && x1 > a0 && a1 > x0)
							{
								//충돌 정보를...Collider2D 클래스에 넣어서..매개변수로..전달해라!!
								Collider2D col2Di;
								col2Di.tag = tagj;  //obji 와 충돌함 ..objj의 태그 정보

								Collider2D col2Dj;
								col2Dj.tag = tagi;  //objj 와 충돌한.. obji의 태그 정보

								obji->OnTriggerStay2D(col2Di);  //obji가 objj 와 충돌 정보 알림
								objj->OnTriggerStay2D(col2Dj);  //objj가 obji 와 충돌 정보 알림					
							}

						}
					}
				}
	
			}
		}
	}	
}

void ObjectManager::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->GetActive() == true)
		{
			gameObjects[i]->Update();
		}
	}
}

void ObjectManager::Draw()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->GetActive() == true) //활성화된 객체들만..화면에 ... 그림
		{
			gameObjects[i]->Draw();

			//게임오브젝트 디버그용 그리기 함수//
			gameObjects[i]->DebugDraw();
		}
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

void ObjectManager::ClearDeadObject()
{
	//목록 사용이 모두 끝난 후...삭제 대기인 객체를...삭제함//
	for (int i = 0; i < gameObjects.size(); i++)
	{
		//삭제 대상으로..표시된..객체를 찾아서..삭제함//
		if (gameObjects[i]->GetDead() == true)
		{
			GameObject* o = gameObjects[i]; //delete를 위해서..포인터 저장하기

			gameObjects.erase(gameObjects.begin() + i);  //gameObjects stl vector에서 i 번째 공간삭제하기

			//객체에...삭제됨을 알려줌
			o->OnDestroy();

			delete o;  //객체 삭제하기
			i--;
		}
	}
}