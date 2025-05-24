#ifndef CONECTARAPI_H_INCLUDED
#define CONECTARAPI_H_INCLUDED

#define MAX_JSON 200
#define TAM_NOMBRE 50
#define API_URL_CON_CODIGO "https://algoritmos-api.azurewebsites.net/api/doce/handler"
#define API_URL_BASE "https://algoritmos-api.azurewebsites.net/api/doce"
#define CODIGO_GRUPO "handler"

#include <curl/curl.h>
#include "../include/jugador.h"

typedef struct
{
    char* info;
    size_t tam;
} tRespuesta;

typedef struct {
    char nombreJugador[TAM_NOMBRE];
    int cantidadPartidasGanadas;
} tJugadorAPI;

size_t WriteMemoryCallback(void* contenido, size_t tam, size_t nmemb, void* usuario);
CURLcode enviar_jugador_JSON(const tJugador* jugador);
CURLcode peticion_GET(tRespuesta* respuesta, const char* URL);
CURLcode peticion_POST(tRespuesta* respuesta, const char* URL, const char* JSON);

#endif // CONECTARAPI_H_INCLUDED
