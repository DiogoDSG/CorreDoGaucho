#pragma once
#include "Fase.h"
#include "Cowboy.h"
#include "CowGirl.h"
#include "Dragao.h"

class NinhoDoDragao :
    public Fase
{
private:
    sf::Clock timerInvocarBruxa;
    int qtdMaxBruxas;
    int qtdBruxas;

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(JogoInfo* pji = NULL, int n_jogadores = 1, bool carregar_jogo = false);
    ~NinhoDoDragao();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);
    void invocarBruxa();

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
    
    void iniciarInimigos();
};

