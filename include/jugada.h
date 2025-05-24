#ifndef JUGADA_H_INCLUDED
#define JUGADA_H_INCLUDED

#include "carta.h"

typedef struct {
    unsigned nroJugada;
    char nombreJugador[TAM_CAD];
    char cartaJugada[13];
    int puntajeAcumulado;
} tJugada;

#endif // JUGADA_H_INCLUDED
