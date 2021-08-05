#include "stdafx.h"
#include "GeradorProjeteis.h"

GeradorProjeteis::GeradorProjeteis():listIni(NULL),listProj(NULL),ini(NULL){}

GeradorProjeteis::~GeradorProjeteis(){
	this->ini = NULL;
	this->listIni = NULL;
	this->listProj = NULL;
}

void GeradorProjeteis::CriarProjetil()
{
	if (ini == NULL)
		ini = listIni->getPrimeiro();
	else {
		Inimigo* pini;
		Morcego* pmor;
		pini = ini->getInfo();
		if (tempo_atual.getElapsedTime().asMilliseconds() > 500)
		{
			pmor = new Morcego(1, pini->getPosition(), pini->getDirection());
			listProj->incluirProjetil(static_cast<Projetil*>(pmor));
			tempo_atual.restart();
			ini = ini->getProximo();
			
		}
		
	}
}

void GeradorProjeteis::ExcluirProjetil()
{
	Lista<Projetil>::Elemento<Projetil>* proj = listProj->getPrimeiro();
	Projetil* pproj;

	while (proj != NULL)
	{
		pproj = proj->getInfo();
		if (pproj->getTempoVida() > 2000)
		{
			listProj->excluirProjetil(pproj->getId());
		}
		proj = proj->getProximo();
	}
}

void GeradorProjeteis::iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp)
{
	this->listIni = li;
	this->listProj = lp;
}