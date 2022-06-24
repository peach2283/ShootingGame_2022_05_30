#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py, int layer)
		 :GameObject(tag, name, active, px, py, layer)
{
	this->index = 0;
	this->clip  = 0;

	this->animTimer = 0;
	this->animDelay = 1 / 15.0f;
	this->speed     = 1;

	this->loop = true; //애니메이션 루프 실행
}

Animation::~Animation()
{
	//로드된..애니메이션 이미지들..메모리 제거//
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < sprites[i].size(); j++)
		{
			delete[] sprites[i][j].argb;  //i 번째 배열의...j 번째 vector 요소(이미지)의 메모리 제거
		}
	}
}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height, int clipId)
{
	Image img;

	BMP::ReadBMP(fileName, x, y, width, height, &img);
	sprites[clipId].push_back(img);
}

void Animation::Play(int clipId)
{
	if (this->clip != clipId)  //현재..재생중인 애니메이션과 다른걸로..바꿀경우만
	{
		this->clip = clipId;  //애니메이션 변경하기
		this->index = 0;      //애니메이션의..이미지를 0 번부터..시작
	}
}

void Animation::SetLoop(bool loop)
{
	this->loop = loop;
}

void Animation::SetSpeed(float speed)
{
	this->speed = speed;
}

void Animation::Draw()
{
	float px = GetPx();
	float py = GetPy();

	BMP::DrawBMP(px, py, &sprites[   clip   ][ index ]);

	//이미지 인덱스..변경..시간 측정//
	animTimer = animTimer + Time::deltaTime * speed;

	if (animTimer >= animDelay)
	{
		index++;

		if ( index >= sprites[ clip ].size() )  //마지막..이미지가 나옴
		{
			//애니메이션의..마지막..이미지가 나왔음을...알려주는 이벤트 만들기//
			OnAnimationEnd();

			if (loop == true)  //루프를 할 경우
			{
				index = 0; //처음 이미지로..감
			}
			else {
				index = sprites[clip].size() - 1; //마지막 이미지를 ..유지함
			}
		}

		animTimer = 0;  //타이머..리셋
	}
}

void Animation::OnAnimationEnd()
{
}