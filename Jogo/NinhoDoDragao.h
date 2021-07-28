#pragma once
#include "Fase.h"
#include "Cowboy.h"
#include "Cowboy2.h"

class NinhoDoDragao :
    public Fase
{
private:
    Mapa mapa;
    Cowboy cowboy;
    Cowboy2 cowboy2;

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(JogoInfo* pji = NULL);
    ~NinhoDoDragao();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);

};

