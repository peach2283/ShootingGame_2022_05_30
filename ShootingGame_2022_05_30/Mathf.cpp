#include "Mathf.h"
#include <math.h>

const float Mathf::PI = 3.141597f;

float Mathf::Abs(float x)  //절대값 반환 함수
{
	if (x < 0)
	{
		return -x;
	}
	else {
		return x;
	}
}

float Mathf::Sin(float radian) //싸인 반환 함수
{
	return (float)sin(radian);
}

float Mathf::Cos(float radian) //코사인 반환 함수
{
	return (float)cos(radian);
}

float Mathf::Tan(float radian) //탄젠트 반환 함수
{
	return (float)tan(radian);
}

float Mathf::Sqrt(float x)
{
	return (float)sqrt(x);
}
