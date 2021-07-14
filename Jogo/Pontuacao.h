#pragma once
#include "Ente.h"

/* Classe do menu de Pontua��o */
class Pontuacao :
    public Ente
{
private:

public:
    // Construtoras e Destrutoras
    Pontuacao();
    Pontuacao(EnteInfo* pei);
    ~Pontuacao();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderWindow& janela);
};

