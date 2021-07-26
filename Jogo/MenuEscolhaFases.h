#pragma once
#include "VelhoOeste.h"
#include "Pontuacao.h"
#include "Menu.h"


class MenuEscolhaFases :
    public Menu
{
private:
    // enumera botoes
    enum BotoesMenu {
        velho_oeste = 0,
        ninho_do_dragao,
        voltar
    };
public:
    // Construtoras e Destrutoras
    MenuEscolhaFases(JogoInfo* pji = NULL);
    ~MenuEscolhaFases();

    // Metodos de Inicializa��o
    void iniciarBotoes();

    // M�todos de Atualiza��o
    void atualizar();
    void GerenciarCliqueBotao();
};
