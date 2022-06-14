#pragma once

#include <vector>
#include "GameObject.h"

class ObjectManager
{
private:
	//���Ӱ�ü ���� stl vector�� ���//
	static vector<GameObject*> gameObjects;

public:	

	//���Ӱ�ü��..��Ͽ� �߰��ؼ�..������ �����ϴ� �ν��Ͻ��� ����� �Լ� / ��� �����Լ�
	static void Instantiate(GameObject* o);
	static void Destroy(GameObject* o);

	//���� ��� ������Ʈ �Լ�
	static void Update();

	//���� ��� Draw �Լ�
	static void Draw();

	//���� ��� ��ü Clear �Լ�
	static void Clear();

	//�浹�˻� �Լ�
	static void CheckCollision();
};

