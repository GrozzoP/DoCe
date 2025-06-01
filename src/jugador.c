#include "../include/jugador.h"
#define TAM_NOM 25
void _cargarJugador(tJugador * py)
{
    char *nomb=(char*)malloc(sizeof(char)*TAM_NOM);
    do{
        printf("Ingrese Nombre: ");
    }while(!scanf("%s",nomb));

    nomb[strcspn(nomb, "\n")] = '\0';
    strcpy(py->nombre,nomb);
    py->puntajeAcumulado=0;//pone por defecto 0 los puntos al jugador
    free(nomb);
}

void _cargarIA(tJugador * py)
{
    int d=0;
    printf("DIFICULTAD A ELEJIR:\n 1)FACIL\n 2)NORMAL\n 3)DIFICIL\n Seleccione Nro:");
    scanf("%d",&d);
    system("CLS");
    switch(d)
    {
        case 1:
            strcpy(py->nombre,TO_STRING(IA_FACIL));
            py->puntajeAcumulado=0;
            break;
        case 2:
            strcpy(py->nombre,TO_STRING(IA_NORMAL));
            py->puntajeAcumulado=0;
            break;
        case 3:
            strcpy(py->nombre,TO_STRING(IA_DIFICIL));
            py->puntajeAcumulado=0;
            break;
    }
}

int cargar_jugador(tJugador* jugA, tJugador* jugB)
{
    srand(time(NULL));

    int res=rand()%2;

    if(res==0)
    {
        _cargarJugador(jugB);

        _cargarIA(jugA);

        return res;
    }
    else
    {
        _cargarJugador(jugA);

        _cargarIA(jugB);

        return res;
    }
    return -1;
}
int obtener_pos_carta_jugador()
{
  /*  int pos;
    do{
        printf("\nSeleccione Carta:");
        scanf("%d",&pos);
        pos--;
    }while(pos>2 || pos<0)
    return pos;*/
    return rand()%3;

}
