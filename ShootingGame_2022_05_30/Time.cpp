#include <Windows.h>
#include "Time.h"

//��ŸŸ�� ��������
float Time::currTime;
float Time::nextTime;
float Time::deltaTime;

//��ŸŸ�� ���� �Լ� �ʱ�ȭ//
void Time::Init()
{
	currTime = GetTickCount() / 1000.0f;  //��ǻ�͸� ����(����)�ؼ�..�����ð�
	nextTime;
	deltaTime;
}

void Time::Update()
{
	nextTime  = GetTickCount() / 1000.0f;
	deltaTime = nextTime - currTime;
	currTime  = GetTickCount() / 1000.0f;
}