#pragma once

class Mathf //실수(float) 기반의 수학함수..클래스
{
private:
public:
	static const float PI;  //원주율 상수

	static float Abs(float x);      //절대값 반환 함수
	static float Sin(float radian); //싸인 반환 함수
	static float Cos(float radian); //코사인 반환 함수
	static float Tan(float radian); //탄젠트 반환 함수
	static float Sqrt(float x);     //제곱근 반환 함수
};
