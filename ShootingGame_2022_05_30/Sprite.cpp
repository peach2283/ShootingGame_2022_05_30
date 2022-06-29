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

void Sprite::SetSprite(const char* fileName)
{
    BMP::ReadBMP(fileName, &sprite);
}

void Sprite::SetSprite(const char* fileName, int x, int y, int width, int height)
{
    BMP::ReadBMP(fileName, x, y, width, height, &sprite);
}

void Sprite::Draw()
{
    if (enabled == true)
    {
        //객체 위치 가져오기//
        float px = GetPx();
        float py = GetPy();

        BMP::DrawBMP(px, py, &sprite);
    }
}
