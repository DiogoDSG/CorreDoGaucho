#pragma once

#include "MenuPrincipal.h"
#include "JogoInfo.h"

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

	// Armazena as informa�oes do jogo
	JogoInfo jogoInfo;

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

