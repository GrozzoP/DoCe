#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

enum{LISTA_TODO_OK, LISTA_LLENA, LISTA_NO_LLENA, LISTA_VACIA, LISTA_CONTIENE_DATOS};

#include <stdlib.h>
#include <string.h>

#define MIN(X,Y) ((X)<=(Y))?(X):(Y)

typedef struct sNodo
{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* lista);
void vaciarLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLLena(const tLista* lista, unsigned tam);
int ponerAlComienzoLista(tLista* lista, const void* dato, unsigned tam);
int sacarPrimeroLista(tLista* lista, void* dato, unsigned tam);
int verPrimeroLista(const tLista* lista, void* dato, unsigned tam);

int mapLista(const tLista* lista, int (*func)(void* dato, void* param), void* param);

#endif // LISTASIMPLE_H_INCLUDED
