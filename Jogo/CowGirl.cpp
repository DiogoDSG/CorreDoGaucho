#include "stdafx.h"
#include "CowGirl.h"

// _______________________________________________________________________________
CowGirl::CowGirl(std::string imgCaminho)
{
	if (!texture.loadFromFile(imgCaminho))
	{
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(100.0, 400.0));
	sprite.setScale(sf::Vector2f(2, 2));
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->iniciarHitbox();
	this->iniciarCompMov();
}

// _______________________________________________________________________________
void CowGirl::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	this->hitbox.desenhar(janela);
}

// _______________________________________________________________________________
void CowGirl::atualizar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->compMov.acelerarX(-0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->compMov.acelerarX(0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->compMov.getCaindo() == false)
		this->compMov.setVelY(-13.f);

	this->hitbox.atualizarPosicao();
	this->compMov.mover();
}

/*
// _______________________________________________________________________________
bool CowGirl::verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push)
{
	float deltaX = posicao.x - sprite.getPosition().x;
	float deltaY = posicao.y - sprite.getPosition().y;

	float intersectX = abs(deltaX) - (tamanho.x / 2 + sprite.getTexture()->getSize().x * sprite.getScale().x / 2);
	float intersectY = abs(deltaY) - (tamanho.y / 2 + sprite.getTexture()->getSize().y * sprite.getScale().y / 2);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				this->mover('r', intersectX * push);
			}
			else
			{
				this->mover('l', intersectX * push);
			}
		}
		else
		{
			if (deltaX > 0.0f)
			{
				this->mover('u', intersectY * push);
			}
			else
			{
				this->mover('d', intersectY * push);
			}
		}

		return true;
	}

	return false;
}
*/
// _______________________________________________________________________________
sf::Vector2f CowGirl::getPosition()
{
	return sprite.getPosition();
}

// _______________________________________________________________________________
sf::Vector2f CowGirl::getSize()
{
	return sf::Vector2f(sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
}

// _______________________________________________________________________________
CowGirl::~CowGirl()
{
}