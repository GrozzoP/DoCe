#include "../include/mazo.h"

int cargar_carta_lista_random(tLista* pL, const char* nombArch)
{
    tCarta aux;
    char carta[14];
    unsigned cantCartas=0;
    FILE* pf = fopen(nombArch,"rt");

    if(pf == NULL)
        return ERROR_ARCHIVO;

    while(fscanf(pf,"%13s",carta)==1)
    {
        cantCartas++;
        aux.tipoPoder=obtener_tipoPoder_segun_carta(carta);
        if(aux.tipoPoder == ERROR_OBTENER_TIPOPODER_SEGUN_CARTA)
        {
            fclose(pf);
            return ERROR_OBTENER_TIPOPODER_SEGUN_CARTA;
        }
        if(aux.tipoPoder == ERROR_SOBRECARGA_CARTAS)
        {
            fclose(pf);
            return ERROR_SOBRECARGA_CARTAS;
        }
        if(poner_en_lista_pos(pL,&aux,sizeof(tCarta),rand()%cantCartas) == LISTA_LLENA)
            return LISTA_LLENA;
    }

    fclose(pf);
    return TODO_OK;
}

int pedir_carta_maso(tLista * masoA,tJugador * jugador,int pos)
{
    if(lista_vacia(masoA) != LISTA_VACIA)
        sacar_primero_lista(masoA,&jugador->mano.mano[pos],sizeof(tCarta));
    else
        return LISTA_VACIA;
return TODO_OK;
}

void _remezclar_mazo(const tCarta * val,tLista *pL,unsigned cantCartas)
{
        poner_en_lista_pos(pL,val,sizeof(tCarta),rand()%cantCartas);
}

void descartar_carta_mano(tLista * masoB,tJugador * jugador,int pos,int cantCartas)
{
    _remezclar_mazo(&jugador->mano.mano[pos],masoB,cantCartas);
}

void cargar_mano(tJugador * py,tLista * lista)
{
    int i;
    for(i=0;i<3;i++)
        sacar_primero_lista(lista,&py->mano.mano[i],sizeof(tCarta));
}

void descartar_mano(tJugador * py,tLista * lista)
{
    int i;
//    printf("\nJugador:[%s]\nCartasSobreantes:\n",py->nombre);
//    printf("----------------\n");
    for(i=0;i<3;i++)
    {
        if(strcmp(obtener_stringPoder(&py->mano.mano[i])," ")!=0)
        {
            poner_al_comienzo_lista(lista,&py->mano.mano[i],sizeof(tCarta));
//            printf("%d]%s\n",i+1,obtener_stringPoder(&py->mano.mano[i]));
        }
    }
}






