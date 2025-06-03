#include "../include/IA.h"


int obtener_pos_carta_IA_dificil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    int pos_espejo, pos_repetir, pos_restar, pos_sumar;
    pos_espejo = pos_repetir = pos_restar = pos_sumar = -1;

    printf("IA Seleccionando carta.....");
    Sleep(1000);

    // Regla 2: Usa carta espejo en caso de recibir una carta negativa del oponente
    if (ultima_carta != NULL && (pos_espejo = buscar_carta_en_mano(IA, ESPEJO)) != -1 &&
       (ultima_carta->tipoPoder == RESTAR_2 || ultima_carta->tipoPoder == RESTAR_1))
        return pos_espejo;

    // Regla 1: Si el jugador está cerca de ganar, prioriza cartas de “repetir turno” o “sacar puntos”.
    pos_repetir = buscar_carta_en_mano(IA, REPETIR_TURNO);

    if(puntaje_jugador >= 8)
    {
        // Si no tengo para repetir, voy a buscar restarle puntos
        if(pos_repetir == -1)
        {
            // BUSCO RESTAR_2
            pos_restar = buscar_carta_en_mano(IA, RESTAR_2);
            if(pos_restar != -1)
                return pos_restar;

            // BUSCO RESTAR_1
            pos_restar = buscar_carta_en_mano(IA, RESTAR_1);
            if(pos_restar != -1)
                return pos_restar;
        }
        // Si no hay cartas de restar, usar repetir turno para retrasar la posible victoria del jugador
        else
            return pos_repetir;
    }

    // Regla 3: Prefiere repetir turno solo si tiene más de una carta buena en mano
    // Si el contrincante no esta cerca de ganar, entonces la IA prioriza sumar puntos, de lo contrario, resta
    if(puntaje_jugador < 8)
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

    }
    else
    {
        // La primera condicion me asegura que en el primer IF de la funcion, si se calculo el espejo
        if(ultima_carta != NULL && ((ultima_carta->tipoPoder == RESTAR_2) ||
           (ultima_carta->tipoPoder == RESTAR_1)))
            return pos_espejo;

        else if(pos_repetir != -1)
            return pos_repetir;
    }

    return rand() % 3;
}

int obtener_pos_carta_IA_normal(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    int pos1, cant = 0;
    printf("IA Seleccionando carta.....");
    Sleep(1000);

    if (IA->puntajeAcumulado >= 8)
    {
        if ((pos1 = buscar_carta_en_mano(IA, SUMAR_2)) != -1)
            return pos1;
        else if((pos1 = buscar_carta_en_mano(IA, SUMAR_1)) != -1)
            return pos1;
    }

    while (pos1 == -1 && cant != 9)
    {
        pos1 = rand() % 3;

        if (IA->mano.mano[pos1].tipoPoder == RESTAR_1 || IA->mano.mano[pos1].tipoPoder == RESTAR_2)
        {
            if (puntaje_jugador == 0)
                pos1 = -1;
            else
                return pos1;
        }
        cant++;
    }

    return pos1 = rand() % 3;
}

int obtener_pos_carta_IA_facil(tJugador* IA, tCarta* ultima_carta, int puntaje_jugador)
{
    printf("IA Seleccionando carta.....");
    Sleep(1000);
    return rand() % 3;
}
