#include "Sprite.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py, int layer)
	   :GameObject(tag, name, active, px, py, layer)
{
    sprite.width  = 0;
    sprite.height = 0;
    sprite.argb   = nullptr;

    this->enabled = true;  //Sprite를 그림
}

Sprite::~Sprite()
{
    if (sprite.argb != nullptr)
    {
        delete[] sprite.argb;
    }
}

void Sprite::SetSprite(const char* fileName, float pvx, float pvy)
{
    //전체 이미지 로드하기
    BMP::ReadBMP(fileName, &sprite);

    //피봇 저장하기
    sprite.pvx = pvx;
    sprite.pvy = pvy;
}

void Sprite::SetSprite(const char* fileName, int x, int y, int width, int height, float pvx, float pvy)
{
    //이미지 로드하기
    BMP::ReadBMP(fileName, x, y, width, height, &sprite);

    //피봇 매개변수... 저장하기
    sprite.pvx = pvx;
    sprite.pvy = pvy;
}

void Sprite::Draw()
{
    if (enabled == true)
    {
        //이미지 피봇 가져오기
        float pvx = sprite.pvx;
        float pvy = sprite.pvy;

        //객체 위치 가져오기//
        float px = GetPx();
        float py = GetPy();

        BMP::DrawBMP(px - pvx, py - pvy, &sprite);
    }
}
