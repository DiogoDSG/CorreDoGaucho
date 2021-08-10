#pragma once
#include "Fase.h"
#include "Cowboy.h"
#include "CowGirl.h"
#include "Dragao.h"

class NinhoDoDragao :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(JogoInfo* pji = NULL, int n_jogadores = 1);
    ~NinhoDoDragao();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
    
    void iniciarInimigos();
};

