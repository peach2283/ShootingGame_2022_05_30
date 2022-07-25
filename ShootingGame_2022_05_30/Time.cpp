#include <Windows.h>
#include "Time.h"

//델타타임 스태틱변수
float Time::currTime;
float Time::nextTime;
float Time::deltaTime;

//타임스케일 스태틱변수
float Time::timeScale;

//델타타임 측정 함수 초기화//
void Time::Init()
{
	currTime  = GetTickCount() / 1000.0f;  //컴퓨터를 시작(부팅)해서..지난시간
	timeScale = 1;
}

void Time::Update()
{
	nextTime  = GetTickCount() / 1000.0f;
	
	deltaTime = (nextTime - currTime) * timeScale;

	currTime  = GetTickCount() / 1000.0f;
}