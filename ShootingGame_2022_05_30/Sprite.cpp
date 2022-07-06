#include "Sprite.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py, int layer)
	   :GameObject(tag, name, active, px, py, layer)
{
    sprite.width  = 0;
    sprite.height = 0;
    sprite.argb   = nullptr;

    this->enabled = true;  //Sprite�� �׸�
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
    //��ü �̹��� �ε��ϱ�
    BMP::ReadBMP(fileName, &sprite);

    //�Ǻ� �����ϱ�
    sprite.pvx = pvx;
    sprite.pvy = pvy;
}

void Sprite::SetSprite(const char* fileName, int x, int y, int width, int height, float pvx, float pvy)
{
    //�̹��� �ε��ϱ�
    BMP::ReadBMP(fileName, x, y, width, height, &sprite);

    //�Ǻ� �Ű�����... �����ϱ�
    sprite.pvx = pvx;
    sprite.pvy = pvy;
}

void Sprite::Draw()
{
    if (enabled == true)
    {
        //�̹��� �Ǻ� ��������
        float pvx = sprite.pvx;
        float pvy = sprite.pvy;

        //��ü ��ġ ��������//
        float px = GetPx();
        float py = GetPy();

        BMP::DrawBMP(px - pvx, py - pvy, &sprite);
    }
}
