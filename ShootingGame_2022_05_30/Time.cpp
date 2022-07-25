#include <Windows.h>
#include "Time.h"

//��ŸŸ�� ����ƽ����
float Time::currTime;
float Time::nextTime;
float Time::deltaTime;

//Ÿ�ӽ����� ����ƽ����
float Time::timeScale;

//��ŸŸ�� ���� �Լ� �ʱ�ȭ//
void Time::Init()
{
	currTime  = GetTickCount() / 1000.0f;  //��ǻ�͸� ����(����)�ؼ�..�����ð�
	timeScale = 1;
}

void Time::Update()
{
	nextTime  = GetTickCount() / 1000.0f;
	
	deltaTime = (nextTime - currTime) * timeScale;

	currTime  = GetTickCount() / 1000.0f;
}