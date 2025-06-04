#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#include "../lib/conectarAPI.h"
#include "utils/listaSimple.h"
#include "utils/comun.h"

void mostrar_jugador_API(const void* dato);
int comparar_jugador_API(const void* a, const void* b);
int parsear_jugador(tRespuesta* res, tJugadorAPI* jugador);
int ver_ranking(const char* url);

#endif // RANKING_H_INCLUDED
