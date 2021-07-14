#pragma once

#include "MenuPrincipal.h"

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

	// Armazena todos os entes
	std::stack<Ente* > entes;
	EnteInfo enteInfo;

public:
	// Construtoras e Destrutoras
	Jogo();
	~Jogo();

	// M�todos de Inicializa��o
	void iniciarJanela();
	void iniciarEnte();

	// M�todos de Atualiza��o
	void atualizar();
	void atualizarEventos();

	// M�todos de Renderiza��o
	void desenhar();

	// Inicia o Jogo
	void executar();
};

