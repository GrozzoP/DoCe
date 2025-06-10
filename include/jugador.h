#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tipoJugador.h"
#include "IA.h"

#define		TO_STRING(X)	#X

int cargar_jugador(tJugador* py);
void cargar_IA(tJugador* py);
int cadena_solo_espacios(const char* str);
int cargar_jugadores(tJugador* jugA,tJugador* jugB);
int obtener_pos_carta_jugador();
int buscar_carta_no_negativa(tJugador* jugador);

#endif // JUGADOR_H_INCLUDED
