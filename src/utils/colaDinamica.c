#include "../../include/utils/colaDinamica.h"

void crear_cola(tCola* cola)
{
    cola->pri = cola->ult = NULL;
}

int enColar(tCola* cola, const void* dato, unsigned tam)
{
    tNodoC* nue =(tNodoC*) malloc(sizeof(tNodoC));

    if (!nue)
        return COLA_LLENA;

    nue->dato = malloc(tam);

    if (!nue->dato)
    {
        free(nue);
        return COLA_LLENA;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = NULL;

    if (!cola->pri)
        cola->pri = nue;

    if (cola->ult)
        cola->ult->sig = nue;

    cola->ult = nue;

    return COLA_TODO_OK;
}

int desEnColar(tCola* cola, void* dato, unsigned tam)
{
    tNodoC* elim = cola->pri;

    if (!elim)
        return COLA_VACIA;

    memcpy(dato, elim->dato, MIN(tam, elim->tam));
    cola->pri = elim->sig;
    free(elim->dato);
    free(elim);

    if (!cola->pri)
        cola->ult = NULL;

    return COLA_TODO_OK;
}

int ver_primero(tCola* cola, void* dato, unsigned tam)
{
    if (!cola->pri)
        return COLA_VACIA;

    memcpy(dato, cola->pri->dato, MIN(tam, cola->pri->tam));

    return COLA_TODO_OK;
}

int cola_llena(const tCola* cola, unsigned tam)
{
    tNodoC* nue = (tNodoC*)malloc(sizeof(tNodoC));

    if (!nue)
        return COLA_LLENA;

    nue->dato = malloc(tam);

    if (!nue->dato)
    {
        free(nue);
        return COLA_LLENA;
    }

    free(nue->dato);
    free(nue);

    return COLA_NO_LLENA;
}

int cola_vacia(const tCola* cola)
{
    return cola->pri == NULL?  COLA_VACIA: COLA_CONTIENE_DATOS;
}

void vaciar_cola(tCola* cola)
{
    tNodoC* elim;

    while (cola->pri != NULL)
    {
        elim = cola->pri;
        cola->pri = elim->sig;
        free(elim->dato);
        free(elim);
    }

    cola->ult = NULL;
}


int consumir_cola(tCola* cola,  int (*func)(void* dato, void* param), void* param)
{
	tNodoC* elim = cola->pri;
	if (!elim)	return COLA_VACIA;

	do
    {
		func(elim->dato, param);

		cola->pri = elim->sig;
		free(elim->dato);
		free(elim);
		elim = cola->pri;
    }
    while (elim);
	cola->ult = NULL;

    return COLA_TODO_OK;
}
