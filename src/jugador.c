#include "../include/jugador.h"
#define TAM_NOM 25

void _cargarJugador(tJugador * py)
{
    char* nomb = (char*)malloc(sizeof(char) * TAM_NOM);
    system("CLS");
    do{
        printf("Ingrese Nombre: ");
        fflush(stdin);
        fgets(nomb, TAM_NOM -1, stdin);

        if (strcmpi(nomb,"IA_FACIL\n") == 0 || strcmpi(nomb,"IA_NORMAL\n") == 0 || strcmpi(nomb,"IA_DIFICIL\n") == 0)
            puts("No puede ponerse el nombre de la IA. Por favor reingrese.");
        else if (strcmpi(nomb,"\n") == 0)
            puts("No puede dejar su nombre en blanco. Por favor reingrese.");
        else if (strlen(nomb) <= 3)
            puts("Tu nombre es demasiado corto, deberia ser mayor a 3 caracteres. Por favor reingrese.");
        else
            break;
    }while(1);

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
        printf("Seleccione Carta: ");
        scanf("%d", &pos);
        pos--;
    } while(pos>2 || pos<0);

    return pos;
}
