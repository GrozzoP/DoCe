#include "../../include/utils/listaSimple.h"

void crearLista(tLista* lista)
{
    *lista = NULL;
}

int listaVacia(const tLista* lista)
{
    return *lista == NULL?	 LISTA_VACIA: LISTA_CONTIENE_DATOS;
}

int listaLLena(const tLista* lista, unsigned tam)
{
    return LISTA_NO_LLENA;
}

int ponerAlComienzoLista(tLista* lista, const void* dato, unsigned tam)
{
    tNodo* nuevoNodo = malloc(sizeof nuevoNodo);
    if( (NULL == nuevoNodo) || (nuevoNodo->dato = malloc(tam)) == NULL )
    {
        free(nuevoNodo);
        return 0;
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *lista;
    *lista = nuevoNodo;

    return LISTA_TODO_OK;
}

void vaciarLista(tLista* lista)
{
    while (*lista)
    {
        tNodo* nodoAElim = *lista;
        *lista = nodoAElim->sig;
        free(nodoAElim->dato);
        free(nodoAElim);
    }
}

int sacarPrimeroLista(tLista* lista, void* dato, unsigned tam)
{
    if (NULL == *lista)
        return LISTA_VACIA;

    tNodo* nodoAElim = *lista;
    *lista = nodoAElim->sig;
    memcpy(dato, nodoAElim->dato, MIN(nodoAElim->tam, tam));
    free(nodoAElim->dato);
    free(nodoAElim);

    return LISTA_TODO_OK;
}

int verPrimeroLista(const tLista* lista, void* dato, unsigned tam)
{
	if (NULL == *lista)
		return LISTA_VACIA;
	memcpy(dato, (*lista)->dato, MIN(tam, (*lista)->tam));

	return LISTA_TODO_OK;
}

int mapLista(const tLista* lista, int (*func)(void* dato, void* param), void* param)
{
	int ret;
	while (*lista)
	{
		if((ret = func((*lista)->dato, param)))
			return ret;
		lista = &(*lista)->sig;
	}

	return LISTA_TODO_OK;
}
