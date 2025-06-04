#include "conectarAPI.h"

/* Si no se usa esta funcion, por default, la libreria utiliza fwrite(),
   su implementacion es necesaria para controlar la reserva de la memoria e
   informar en caso de no exito en el malloc. */

size_t WriteMemoryCallback(void* contenido, size_t tam, size_t nmemb, void* usuario)
{
  size_t tamReal = tam * nmemb;
  tRespuesta* respuesta = (tRespuesta*)usuario;

  // Se reserva tamReal + 1 para guardar en el string el sentinela
  if((respuesta->info = malloc(tamReal + 1)) == NULL)
  {
      printf("\nNo se pudo reservar memoria.\n");
      return 0;
  }

  // Se copia todo a la estructura que permite observar la respuesta
  memcpy(respuesta->info, contenido, tamReal);
  *(respuesta->info + tamReal) = '\0';
  respuesta->tam = tamReal;

  return tamReal;
}

CURLcode peticion_GET(tRespuesta* respuesta, const char* URL)
{
    CURLcode codRespuesta;
    CURL* curl;

    codRespuesta = curl_global_init(CURL_GLOBAL_DEFAULT);

    if(codRespuesta != CURLE_OK)
        printf("\nFallo el setup global de CURL: %s\n", curl_easy_strerror(codRespuesta));

    curl = curl_easy_init();

    if(!curl)
        return CURLE_FAILED_INIT;

    curl_easy_setopt(curl, CURLOPT_URL, URL);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, respuesta);

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    codRespuesta = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    curl_global_cleanup();

    if(codRespuesta != CURLE_OK)
        printf("\nFallo la peticion: %s\n", curl_easy_strerror(codRespuesta));

    return codRespuesta;
}

CURLcode peticion_POST(tRespuesta* respuesta, const char* URL, const char* JSON)
{
    CURLcode codRespuesta;
    CURL* curl;
    struct curl_slist* headers = NULL;

    codRespuesta = curl_global_init(CURL_GLOBAL_DEFAULT);

    if(codRespuesta != CURLE_OK)
        printf("\nFallo el setup global de CURL: %s\n", curl_easy_strerror(codRespuesta));

    curl = curl_easy_init();

    if(!curl)
        return CURLE_FAILED_INIT;

    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, URL);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, JSON);

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, respuesta);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    codRespuesta = curl_easy_perform(curl);

    if(codRespuesta != CURLE_OK)
        printf("\nFallo la peticion: %s\n", curl_easy_strerror(codRespuesta));

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return codRespuesta;
}

CURLcode enviar_jugador_JSON(const tJugador* jugador)
{
    char JSON[MAX_JSON];
    tRespuesta respuesta;

    snprintf(JSON, sizeof(JSON),
    "{\"CodigoGrupo\":\"%s\", \"jugador\":{\"nombre\":\"%s\",\"vencedor\":%d}}",
    CODIGO_GRUPO,
    jugador->nombre,
    1
    );

    return peticion_POST(&respuesta, API_URL_BASE, JSON);
}
