#pragma once
#include "Tela.h"
#include "Pontuacao.h"
class TelaMorte :
    public Tela
{
private:
    // variaveis
    int score;
    sf::Text textoMorte;
    sf::Text textoScore;
    sf::Text digiteNome;
    sf::Text nome;
    std::string nomeInput;
    sf::Font fonte;

public:
    // construtores e destrutoras
    TelaMorte(JogoInfo* pji = NULL, int s = 0);
    ~TelaMorte();

    // Metodos de inicializa��o
    void iniciarTextos();

    // M�todos de Atualiza��o
    void adicionarPontuacao();
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
};

