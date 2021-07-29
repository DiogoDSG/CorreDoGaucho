#pragma once

#include "Botao.h"
#include "JogoInfo.h"
#include "configuracoes.h"

/* Classe abstrata de Entes */
class Ente
{
protected:
	// Variaveis
    JogoInfo* jogoInfo;

    // background
    sf::Texture texturaBg;
    sf::Sprite background;

public:
    // Construtoras e Destrutoras
    Ente(JogoInfo* pji = NULL);
    virtual ~Ente();

    // Metodos de Inicializa��o
    void iniciarBackground(std::string diretorio);

    // M�todos de Atualiza��o
    virtual void atualizar() = 0;
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;

    // M�todos de Renderiza��o
    virtual void desenhar(sf::RenderTarget& janela) = 0;

};

