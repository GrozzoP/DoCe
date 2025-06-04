#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

enum{COLA_TODO_OK, COLA_LLENA, COLA_NO_LLENA, COLA_VACIA, COLA_CONTIENE_DATOS};

#define MIN(X,Y) ((X)<=(Y))?(X):(Y)

#include <string.h>
#include <stdlib.h>

typedef struct sNodoC
{
    void* dato;
    unsigned tam;
    struct sNodoC* sig;
} tNodoC;

typedef struct
{
    tNodoC* pri;
    tNodoC* ult;
} tCola;

void crear_cola(tCola* cola);
int enColar(tCola* cola, const void* dato, unsigned tam);
int desEnColar(tCola* cola, void* dato, unsigned tam);
int ver_primero(tCola* cola, void* dato, unsigned tam);
int cola_llena(const tCola* cola, unsigned tam);
int cola_vacia(const tCola* cola);
void vaciar_cola(tCola* cola);

int consumir_cola(tCola* cola, int (*func)(void* dato, void* param), void* param);

#endif // COLADINAMICA_H_INCLUDED
