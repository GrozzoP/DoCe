#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipoJugador.h"
#include "utils/listaSimple.h"
#include "../config.h"

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#define		TO_STRING(X)	#X

int cargar_carta_lista_random(tLista* pL, const char* nombArch);
int crear_archivo_cartas(const char* nombreArch);
int pedir_carta_mazo(tLista* mazoA, tJugador* jugador, int pos);
void remezclar_mazo(const tCarta* val, tLista* pL, unsigned cantCartas);
void descartar_carta_mano(tLista* mazoB, tJugador* jugador, int pos, int cantCartas);
void cargar_mano(tJugador* py, tLista* lista);
void descartar_mano(tJugador* py, tLista* lista);


#endif // MAZO_H_INCLUDED
