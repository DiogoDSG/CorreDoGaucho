#include "stdafx.h"
#include "Cowboy.h"

// _______________________________________________________________________________
Cowboy::Cowboy()
{
	this->iniciarSprite("./Recursos/Imagens/Personagens/cowboy.png", 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL_JOGADOR, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_PLAYER);
	this->barraVida.setTamTexto(22);
	this->barraVida.identificarBarraVida("Cowboy", 10.f, 10.f);
	this->barraVida.setValorMaximo(VIDA_INICIAL_JOGADOR);
}

// _______________________________________________________________________________
Cowboy::~Cowboy()
{
}

void Cowboy::mover()
{
	/* Movimenta o jogador de acordo com o Input do usuario */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->compMov.acelerarX(-0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->compMov.acelerarX(0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->compMov.getCaindo() == false)
		this->compMov.setVelY(-13.f);
}

// _______________________________________________________________________________
void Cowboy::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

// _______________________________________________________________________________
void Cowboy::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	hitbox.desenhar(janela);
	barraVida.desenharBarraVida(janela);
}

