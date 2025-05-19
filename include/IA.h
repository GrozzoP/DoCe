#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "tipoJugador.h"

typedef enum {IA_FACIL, IA_NORMAL, IA_DIFICIL} eDificultad;

void juega_IA(tMazo* mazo, const tJugador* ia, const tCarta* ult_carta, int puntaje_jugador);

#endif // IA_H_INCLUDED
