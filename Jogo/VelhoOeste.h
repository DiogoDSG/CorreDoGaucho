#pragma once
#include "Fase.h"
class VelhoOeste :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    VelhoOeste();
    VelhoOeste(EnteInfo* pei);
    ~VelhoOeste();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderWindow& janela);
};

