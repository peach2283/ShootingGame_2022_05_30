#include "framework.h"
#include "ShootingGame.h"

vector<GameObject*> ObjectManager::gameObjects;

bool CmpLayer(GameObject* x, GameObject* y)
{
	//x, y�� ���̾ ��
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
	//���ο� ���Ӱ�ü �߰���...���̾ ���ؼ�..����//
	sort(gameObjects.begin(), gameObjects.end(), CmpLayer);
}

void ObjectManager::Destroy(GameObject* o)
{
	//����..�������..������̶��...ǥ��//
	o->SetDead();  

	/***********************************************************
	for (int i = 0  ; i < gameObjects.size()  ; i++)
	{
		if (gameObjects[i] == o)
		{
			gameObjects.erase( gameObjects.begin() + i ); //��Ͽ��� ����
			delete o;                                     //��ü..����

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
				GameObject* obji = gameObjects[i];  //�Ѿ�
				GameObject* objj = gameObjects[j];  //����

				//obji�� Ȱ��ȭ�̰�, �׸���, objj�� Ȱ��ȭ�̾����..�浹�˻縦 ��
				if (obji->GetActive() == true && objj->GetActive() == true)
				{

					string tagi = obji->GetTag();
					string tagj = objj->GetTag();

					vector<BoxCollider2D> coli = obji->GetColliders();
					vector<BoxCollider2D> colj = objj->GetColliders();

					//int layeri = obji->GetLayer();
					//int layerj = objj->GetLayer();
					//[����Ƽ ����] ... �ɼ� ������ ����..layeri�� ���� obji�� layerj�� ���� objj�� �浹�˻縦 ���� �������� ����

					for (int ii = 0; ii < coli.size(); ii++)  //coli�� �ڽ���..�ݺ�
					{
						for (int jj = 0; jj < colj.size(); jj++)  //colj�� �ڽ���..�ݺ�
						{
							//coli, colj ��ǥ ��������//
							float x, y, width, height;

							float a0, b0, a1, b1;  //coli�� ��ǥ
							float x0, y0, x1, y1;  //colj�� ��ǥ

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
								//�浹 ������...Collider2D Ŭ������ �־..�Ű�������..�����ض�!!
								Collider2D col2Di;
								col2Di.tag = tagj;  //obji �� �浹�� ..objj�� �±� ����

								Collider2D col2Dj;
								col2Dj.tag = tagi;  //objj �� �浹��.. obji�� �±� ����

								obji->OnTriggerStay2D(col2Di);  //obji�� objj �� �浹 ���� �˸�
								objj->OnTriggerStay2D(col2Dj);  //objj�� obji �� �浹 ���� �˸�					
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
		if (gameObjects[i]->GetActive() == true) //Ȱ��ȭ�� ��ü�鸸..ȭ�鿡 ... �׸�
		{
			gameObjects[i]->Draw();

			//���ӿ�����Ʈ ����׿� �׸��� �Լ�//
			gameObjects[i]->DebugDraw();
		}
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

void ObjectManager::ClearDeadObject()
{
	//��� ����� ��� ���� ��...���� ����� ��ü��...������//
	for (int i = 0; i < gameObjects.size(); i++)
	{
		//���� �������..ǥ�õ�..��ü�� ã�Ƽ�..������//
		if (gameObjects[i]->GetDead() == true)
		{
			GameObject* o = gameObjects[i]; //delete�� ���ؼ�..������ �����ϱ�

			gameObjects.erase(gameObjects.begin() + i);  //gameObjects stl vector���� i ��° ���������ϱ�

			//��ü��...�������� �˷���
			o->OnDestroy();

			delete o;  //��ü �����ϱ�
			i--;
		}
	}
}