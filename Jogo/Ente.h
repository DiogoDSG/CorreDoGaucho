#pragma once

#include "Botao.h"
#include "JogoInfo.h"

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
    Ente();
    Ente(JogoInfo* pji);
    virtual ~Ente();

    // Metodos de Inicializa��o
    void iniciarBackground(std::string diretorio);

    // Setters e getters
    const bool getEncerrar() const;
    void setEncerrar(const bool e);

    // M�todos de Atualiza��o
    virtual void atualizar() = 0;
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;

    // M�todos de Renderiza��o
    virtual void desenhar(sf::RenderTarget& janela) = 0;

};

