#include "../include/ranking.h"

void mostrar_jugador_API(const void* dato)
{
    tJugadorAPI* jugadorAPI = (tJugadorAPI*)dato;
    if(jugadorAPI == NULL)
        printf("%-20s %-20s\n", "Nombre", "Partidas Ganadas");
    else
        printf("%-20s %-2d\n", jugadorAPI->nombreJugador, jugadorAPI->cantidadPartidasGanadas);
}

int comparar_jugador_API(const void* a, const void* b)
{
    tJugadorAPI a_jugador = *(tJugadorAPI*)a;
    tJugadorAPI b_jugador = *(tJugadorAPI*)b;

    return a_jugador.cantidadPartidasGanadas - b_jugador.cantidadPartidasGanadas;
}

int parsear_jugador(tRespuesta* res, tJugadorAPI* jugador)
{
    char* pJsonPosterior, *pJsonAnterior;

    if(!(res->info))
        return SIN_MEM;

    pJsonPosterior = res->info;
    pJsonAnterior = res->info;

    pJsonPosterior = strrchr(res->info, '}');

    if(!pJsonPosterior)
        return CHAR_NO_ENCONTRADO;

    *pJsonPosterior = '\0';

    pJsonAnterior = strrchr(res->info, ':');

    sscanf(pJsonAnterior + 1, "%d", &jugador->cantidadPartidasGanadas);

    pJsonPosterior = strrchr(res->info, ',');

    pJsonPosterior--;
    *pJsonPosterior = '\0';


    pJsonAnterior = strrchr(res->info, '"');

    pJsonAnterior++;

    strcpy(jugador->nombreJugador, pJsonAnterior);


    pJsonPosterior = strrchr(res->info, '{');
    *pJsonPosterior = '\0';

    return TODO_OK;
}

int ver_ranking(const char* url)
{
    tRespuesta res;
    tJugadorAPI jugador;
    tLista lista;
    CURLcode res_curl;

    if((res_curl=peticion_GET(&res, url)) != CURLE_OK)
        return res_curl;

    crear_lista(&lista);

    while(!parsear_jugador(&res, &jugador))
        insertar_ordenado_desc(&lista, &jugador, sizeof(tJugadorAPI), comparar_jugador_API);
    printf("Ranking Historico\n\n");
    recorrer_lista(&lista, mostrar_jugador_API);

    free(res.info);
    vaciar_lista(&lista);

    return TODO_OK;
}
