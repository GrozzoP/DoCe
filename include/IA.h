#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED


#include "tipoJugador.h"


typedef enum {IA_FACIL, IA_NORMAL, IA_DIFICIL} eDificultad;

int obtener_pos_carta_IA_dificil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador);
int obtener_pos_carta_IA_normal(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador);
int obtener_pos_carta_IA_facil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador);
#endif // IA_H_INCLUDED
