#include "../include/IA.h"
#include <stdlib.h>
#include <time.h>

void juega_IA(tMazo* mazo, const tJugador* ia, const tCarta* ult_carta, int puntaje_jugador)
{
    signed char pos1, pos2, pos_espejo;
    static char band = 0;

    if (!band)
    {
        srand(time(NULL));  /// hace el srand la primera vez que entra en la funcion
        band = 1;
    }

    switch(ia->*(nombre+3)) /// hacemos un switch para separar el comportamiento de la ia segun la dificultad. la dificultad la sacamos del 4to caracter del nombre de la ia (F, M, D): IA_FACIL, IA_MEDIO o IA_DIFICIL
    {
        case 'D':
            if ((pos_espejo = buscar_carta_en_mano(ia, ESPEJO)) != -1) /// busca una carta espejo en su mano
                if (ult_carta->tipoPoder == RESTAR_2 || ult_carta->tipoPoder == RESTAR_1)   /// mira si la ultima carta que tiro el jugador es de restar puntos
                    ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder; /// si tiene una carta espejo, la tira
            else
            {
                pos1 = buscar_carta_en_mano(ia, REPETIR_TURNO);    /// busca carta de repetir turno en su mano

                if (puntaje_jugador >= 8)   /// si el jugador esta por ganar:
                {
                    if ((pos2 = buscar_carta_en_mano(RESTAR_2)) != -1)  /// busca carta de restar 2 puntos
                    {
                        if (pos1 == -1)
                            pos1 = pos2;    /// si encontro carta restar 2, y no tiene repetir, guarda la carta restar 2
                    }
                    else
                        if ((pos2 = buscar_carta_en_mano(RESTAR_1) != -1)  /// si no tiene, busca carta de restar 1 punto
                        {
                            if (pos1 == -1)
                                pos1 = pos2;    /// si encontro carta restar 1, y no tiene repetir, guarda la carta restar 2
                        }

                    if (pos1 != -1)
                        ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder; /// tira carta de repetir, o de restar puntos, si es que tiene
                }

                if (pos1 == -1 || puntaje_jugador < 8)  /// si el jugador no esta por ganar, y tengo carta de repetir, o no tengo carta de repetir
                {
                    if ((pos2 = buscar_carta_en_mano(ia, SUMAR_2)) != 1)   /// busca en su mano cartas de sumar 2 puntos
                    {
                        if (pos1 == -1)
                            pos1 = pos2;
                    }
                    else
                        if ((pos2 = buscar_carta_en_mano(ia, SUMAR_1)) != -1)   /// sino, busca en su mano cartas de sumar 1 punto
                        {
                            if (pos1 == -1)
                                pos1 = pos2;
                        }

                    if (pos1 != -1 && pos2 != -1)
                        ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;   /// si tengo carta de repetir y de sumar, tiro la de repetir. si tengo de sumar, tiro la de sumar
                }
                else
                    if (pos1 != -1)
                    {
                        if (puntaje_jugador >= 2)
                            if ((pos2 = buscar_carta_en_mano(ia, RESTAR_2)) != -1)  /// si el jugador no está por ganar, y no tengo cartas de sumar, busco de restar 2 (si el jugador tiene 2 puntos o mas)
                            {
                                if (pos1 == -1)
                                    pos1 = pos2;
                            }
                            else
                                if (puntaje_jugador >= 1 && (pos2 = buscar_carta_en_mano(ia, RESTAR_1)) != -1)  /// si el jugador tiene 1 punto o mas, busco carta de restar punto
                                {
                                    if (pos1 == -1)
                                        pos1 = pos2;
                                }

                        if (pos1 != -1 && pos2 != -1)
                            ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;   /// si tiene carta repetir, y alguna de resta, tira la de repetir. si tiene solo de resta, tira la de resta
                    }

                if (pos1 == -1 && pos_espejo != -1)
                    ult_carta->tipoPoder = ia->mano.mano[pos_espejo].tipoPoder; /// si no tiene cartas de sumar, de restar ni de repetir, se fija si tiene de espejo (la consigna habla de SOLO usar la carta de repetir cuando hay mas de una buena en el mazo)
                else
                    if (pos == -1)
                        ult_carta->tipoPoder = ia->mano.mano[0].tipoPoder:  /// se supone que en este caso, la mano de la ia tiene todas cartas de repetir, entonces tira la primera
            }
    }
    break;
        case 'M':
            if (ia->puntajeAcumulado >= 8)  /// si la ia esta por ganar: busca cartas de sumar puntos
            {
                if ((pos1 = buscar_carta_en_mano(ia, SUMAR_2)) != -1)
                    ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;
                else
                    if ((pos1 = buscar_carta_en_mano(ia, SUMAR_1)) != -1)
                        ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;
            }

            while (pos == -1)   /// si la ia no tiro carta, busca una aleatoriamente, y luego la compara con las cartas de restar, y se fija si el puntaje del jugador no es 0. si es 0, y la carta que selecciono es restar, no la tira y busca otra
            {
                pos1 = rand() %3;
                if (ia->mano.mano[pos1].tipoPoder == RESTAR_1 || ia->mano.mano[pos1].tipoPoder == RESTAR_2)
                {
                    if (puntaje_jugador == 0)
                        pos1 = -1;
                    else
                        ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;
                }
            }
    break;
        case 'F':
            pos1 = rand() %3;
            ult_carta->tipoPoder = ia->mano.mano[pos1].tipoPoder;   /// tira una carta aleatoria

    /// la ia tiene que agarrar una carta del mazo, y la guarda en su mano, en el subindice "pos1"

}
