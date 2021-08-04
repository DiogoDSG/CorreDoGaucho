#pragma once
#include "Tela.h"

/* Classe Abstrata de um Menu Generico */
class Menu :
    public Tela
{
protected:
    // armazena os botoes do menu 
    std::map<int, gui::Botao* > botoes;
    sf::RectangleShape caixaBotoes;
    int botaoAtivo;

public:
    // Construtoras e Destrutoras
    Menu(JogoInfo* pji = NULL);
    virtual ~Menu();

    // Metodos de Inicializa��o
    virtual void iniciarBotoes() = 0;

    // M�todos de Atualiza��o
    virtual void atualizarEventos(sf::Event& evento_sfml);
    void trocarBotao(int direcao);
    virtual void GerenciarCliqueBotao() = 0;

    // M�todos de Renderiza��o
    virtual void desenhar(sf::RenderTarget& janela);
};

