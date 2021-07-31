#include "stdafx.h"
#include "Mapa.h"

// _______________________________________________________________________________
Mapa::Mapa() { 
	this->inicioPlataformas = -1;
	this->qtdPlataformas = -1;
}

// _______________________________________________________________________________
Mapa::~Mapa()
{
	// desaloca mapa e posicoes livres
	for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
			this->mapa[x][y] = NULL;
			this->posLivres[x][y] = NULL;
		}
	}

	// desaloca plataformas
	for (auto& ent : this->entidades) {
		delete ent;
	}
}

// _______________________________________________________________________________
const int Mapa::blocoAtual(sf::Vector2f pos) const
{
	/* Retona o bloco na posi��o passada por parametro */
	int pos_x = pos.x / 32;
	int pos_y = pos.y / 32;

	if (pos_x >= 0 && pos_y >= 0 && pos_x < TAM_MAPA_X && pos_y < TAM_MAPA_Y)
		return this->mapa[pos_x][pos_y]; // retorna a plataforma na posicao
	else
		return 0;
}

// _______________________________________________________________________________
Entidade* Mapa::getEntidade(const int i) const
{
	return this->entidades[i];
}

// _______________________________________________________________________________
void Mapa::iniciarMapa(std::string diretorio, int ini, int qtd)
{
	this->inicioPlataformas = ini;
	this->qtdPlataformas = qtd;
	this->carregarMapa(diretorio);
	this->iniciaPosicoesLivres();
	this->iniciarEntidades();
}

// _______________________________________________________________________________
void Mapa::carregarMapa(std::string diretorio)
{
	/* le o mapa apartir de um arquivo */
	this->mapa.resize(TAM_MAPA_X);
	for (unsigned int i = 0; i < TAM_MAPA_X; i++)
		this->mapa[i].resize(TAM_MAPA_Y);

	// abre o arquivo com o mapa
	std::fstream arquivo_mapa;
	arquivo_mapa.open(diretorio, std::ios::in);
	int n = 0;

	// salva o mapa na matriz mapa
	for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
			if (arquivo_mapa >> n)
				this->mapa[x][y] = n;
		}
	}
	arquivo_mapa.close();
}

// _______________________________________________________________________________
void Mapa::iniciaPosicoesLivres()
{
	/* aloca memoria suficiente*/
	this->posLivres.resize(TAM_MAPA_X);
	for (unsigned int i = 0; i < TAM_MAPA_X; i++)
		this->posLivres[i].resize(TAM_MAPA_Y);

	// inicia posicoes que podem recebem um obstaculo
	for (unsigned int y = 0; y < TAM_MAPA_Y - 1; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
			if ((this->mapa[x][y + (size_t)(1)] == 2 || this->mapa[x][y + (size_t)(1)] == 8) && this->mapa[x][y] == 0) // se for uma plataforma
				this->posLivres[x][y] = 1;
			else
				this->posLivres[x][y] = 0;
		}
	}
}

// _______________________________________________________________________________
void Mapa::iniciarEntidades()
{
	/* Inicia todas as plataformas e obstaculos*/
	// inicia todas as plataformas
	for (int i = 0; i < this->qtdPlataformas; i++) {
		this->entidades.push_back(static_cast<Entidade* >(new Plataforma(this->inicioPlataformas + i)));
	}
	
	// define as posi�oes dos obstaculos
	for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
		for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
			if (posLivres[x][y] == 1 && rand() % 3 == 0)
				this->mapa[x][y] = this->qtdPlataformas + rand() % 3 + 1;
		}
	}

	// incia obstaculos;
	this->entidades.push_back(static_cast<Entidade*>(new Cactus(1)));
	this->entidades.push_back(static_cast<Entidade*>(new Espinho(2)));
	this->entidades.push_back(static_cast<Entidade*>(new AreiaDasAlmas(3)));
}

// _______________________________________________________________________________
void Mapa::desenharMapa(sf::RenderTarget& janela)
{
	/* desenha todas as entidades */
	for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
		for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
			int ent = mapa[x][y] - 1;
			if (ent >= 0) {
				entidades[ent]->setPosicao((float)(x * TAM_BLOCO), (float)(y * TAM_BLOCO));
				entidades[ent]->desenharEntidade(janela);
			}
		}
	}
}
