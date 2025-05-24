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

int parsearJugador(tRespuesta* res, tJugadorAPI* jugador)
{
    char* pJsonPosterior, *pJsonAnterior, *nombre;

    if(!(res->info))
        return -1;

    nombre = malloc(TAM_NOMBRE);

    if(!nombre)
        return -1;

    // Este puntero siempre apuntara a una direccion mayor, sera mi referencia HASTA donde debo leer
    pJsonPosterior = res->info;
    // Este puntero siempre apuntara a una direccion menor, sera mi referencia DESDE donde debo leer
    pJsonAnterior = res->info;

    pJsonPosterior = strrchr(res->info, '}');

    if(!pJsonPosterior)
        return -1;

    // Como se que no piso un dato, pongo el sentinela para copiar mas adelante
    *pJsonPosterior = '\0';

    // Si encuentro ':', estoy en un caracter anterior al comienzo del dato
    pJsonAnterior = strrchr(res->info, ':');

    // Copio la cantidad de partidas ganadas
    sscanf(pJsonAnterior + 1, "%d", &jugador->cantidadPartidasGanadas);

    // Busco el otro dato relativo al jugador, que es el nombre, primero busco el separador ','
    pJsonPosterior = strrchr(res->info, ',');
    // Decremento en uno para situarme en la ultima " que cierra el nombre
    pJsonPosterior--;
    *pJsonPosterior = '\0';

    // Dejo el puntero menor en la primer comilla que abre el nombre
    pJsonAnterior = strrchr(res->info, '"');
    // Cuando aumento, me encuentro en la primer letra del nombre
    pJsonAnterior++;

    // Copio el nombre en la estructura del jugador
    strcpy(jugador->nombreJugador, pJsonAnterior);

    // Me situo en el '{' para sacar de la cadena el jugador que ya acabo de leer
    pJsonPosterior = strrchr(res->info, '{');
    *pJsonPosterior = '\0';

    return 0;
}

int verRanking(const char* url)
{
    tRespuesta res;
    tJugadorAPI jugador;
    tLista lista;

    if(peticion_GET(&res, url) != CURLE_OK)
        return -1;

    crear_lista(&lista);

    while(!parsearJugador(&res, &jugador))
        insertar_ordenado_sin_duplicados_desc(&lista, &jugador, sizeof(tJugadorAPI), NULL, comparar_jugador_API, NULL);

    recorrer_lista(&lista, mostrar_jugador_API);

    free(res.info);
    vaciar_lista(&lista);

    return 0;
}
