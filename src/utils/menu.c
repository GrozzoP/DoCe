#include "../../include/utils/menu.h"

int menu()
{
    int opcion,res;
    habilitarANSI();
    vistas_bienvenida();
    printf("%40s|Menu de Opciones[1,2,3]|\n%40s%s\n1]%-40s2]%-40s3]%-20s\n",
           " "," ","+-----------------------+",MENSAJES[0],MENSAJES[1],MENSAJES[2]);
    do
    {
        printf("\nSeleccione opcion:");
        scanf("%d",&opcion);
        opcion--;
    }while(2< opcion || opcion <0);

    switch(opcion)
    {
        case 0:
            system("CLS");
            if((res=juegoDOCE())!= TODO_OK)
                return res;
            break;
        case 1:
            system("CLS");
            ver_ranking(API_URL_CON_CODIGO);
            break;
        case 2:
            system("CLS");
            printf("Saliendo del Juego..");
            break;
    }
    return TODO_OK;
}
