#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED


#include "tipoJugador.h"


typedef enum {IA_FACIL, IA_NORMAL, IA_DIFICIL} eDificultad;

int obtener_pos_carta_IAdificil(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador);
int obtener_pos_carta_IAnormal(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador);
int obtener_pos_carta_IAfacil(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador);
#endif // IA_H_INCLUDED
