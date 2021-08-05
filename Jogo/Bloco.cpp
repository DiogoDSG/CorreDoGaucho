#include "stdafx.h"
#include "Bloco.h"

Bloco::Bloco(const bool colidir)
{
    this->colidir = colidir;
}

Bloco::~Bloco()
{
}

const bool Bloco::getColidir()
{
    return this->colidir;
}

void Bloco::setPosicao(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Bloco::desenharBloco(sf::RenderTarget& janela)
{
    janela.draw(this->sprite);
}
