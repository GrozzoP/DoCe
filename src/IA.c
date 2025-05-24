#include "../include/IA.h"


int obtener_pos_carta_IAdificil(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador)
{
    int pos_espejo,pos1,pos2;
    printf("IA Seleccionando carta.....");
    Sleep(1000);
            if (ultima_carta != NULL && (pos_espejo = buscar_carta_en_mano(ia, ESPEJO)) != -1 && (ultima_carta->tipoPoder == RESTAR_2 || ultima_carta->tipoPoder == RESTAR_1)) /// busca una carta espejo en su mano
            {/// mira si la ultima carta que tiro el jugador es de restar puntos
                    /// si tiene una carta espejo, la tira
                    return pos_espejo;
            }
            else
            {
                pos1 = buscar_carta_en_mano(ia, REPETIR_TURNO);    /// busca carta de repetir turno en su mano
                if (puntaje_jugador >= 8)   /// si el jugador esta por ganar:
                {
                    if ((pos2 = buscar_carta_en_mano(ia,RESTAR_2)) != -1)  /// busca carta de restar 2 puntos
                    {
                        if (pos1 == -1)
                            pos1 = pos2;    /// si encontro carta restar 2, y no tiene repetir, guarda la carta restar 2
                    }
                    else
                        if ((pos2 = buscar_carta_en_mano(ia,RESTAR_1)) != -1)  /// si no tiene, busca carta de restar 1 punto
                        {
                            if (pos1 == -1)
                                pos1 = pos2;    /// si encontro carta restar 1, y no tiene repetir, guarda la carta restar 2
                        }

                    if (pos1 != -1)
                    {
                        /// tira carta de repetir, o de restar puntos, si es que tiene
                        return pos1;
                    }
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
                    {
                        /// si tengo carta de repetir y de sumar, tiro la de repetir. si tengo de sumar, tiro la de sumar
                        return pos1;
                    }
                }
                else
                    if (pos1 != -1)
                    {
                        if (puntaje_jugador >= 2)
                        {
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
                        }
                        if (pos1 != -1 && pos2 != -1)
                        {
                            /// si tiene carta repetir, y alguna de resta, tira la de repetir. si tiene solo de resta, tira la de resta
                            return pos1;
                        }
                    }

                if (pos1 == -1 && pos_espejo != -1)
                {
                    /// si no tiene cartas de sumar, de restar ni de repetir, se fija si tiene de espejo (la consigna habla de SOLO usar la carta de repetir cuando hay mas de una buena en el mazo)
                    return pos_espejo;
                }
                else
                    if (pos1 == -1)
                    {
                        /// se supone que en este caso, la mano de la ia tiene todas cartas de repetir, entonces tira la primera
                        return 0;
                    }
            }
            pos1=rand()%3;
            return pos1;
}
int obtener_pos_carta_IAnormal(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador)
{
    int pos1,cantBucle=0;
    printf("IA Seleccionando carta.....");
    Sleep(1000);
    if (ia->puntajeAcumulado >= 8)  /// si la ia esta por ganar: busca cartas de sumar puntos
            {
                if ((pos1 = buscar_carta_en_mano(ia, SUMAR_2)) != -1)
                    return pos1;
                else
                    if ((pos1 = buscar_carta_en_mano(ia, SUMAR_1)) != -1)
                        return pos1;
            }
            while (pos1 == -1 && cantBucle!=9)   /// si la ia no tiro carta, busca una aleatoriamente, y luego la compara con las cartas de restar, y se fija si el puntaje del jugador no es 0. si es 0, y la carta que selecciono es restar, no la tira y busca otra
            {
                pos1 = rand() %3;
                if (ia->mano.mano[pos1].tipoPoder == RESTAR_1 || ia->mano.mano[pos1].tipoPoder == RESTAR_2)
                {
                    if (puntaje_jugador == 0)
                        pos1 = -1;
                    else
                        return pos1;
                }
                cantBucle++;
            }
   return pos1 = rand() %3;
}
int obtener_pos_carta_IAfacil(tJugador * ia,tCarta * ultima_carta,int puntaje_jugador)
{
    printf("IA Seleccionando carta.....");
    Sleep(1000);
    return rand()%3;
}
