#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

enum{COLA_TODO_OK,COLA_LLENA,COLA_NO_LLENA,COLA_VACIA,COLA_CONTIENE_DATOS};
typedef struct sNodo tNodo;
typedef struct sCola tCola;


void crearCola(tCola* cola);
int enColar(tCola* cola, const void* dato, unsigned tam);
int desEnColar(tCola* cola, void* dato, unsigned tam);
int verPrimero(tCola* cola, void* dato, unsigned tam);
int colaLlena(const tCola* cola, unsigned tam);
int colaVacia(const tCola* cola);
void vaciarCola(tCola* cola);

int consumirCola(tCola* cola, int (*func)(void* dato, void* param), void* param);

#endif // COLADINAMICA_H_INCLUDED
