#pragma once
#include "Plataforma.h"
#include "Cactus.h"
#include "JogoInfo.h"

class Mapa
{
private:
	std::vector<std::vector<int > > mapa;
	std::vector<Entidade* > entidades;
	JogoInfo* jogoinfo;

	// armazena informa��es sobre o mapa
	sf::Vector2u tamMapa;
	float tamEntidade;

	// os arquivos est�o nomeados como "<nomemapa><numero>.png"
	// armazena o numero de inicio e fim de cada tipo de de entidade
	int inicioPlataformas;
	int qtdPlataformas;

public:
	// construtoras e destrutoras
	Mapa(JogoInfo* pji = NULL, std::string diretorio = "", int ini = 0, int qtd = 0);
	~Mapa();

	// metodos de inicializa��o
	void iniciarVariaveis();
	void carregarMapa(std::string diretorio);
	void iniciarEntidades();

	// metodo de renderiza��o
	void desenharMapa(sf::RenderTarget& janela);
};
