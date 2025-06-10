#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <string.h>
#include "tipoPoder.h"
#include "../config.h"
#include "utils/comun.h"

typedef struct
{
    tPoder tipoPoder;
} tCarta;

int obtener_tipoPoder_segun_carta(const char* nomb);
char* obtener_stringPoder(tCarta* carta);

#endif // CARTA_H_INCLUDED
