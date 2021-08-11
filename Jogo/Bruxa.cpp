#include "stdafx.h"
#include "Bruxa.h"

// _______________________________________________________________________________
Bruxa::Bruxa(): tempo_direcao(1000), vivo(true) {}
// _______________________________________________________________________________
Bruxa::Bruxa(sf::Vector2f position, int tempo_direcao):
	tempo_direcao(tempo_direcao), vivo(true)
{
	this->recompensa = 20;
	this->iniciarSprite("./Recursos/Imagens/Personagens/bruxa.png", 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_BRUXA);
	this->sprite.setPosition(position);
	this->compMov.setControleArrasto(false);
	t = std::thread(executar,this);
}

void Bruxa::executar(Bruxa* bruxa)
{
	while (bruxa->vivo)
	{
		bruxa->mover();
	}
}
// _______________________________________________________________________________
Bruxa::~Bruxa()
{
	vivo = false;
	std::cout << "Teste" << std::endl;
}

// _______________________________________________________________________________
void Bruxa::mover()
{
	if (this->tempo_vida.getElapsedTime().asMilliseconds() > tempo_direcao) {
		direction = !direction;
		tempo_vida.restart();
	}

	if (direction)
		this->compMov.setVelX(-VEL_MAX_BRUXA);
	else
		this->compMov.setVelX(VEL_MAX_BRUXA);
	
}

// _______________________________________________________________________________
void Bruxa::atualizar()
{
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

// _______________________________________________________________________________
void Bruxa::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	hitbox.desenhar(janela);
}

int Bruxa::getTipo()
{
	return 1;
}