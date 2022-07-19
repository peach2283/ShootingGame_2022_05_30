#include "Mathf.h"
#include <math.h>

const float Mathf::PI = 3.141597f;

float Mathf::Abs(float x)  //���밪 ��ȯ �Լ�
{
	if (x < 0)
	{
		return -x;
	}
	else {
		return x;
	}
}

float Mathf::Sin(float radian) //���� ��ȯ �Լ�
{
	return (float)sin(radian);
}

float Mathf::Cos(float radian) //�ڻ��� ��ȯ �Լ�
{
	return (float)cos(radian);
}

float Mathf::Tan(float radian) //ź��Ʈ ��ȯ �Լ�
{
	return (float)tan(radian);
}

float Mathf::Sqrt(float x)
{
	return (float)sqrt(x);
}
