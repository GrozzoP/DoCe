#include "../include/jugador.h"
#define TAM_NOM 25

void _cargarJugador(tJugador * py)
{
    char* nomb = (char*)malloc(sizeof(char) * TAM_NOM);
    do{
        system("CLS");
        printf("Ingrese Nombre: ");
        fflush(stdin);
        fgets(nomb, TAM_NOM -1, stdin);
    }while(strcmp(nomb,"IA_FACIL\n") == 0 || strcmp(nomb,"IA_NORMAL\n") == 0 || strcmp(nomb,"IA_DIFICIL\n") == 0);

    nomb[strcspn(nomb, "\n")] = '\0';
    strcpy(py->nombre,nomb);
    py->puntajeAcumulado = 0;//pone por defecto 0 los puntos al jugador
    free(nomb);
}

void _cargarIA(tJugador * py)
{
    int d = 0;
    char linea[20];
    printf("DIFICULTAD A ELEGIR:\n 1) FACIL\n 2) NORMAL\n 3) DIFICIL\n");

    do
    {
        printf("Seleccione Nro: ");
        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            d = 0;
            continue;
        }

        if (sscanf(linea, "%d", &d) != 1) {
            printf("Entrada invalida. Debe ingresar un numero.\n");
            d = 0;
            continue;
        }

        if (d < 1 || d > 3) {
            printf("Opcion fuera de rango. Elija 1, 2 o 3.\n");
        }
    } while (d < 1 || d > 3);

    system("CLS");

    py->puntajeAcumulado=0;
    switch(d)
    {
        case 1:
            strcpy(py->nombre,TO_STRING(IA_FACIL));
            break;
        case 2:
            strcpy(py->nombre,TO_STRING(IA_NORMAL));
            break;
        case 3:
            strcpy(py->nombre,TO_STRING(IA_DIFICIL));
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

    return JUGADOR_NO_CARGADO;
}

int obtener_pos_carta_jugador()
{
    int pos;

    do{
        printf("\nSeleccione Carta: ");
        scanf("%d", &pos);
        pos--;
    } while(pos>2 || pos<0);

    return pos;
}
