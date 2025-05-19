#ifndef TIPOJUGADOR_H_INCLUDED
#define TIPOJUGADOR_H_INCLUDED

#include "mano.h"

#define TAM_CAD 50

typedef struct {
   char nombre[TAM_CAD];
   int puntajeAcumulado;
   tMano mano;
} tJugador;

signed char buscar_carta_en_mano(const tJugador* j, tPoder PODER);

#endif // TIPOJUGADOR_H_INCLUDED
