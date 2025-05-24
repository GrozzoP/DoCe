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

    //Setea el ambiente necesario para ejecutar funciones de libreria. Basta con llamarlo una vez
    //en la vida del programa. Como nos manejamos por funciones, lo hago en cada una

    codRespuesta = curl_global_init(CURL_GLOBAL_DEFAULT);

    if(codRespuesta != CURLE_OK)
        printf("\nFallo el setup global de CURL: %s\n", curl_easy_strerror(codRespuesta));

    // Devuelve un 'easy handler' que sirve para controlar una transferencia de red
    curl = curl_easy_init();

    if(!curl)
        return CURLE_FAILED_INIT;

    // Indica como se debe comportar libcurl. En este caso, vamos a asignar la URL pasada por parametro
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Asigno la funcion para escribir en memoria reservada el resultado
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    // Se exhibe que puntero a estructura utilizara la funcion de callback para almacenar informacion
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, respuesta);

    // Verifica el certificado SSL para observar si la conexion es segura
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    // Una vez realizada la configuracion, se realiza la peticion GET
    codRespuesta = curl_easy_perform(curl);

    // Hace un 'free' de los recursos utilizados por el 'easy handler'
    curl_easy_cleanup(curl);
    // Hace un 'free' de los recursos utilizados por el 'curl_global_init'
    curl_global_cleanup();

    if(codRespuesta != CURLE_OK)
        printf("\nFallo la peticion: %s\n", curl_easy_strerror(codRespuesta));

    return codRespuesta;
}

CURLcode peticion_POST(tRespuesta* respuesta, const char* URL, const char* JSON)
{
    CURLcode codRespuesta;
    CURL* curl;
    // Es una estructura de la libreria que funciona como una lista enlazada simple
    struct curl_slist* headers = NULL;

    codRespuesta = curl_global_init(CURL_GLOBAL_DEFAULT);

    if(codRespuesta != CURLE_OK)
        printf("\nFallo el setup global de CURL: %s\n", curl_easy_strerror(codRespuesta));

    curl = curl_easy_init();

    if(!curl)
        return CURLE_FAILED_INIT;

    // Se agregan los encabezados para definir que el contenido es JSON
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Se especifica que el metodo es POST, y se le pasan los datos JSON
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, JSON);

    // Se establecen los headers en la peticion
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Configuracion necesaria para la liberiael resultado (explicada en GET)
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, respuesta);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    // Realizar la solicitud POST
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
    ((jugador->puntajeAcumulado) >= 12) ? 1 : 0
    );

    return peticion_POST(&respuesta, API_URL_BASE, JSON);
}
