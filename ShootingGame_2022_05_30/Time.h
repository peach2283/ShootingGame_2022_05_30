#pragma once

class Time
{
private:
	static float currTime;
	static float nextTime;

public:
	static float deltaTime; //����Ƽ������ C#�� ���α׷�(Get/Set ������Ƽ) �������..deltaTime�� public���� �����
	static float timeScale; //Ÿ�ӽ�����

	static void Init();
	static void Update();	
};