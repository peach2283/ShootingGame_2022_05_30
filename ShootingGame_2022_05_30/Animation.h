#pragma once

#include <vector>

#include "GameObject.h"
#include "BMP.h"

class Animation : public GameObject
{
private:	

	vector<Image> sprites[3];

	int   index;  //�ִϸ��̼� STL vector�� �̹��� �ε���
	int   clip;   //STL vector  �迭�� �ε���(�ִϸ��̼� Ŭ��)

	float animTimer;
	float animDelay;

	bool  loop;    //�ִϸ��̼� �ݺ�����(loop) ����
	float speed;   //�ִϸ��̼� ��� �ӵ� ����

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void Draw();

	//�ִϸ��̼� �̹��� �ε� �Լ�//
	void AddSprite(const char* fileName, int x, int y, int width, int height, int clipId);

	//�������..�ִϸ��̼� Ŭ�� �����Լ�//
	void Play(int clipId);

	//�ִϸ��̼� ���� ���� �Լ�
	void SetLoop(bool loop);

	//�ִϸ��̼� �ӵ� ���� �Լ�
	void SetSpeed(float speed);

	//�ִϸ��̼� ������ �׸� ������..�˷��ִ�..�θ� �����Լ�
	virtual void OnAnimationEnd();
};

