#include "stdafx.h"
#include "ListaInimigos.h"

ListaInimigos::ListaInimigos()
    : listaInimigos()
{
}

ListaInimigos::~ListaInimigos()
{
    this->listaInimigos.limpaLista();
}

void ListaInimigos::incluirInimigo(Inimigo* i)
{
    if (i != NULL)
        this->listaInimigos.incluaInfo(i);
}

void ListaInimigos::removerInimigo(int id)
{
    this->listaInimigos.removerElemento(id);
}

const bool ListaInimigos::listaVazia()
{
    return this->listaInimigos.listaVazia();
}

Lista<Inimigo>::Elemento<Inimigo>* ListaInimigos::getPrimeiro()
{
    return this->listaInimigos.getPrimeiro();
}
