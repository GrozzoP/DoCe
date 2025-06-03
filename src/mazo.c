#include "../include/mazo.h"

int cargar_carta_lista_random(tLista* pL, const char* nombArch)
{
    tCarta aux;
    char carta[14];
    unsigned cantCartas=0;
    FILE* pf = fopen(nombArch, "rt");

    if(!pf)
        crear_archivo_cartas(nombArch);

    while(fscanf(pf, "%13s", carta) == 1)
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
        poner_en_lista_pos(pL, &aux, sizeof(tCarta), rand() % cantCartas);
    }

    fclose(pf);
    return TODO_OK;
}

int crear_archivo_cartas(const char* nombreArch)
{
    size_t num_cartas;
    FILE* pF = fopen(nombreArch, "wt");

    if (pF == NULL)
        return ERROR_ARCHIVO;

    const char* cartas[] = {
        "Sumar_2",
        "Sumar_1",
        "Restar_1",
        "REPETIR_TURNO",
        "Restar_2",
        "Sumar_1",
        "Espejo",
        "Sumar_1",
        "Restar_2",
        "Sumar_2",
        "REPETIR_TURNO",
        "Sumar_1",
        "Restar_1",
        "Sumar_1",
        "Espejo",
        "Restar_2",
        "Sumar_2",
        "REPETIR_TURNO",
        "Sumar_1",
        "Restar_1",
        "Restar_2",
        "Sumar_1",
        "Restar_1",
        "REPETIR_TURNO",
        "Sumar_2",
        "Restar_1",
        "Sumar_1",
        "Espejo",
        "REPETIR_TURNO",
        "Restar_1",
        "Restar_2",
        "Sumar_2",
        "Espejo",
        "Restar_1",
        "Sumar_1",
        "Restar_2",
        "Sumar_1",
        "REPETIR_TURNO",
        "Sumar_2",
        "Restar_1"
    };

    num_cartas = sizeof(cartas) / sizeof(cartas[0]);

    for (size_t i = 0; i < num_cartas; ++i)
    {
        if (fprintf(pF, "%s\n", cartas[i]) < 0)
        {
            fclose(pF);
            return ERROR_ARCHIVO;
        }
    }

    fclose(pF);
    return TODO_OK;
}

int pedir_carta_mazo(tLista* mazoA, tJugador* jugador, int pos)
{
    if(lista_vacia(mazoA) != LISTA_VACIA)
        sacar_primero_lista(mazoA,&jugador->mano.mano[pos],sizeof(tCarta));
    else
        return LISTA_VACIA;
return TODO_OK;
}

void remezclar_mazo(const tCarta* val, tLista* pL, unsigned cantCartas)
{
        poner_en_lista_pos(pL,val,sizeof(tCarta),rand()%cantCartas);
}

void descartar_carta_mano(tLista* mazoB, tJugador* jugador, int pos, int cantCartas)
{
    remezclar_mazo(&jugador->mano.mano[pos],mazoB,cantCartas);
}

void cargar_mano(tJugador* py, tLista* lista)
{
    int i;
    for(i=0;i<3;i++)
        sacar_primero_lista(lista, &py->mano.mano[i], sizeof(tCarta));
}

void descartar_mano(tJugador* py, tLista* lista)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(strcmp(obtener_stringPoder(&py->mano.mano[i])," ")!=0)
        {
            poner_al_comienzo_lista(lista,&py->mano.mano[i],sizeof(tCarta));
//            printf("%d]%s\n",i+1,obtener_stringPoder(&py->mano.mano[i]));
        }
    }
}






