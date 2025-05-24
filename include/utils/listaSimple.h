#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

enum{LISTA_TODO_OK, LISTA_LLENA, LISTA_NO_LLENA, LISTA_VACIA, LISTA_CONTIENE_DATOS, LISTA_INSERCION_DUPLICADO, ACCION_NULA};

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

typedef int (tComparar)(const void*, const void*);
typedef void (tAccion)(void*, void*);
typedef void (tMostrar)(const void*);

void crear_lista(tLista* lista);
void vaciar_lista(tLista* lista);
int lista_vacia(const tLista* lista);
int lista_llena(const tLista* lista, unsigned tam);
int poner_al_comienzo_lista(tLista* lista, const void* dato, unsigned tam);
int sacar_primero_lista(tLista* lista, void* dato, unsigned tam);
int ver_primero_lista(const tLista* lista, void* dato, unsigned tam);
void recorrer_lista(const tLista* lista, tMostrar mostrar);
int insertar_ordenado_sin_duplicados_desc(tLista* lista, const void* dato, unsigned tam, void* parametro, tComparar comparar, tAccion accion);
int poner_en_lista_pos(tLista * pL,const void * dato,unsigned cantBytes,unsigned pos);

int map_lista(tLista* lista, tAccion accion, void* param);

#endif // LISTASIMPLE_H_INCLUDED
