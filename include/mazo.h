#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipoJugador.h"
#include "utils/listaSimple.h"

#define		TO_STRING(X)	#X

int cargar_carta_lista_random(tLista * pL,const char * nombArch);

void pedir_carta_maso(tLista * masoA,tJugador * jugador,int pos);
void _remezclar_mazo(const tCarta * val,tLista *pL,unsigned cantCartas);
void descartar_carta_mano(tLista * masoB,tJugador * jugador,int pos,int cantCartas);
void cargarMano(tJugador * py,tLista * lista);
void descartar_mano(tJugador * py,tLista * lista);


#endif // MAZO_H_INCLUDED
