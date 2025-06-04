#ifndef TIPOJUGADOR_H_INCLUDED
#define TIPOJUGADOR_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "mano.h"
#define TAM_CAD 50

typedef struct {
   char nombre[TAM_CAD];
   int puntajeAcumulado;
   tMano mano;
} tJugador;

int buscar_carta_en_mano(tJugador* jugador, tPoder PODER);

#endif // TIPOJUGADOR_H_INCLUDED
