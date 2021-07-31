#pragma once
#include "NinhoDoDragao.h"
#include "Jogador.h"
#include "TelaMorte.h"

class VelhoOeste :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    VelhoOeste(JogoInfo* pji = NULL);
    ~VelhoOeste();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);

};
