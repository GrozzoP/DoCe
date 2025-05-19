#ifndef TIPOJUGADOR_H_INCLUDED
#define TIPOJUGADOR_H_INCLUDED

#include "mano.h"

#define TAM_CAD 50

typedef struct {
   char nombre[TAM_CAD];
   int puntajeAcumulado;
   tMano mano;
} tJugador;

#endif // TIPOJUGADOR_H_INCLUDED
