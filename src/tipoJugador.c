#include "../include/tipoJugador.h"

signed char buscar_carta_en_mano(const tJugador* jugador, tPoder PODER)
{
    signed char i = 0;

    while (i < CANT_CARTAS)
    {
        if (jugador->mano.mano[i].tipoPoder == PODER)
            return i;
    }

    return -1;
}
