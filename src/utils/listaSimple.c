#include "../../include/utils/listaSimple.h"

void crear_lista(tLista* lista)
{
    *lista = NULL;
}

int lista_vacia(const tLista* lista)
{
    return *lista == NULL?	 LISTA_VACIA: LISTA_CONTIENE_DATOS;
}

int lista_llena(const tLista* lista, unsigned tam)
{
    return LISTA_NO_LLENA;
}

int poner_al_comienzo_lista(tLista* lista, const void* dato, unsigned tam)
{
    tNodo* nuevoNodo = malloc(sizeof nuevoNodo);
    if((NULL == nuevoNodo) || (nuevoNodo->dato = malloc(tam)) == NULL )
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

void vaciar_lista(tLista* lista)
{
    while (*lista)
    {
        tNodo* nodoAElim = *lista;
        *lista = nodoAElim->sig;
        free(nodoAElim->dato);
        free(nodoAElim);
    }
}

int sacar_primero_lista(tLista* lista, void* dato, unsigned tam)
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

int ver_primero_lista(const tLista* lista, void* dato, unsigned tam)
{
	if (NULL == *lista)
		return LISTA_VACIA;

	memcpy(dato, (*lista)->dato, MIN(tam, (*lista)->tam));

	return LISTA_TODO_OK;
}

void recorrer_lista(const tLista* lista, tMostrar mostrar)
{
    mostrar(NULL);
    while(*lista)
    {
        mostrar((*lista)->dato);
        lista = &(*lista)->sig;
    }
}

int insertar_ordenado_sin_duplicados_desc(tLista* lista, const void* dato, unsigned tam, void* parametro, tComparar comparar, tAccion accion)
{
    tNodo* nodoNuevo;
    int comparacion;

    while(*lista && (comparacion = comparar((*lista)->dato, dato)) > 0)
        lista = &(*lista)->sig;

    if(*lista && comparacion == 0)
    {
        accion((*lista)->dato, parametro);
        return LISTA_INSERCION_DUPLICADO;
    }

    if((nodoNuevo = (tNodo*)malloc(sizeof(tNodo))) == NULL ||
       (nodoNuevo->dato = malloc(tam)) == NULL)
    {
        free(nodoNuevo);
        return LISTA_LLENA;
    }

    memcpy(nodoNuevo->dato, dato, tam);
    nodoNuevo->tam = tam;

    nodoNuevo->sig = *lista;
    *lista = nodoNuevo;

    return LISTA_TODO_OK;
}

int map_lista(tLista* lista, tAccion accion, void* param)
{
	if(accion == NULL)
        return ACCION_NULA;

	while (*lista)
	{
	    accion((*lista)->dato, param);
		lista = &(*lista)->sig;
	}

	return LISTA_TODO_OK;
}
