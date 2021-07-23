#pragma once
#include "VelhoOeste.h"
#include "Pontuacao.h"

// enumera botoes
enum BotoesEscolhaFase {
    velho_oeste = 0,
    ninho_do_dragao,
    voltar
};

class MenuEscolhaFases :
    public Ente
{

private:
    // armazena os botoes do menu de escolha de fases
    std::map<int, gui::Botao* > botoes;
    sf::RectangleShape caixaBotoes;
    int botaoAtivo;

public:
    // Construtoras e Destrutoras
    MenuEscolhaFases(JogoInfo* pji = NULL);
    ~MenuEscolhaFases();

    // Metodos de Inicializa��o
    void iniciarBotoes();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);
    void trocarBotao(int direcao);
    void GerenciarCliqueBotao();

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
};

