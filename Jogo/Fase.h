#pragma once
#include "Ente.h"
#include "Mapa.h"
#include "Cowboy2.h"
#include "GerenciadorColisoes.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:
    Mapa mapa;
    GerenciadorColisoes gerColisoes;
    std::vector<Personagem* > personagens;

public:
    // Construtoras e Destrutoras
    Fase(JogoInfo* pji = NULL);
    virtual ~Fase();

    // metodos de inicializacao
    void iniciarPersonagens();
    void iniciarMapa(std::string dir, int ini, int qtd);
    void iniciarGerenciadorColisoes();
};

