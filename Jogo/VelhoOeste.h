#pragma once
#include "Fase.h"
#include "Mapa.h"
class VelhoOeste :
    public Fase
{
private:
    Mapa mapa;
public:
    // Construtoras e Destrutoras
    VelhoOeste();
    VelhoOeste(JogoInfo* pji);
    ~VelhoOeste();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);

};

