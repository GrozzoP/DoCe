#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#include "../lib/conectarAPI.h"
#include "utils/listaSimple.h"

void mostrar_jugador_API(const void* dato);
int comparar_jugador_API(const void* a, const void* b);
int parsearJugador(tRespuesta* res, tJugadorAPI* jugador);
int verRanking(const char* url);

#endif // RANKING_H_INCLUDED
