#include "../include/carta.h"

int obtener_tipoPoder_segun_carta(const char * nomb)
{
    if(strcmpi(nomb,STRING_PODER[SUMAR_2])==0)
    {
        if(CANT_PODER_CARTA[SUMAR_2]>0)
        {
            CANT_PODER_CARTA[SUMAR_2]--;
            return SUMAR_2;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    if(strcmpi(nomb,STRING_PODER[SUMAR_1])==0)
    {
        if(CANT_PODER_CARTA[SUMAR_1]>0)
        {
            CANT_PODER_CARTA[SUMAR_1]--;
            return SUMAR_1;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    if(strcmpi(nomb,STRING_PODER[RESTAR_1])==0)
    {
        if(CANT_PODER_CARTA[RESTAR_1]>0)
        {
            CANT_PODER_CARTA[RESTAR_1]--;
            return RESTAR_1;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    if(strcmpi(nomb,STRING_PODER[RESTAR_2])==0)
    {
        if(CANT_PODER_CARTA[RESTAR_2]>0)
        {
            CANT_PODER_CARTA[RESTAR_2]--;
            return RESTAR_2;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    if(strcmpi(nomb,STRING_PODER[ESPEJO])==0)
    {
        if(CANT_PODER_CARTA[ESPEJO]>0)
        {
            CANT_PODER_CARTA[ESPEJO]--;
            return ESPEJO;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    if(strcmpi(nomb,STRING_PODER[REPETIR_TURNO])==0)
    {
        if(CANT_PODER_CARTA[REPETIR_TURNO]>0)
        {
            CANT_PODER_CARTA[REPETIR_TURNO]--;
            return REPETIR_TURNO;
        }
        else
            return ERROR_SOBRECARGA_CARTAS;
    }
    return ERROR_OBTENER_TIPOPODER_SEGUN_CARTA;
}
char * obtener_stringPoder(tCarta * carta)
{
    if(carta != NULL)
    {
        return (char*)STRING_PODER[carta->tipoPoder];
       /* switch(carta->tipoPoder)
        {
            case RESTAR_2:
                return "RESTAR_2\0";
                break;
            case RESTAR_1:
                return "RESTAR_1\0";
                break;
            case SUMAR_1:
                return "SUMAR_1\0";
                break;
            case SUMAR_2:
                return "SUMAR_2\0";
                break;
            case ESPEJO:
                return "ESPEJO\0";
                break;
            case REPETIR_TURNO:
                return "REPETIR_TURNO\0";
                break;
        }*/
    }
     return " ";
}
