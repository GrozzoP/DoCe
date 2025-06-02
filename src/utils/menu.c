#include "../../include/utils/menu.h"

int imprimir_errores(int val_error)
{
    switch(val_error)
    {
        case PERDIDA_DE_DATOS:
            printf("\nHubo perdida de datos al vaciar las listas/colas\n");
            break;
        case JUGADOR_NO_CARGADO:
            printf("\nAlgo salio mal al cargar los jugadores\n");
            break;
        case ERROR_ARCHIVO:
            printf("\nError al crear/cargar archivo\n");
            break;
        case ERROR_OBTENER_TIPOPODER_SEGUN_CARTA:
            printf("\nPoder de carta cargado Inexistente\n");
            break;
        case ERROR_SOBRECARGA_CARTAS:
            printf("\nCartas cargadas de mas de tipo poder especifico\n");
            break;
        case LISTA_LLENA:
            printf("\nLista Llena, no se pueden cargar mas datos\n");
            break;
    }
    return TODO_OK;
}

int menu()
{
    int opcion, res;
    habilitarANSI();
    vistas_bienvenida();
    char linea[20];

    printf("%40s|Menu de Opciones[1,2,3]|\n%40s%s\n1]%-40s2]%-40s3]%-20s\n",
           " "," ","+-----------------------+",MENSAJES[0],MENSAJES[1],MENSAJES[2]);
    do
    {
        printf("Seleccione Nro: ");
        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            opcion = 0;
            continue;
        }

        if (sscanf(linea, "%d", &opcion) != 1) {
            printf("Entrada invalida. Debe ingresar un numero.\n");
            opcion = 0;
            continue;
        }

        if (opcion < 1 || opcion > 3) {
            printf("Opcion fuera de rango. Elija 1, 2 o 3.\n");
        }
    } while (opcion < 1 || opcion > 3);

    switch(opcion)
    {
        case 1:
            system("CLS");
            if((res=juegoDOCE())!= TODO_OK)
                return res;
            break;
        case 2:
            system("CLS");
            ver_ranking(API_URL_CON_CODIGO);
            break;
        case 3:
            system("CLS");
            printf("Saliendo del Juego..");
            break;
    }
    return TODO_OK;
}

int menu_juego()
{
    return imprimir_errores(menu());
}
