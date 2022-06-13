#pragma once

class BoxCollider2D
{
private:
	float x, y;         //Box의 왼쪽상단좌표
	float width, height;//Box의 가로 길이 /세로길이

public:
	BoxCollider2D();
	BoxCollider2D(float x, float y, float width, float height);

	virtual ~BoxCollider2D();

	//게터
	void GetBox(float& x, float& y, float& width, float& height);

	//이동함수
	void Translate(float x, float y);
};

