#pragma once
#include "NinhoDoDragao.h"
#include "Jogador.h"
#include "TelaMorte.h"
#include "Bruxa.h"
#include "Cobra.h"

class VelhoOeste :
    public Fase
{
private:
    sf::Clock timerInvocarCobra;
    int qtdMaxCobras;
    int qtdCobras;

public:
    // Construtoras e Destrutoras
    VelhoOeste(JogoInfo* pji = NULL, int n_jogadores = 1);
    ~VelhoOeste();

    // Criar inimigos
    void invocarCobra();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
    void iniciarInimigos();

};
