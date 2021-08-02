#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji):
	Ente(pji)
{
}

// _______________________________________________________________________________
Fase::~Fase()
{
	for (auto& personagem : this->personagens)
		delete personagem;
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	this->personagens.push_back(new Cowboy("./Recursos/Imagens/Personagens/cowboy.png"));
	this->personagens.push_back(new CowGirl("./Recursos/Imagens/Personagens/cowgirl.png"));
}

// _______________________________________________________________________________
void Fase::iniciarMapa(std::string dir, int ini, int qtd, int tipo)
{
	this->mapa.iniciarMapa(dir, ini, qtd, tipo);
}

// _______________________________________________________________________________
void Fase::iniciarGerenciadorColisoes()
{
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->personagens);
}
