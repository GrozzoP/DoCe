#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "tipoJugador.h"
#include "IA.h"

#define		TO_STRING(X)	#X

void _cargarJugador(tJugador * py);
void _cargarIA(tJugador * py);
int cargarJugador(tJugador * jugA,tJugador * jugB);
int obtener_pos_carta_jugador();

#endif // JUGADOR_H_INCLUDED
