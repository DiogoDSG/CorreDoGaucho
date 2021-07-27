#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(JogoInfo* pji)
	: Fase(pji), mapa("./Recursos/mapas/velho_oeste.txt", 1, 13)
{
	this->iniciarBackground("./Recursos/Imagens/backgrounds/velho_oeste.png");
	this->jogoInfo->getTocaDisco()->tocarFallenDown();
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
}

// _______________________________________________________________________________
void VelhoOeste::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape){
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->popEnte(); // volta ao menu principal
		}
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->background);
	this->mapa.desenharMapa(janela);
}