#include "../include/tipoJugador.h"

int buscar_carta_en_mano(tJugador* jugador, tPoder PODER)
{
    int i;
    for(i=0;i < CANT_CARTAS;i++)
    {
        if (jugador->mano.mano[i].tipoPoder == PODER)
            return i;
    }
    return -1;
}
