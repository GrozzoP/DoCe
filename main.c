#include "include/utils/menu.h"
int imprimir_errores(int val_error)
{
    switch(val_error)
    {
        case -11:
            printf("\nHubo perdida de datos al vaciar las listas/colas\n");
            break;
        case -12:
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
            printf("\nLista Llena,no se pueden cargar mas datos\n");
            break;
    }
    return TODO_OK;
}


int main() {
    return imprimir_errores(menu());
}
