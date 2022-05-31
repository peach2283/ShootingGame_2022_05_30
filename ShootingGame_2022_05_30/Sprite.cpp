#include "Sprite.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	   :GameObject(tag, name, active, px, py)
{
    sprite.width  = 0;
    sprite.height = 0;
    sprite.argb = nullptr;
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

void Sprite::Draw()
{
    //��ü ��ġ ��������//
    float px = GetPx();
    float py = GetPy();

    BMP::DrawBMP(px, py, &sprite);
}
