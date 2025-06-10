#ifndef JUGADA_H_INCLUDED
#define JUGADA_H_INCLUDED

#include "carta.h"

typedef struct {
    unsigned nroJugada;
    char *nombreJugador[2];
    char cartaJugada_primer_jugador[14],
         cartaJugada_segundo_jugador[14];
    int puntajeAcumulado_primer_jugador,
        puntajeAcumulado_segundo_jugador;
} tJugada;

#endif // JUGADA_H_INCLUDED
