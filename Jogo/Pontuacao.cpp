#include "stdafx.h"
#include "Pontuacao.h"

// _______________________________________________________________________________
Pontuacao::Pontuacao()
{
}

// _______________________________________________________________________________
Pontuacao::Pontuacao(EnteInfo* pei) :
	Ente(pei)
{
	// chama os metodos de inicializa��o
	this->iniciarBackground("./Recursos/Imagens/pontuacao.png");
	this->iniciarCaixa();
	this->iniciarBotao();
	this->iniciarLinhas();
}

// _______________________________________________________________________________
Pontuacao::~Pontuacao()
{
	delete this->enteInfo;
}

// _______________________________________________________________________________
void Pontuacao::iniciarCaixa()
{
	/* Inicia a caixa que engloba a lista de pontua�oes */
	this->caixaPontuacao.setFillColor(sf::Color(0, 0, 0, 150));

	// Inicia a caixa com 80% do tamanho da janela em comprimento e 60% em altura
	this->caixaPontuacao.setSize(sf::Vector2f(
		0.8f * static_cast<float>(this->enteInfo->janela->getSize().x),
		0.6f * static_cast<float>(this->enteInfo->janela->getSize().y)
	));

	// centraliza na tela
	this->caixaPontuacao.setPosition(
		this->enteInfo->janela->getSize().x / 2 - this->caixaPontuacao.getGlobalBounds().width / 2,
		this->enteInfo->janela->getSize().y / 2 - this->caixaPontuacao.getGlobalBounds().height / 2
	);
}

// _______________________________________________________________________________
void Pontuacao::iniciarBotao()
{
	/* Inicia o botao de voltar */
	this->botaoVoltar.iniciarBotao(
		this->enteInfo->janela->getSize().x / 2 - 100.f,
		this->enteInfo->janela->getSize().y - 100.f,
		"Voltar"
	);
	this->botaoVoltar.ativar();
}

// _______________________________________________________________________________
void Pontuacao::iniciarLinhas()
{
	/* Inicia Linhas */
	this->linhas.push_back(new Linha(
		this->caixaPontuacao.getPosition().x + 10.f,
		this->caixaPontuacao.getPosition().y + 10.f,
		"NOME", "PONTUA��O"
	));
}	

// _______________________________________________________________________________
void Pontuacao::atualizar()
{
}

// _______________________________________________________________________________
void Pontuacao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Enter)
			this->enteInfo->entes->pop(); // volta ao menu principal
	}
}
// _______________________________________________________________________________
void Pontuacao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha novo frame*/
	janela.draw(this->background);
	janela.draw(this->caixaPontuacao);
	this->botaoVoltar.desenharBotao(janela);

	for (auto& linha : this->linhas)
		linha->desenharLinha(janela);
}		