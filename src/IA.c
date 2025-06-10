#include "../include/IA.h"


int obtener_pos_carta_IA_dificil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    int pos_espejo, pos_repetir, pos_restar, pos_sumar, pos_no_restar;
    pos_espejo = pos_repetir = pos_restar = pos_sumar = -1;

    printf("IA Seleccionando carta.....");
    Sleep(1000);

    if (ultima_carta != NULL && (pos_espejo = buscar_carta_en_mano(IA, ESPEJO)) != -1 &&
       (ultima_carta->tipoPoder == RESTAR_2 || ultima_carta->tipoPoder == RESTAR_1))
        return pos_espejo;

    pos_repetir = buscar_carta_en_mano(IA, REPETIR_TURNO);

    if(puntaje_jugador >= 8)
    {
        if(pos_repetir == -1)
        {
            pos_restar = buscar_carta_en_mano(IA, RESTAR_2);
            if(pos_restar != -1)
                return pos_restar;

            pos_restar = buscar_carta_en_mano(IA, RESTAR_1);
            if(pos_restar != -1)
                return pos_restar;
        }
        else
            return pos_repetir;
    }
    else
    {
        pos_sumar = buscar_carta_en_mano(IA, SUMAR_2);

        if(pos_sumar != -1)
            return (pos_repetir != -1) ? (pos_repetir) : (pos_sumar);
        else
        {
            pos_sumar = buscar_carta_en_mano(IA, SUMAR_1);
            if(pos_sumar != -1)
                return (pos_repetir != -1) ? (pos_repetir) : (pos_sumar);
        }

        if(puntaje_jugador >= 2)
        {
            pos_restar = buscar_carta_en_mano(IA, RESTAR_2);
            if(pos_restar != -1)
                return (pos_repetir != -1) ? (pos_repetir) : (pos_restar);
        }
        else if(puntaje_jugador >= 1)
        {
            pos_restar = buscar_carta_en_mano(IA, RESTAR_1);
            if(pos_restar != -1)
                return (pos_repetir != -1) ? (pos_repetir) : (pos_restar);
        }
        else
        {
            if((pos_no_restar = buscar_carta_no_negativa(IA)) != -1)
                return pos_no_restar;
        }
    }

    return rand() % 3;
}

int obtener_pos_carta_IA_normal(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    int pos_sumar, pos_restar, pos_no_restar;
    printf("IA Seleccionando carta.....");
    Sleep(1000);

    if (IA->puntajeAcumulado >= 8)
    {
        if ((pos_sumar = buscar_carta_en_mano(IA, SUMAR_2)) != -1)
            return pos_sumar;
        else if((pos_sumar = buscar_carta_en_mano(IA, SUMAR_1)) != -1)
            return pos_sumar;
    }

    if(puntaje_jugador != 0)
    {
        if((pos_restar = buscar_carta_en_mano(IA, RESTAR_2)) != -1 && puntaje_jugador >= 2)
            return pos_restar;
        else if((pos_restar = buscar_carta_en_mano(IA, RESTAR_1)) != -1 && puntaje_jugador >= 1)
            return pos_restar;
    }
    else
    {
        if((pos_no_restar = buscar_carta_no_negativa(IA)) != -1)
            return pos_no_restar;
    }

    return rand() % 3;
}

int obtener_pos_carta_IA_facil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    printf("IA Seleccionando carta.....");
    Sleep(1000);
    return rand() % 3;
}
