#pragma once
#include "VelhoOeste.h"
#include "TelaPontuacao.h"
#include "MenuEscolhaFases.h"
#include "MenuQtdJogadores.h"

/* Classe do Menu Principal */
class MenuPrincipal :
    public Menu
{
private:
    // enumera botoes
    enum BotoesMenu {
        novo_jogo = 0,
        escolha_de_fases,
        lista_de_pontuacoes,
        sair
    };

public:
    // Construtoras e Destrutoras
    MenuPrincipal(JogoInfo* pji = NULL);
    ~MenuPrincipal();
    
    // Metodos de Inicializa��o
    void iniciarBotoes();

    // M�todos de Atualiza��o
    void atualizar();
    void GerenciarCliqueBotao();
};

