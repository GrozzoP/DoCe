#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#include "utils/colaDinamica.h"
#include "utils/vistas.h"
#include "mazo.h"
#include "jugada.h"
#include "jugador.h"
#include "../config.h"

typedef int(*ACCION)(tJugador* ia, tCarta * ultima_carta, int puntaje_jugador);
void intercambiar_mazos(tLista * mazoA,tLista * mazoB,int * CantidadCartas);
void imprimir_turnos(tCola* cola_regTurnos,FILE*pf);
void almacenar_turno(tCola* cola_regTurnos,tJugador* primer_jugador,tJugador* segundo_jugador,tCarta carta_primer_jugador, tCarta carta_segundo_jugador,int turno);
void asignar_puntos(tJugador* jugPrincipal,tJugador* jugContrincante,tCarta* principal, tCarta* contrincante);
void procesar_partida(tLista* masoA, tLista * masoB,tCola * cola_regTurnos,tJugador* primer_jugador,tJugador* segundo_jugador,int posIA,ACCION POS_IA);
void partida(tLista * masoA, tLista* masoB, tCola* cola_regTurnos,tJugador* primer_jugador,tJugador* segundo_jugador, int posIA);
int juegoDOCE();
#endif // PARTIDA_H_INCLUDED
