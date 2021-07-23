#pragma once
#include "Fase.h"
class NinhoDoDragao :
    public Fase
{
private:
    Mapa mapa;

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

