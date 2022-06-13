#pragma once

class BoxCollider2D
{
private:
	float x, y;         //Box�� ���ʻ����ǥ
	float width, height;//Box�� ���� ���� /���α���

public:
	BoxCollider2D();
	BoxCollider2D(float x, float y, float width, float height);

	virtual ~BoxCollider2D();

	//����
	void GetBox(float& x, float& y, float& width, float& height);

	//�̵��Լ�
	void Translate(float x, float y);
};

