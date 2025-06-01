#include "../../include/mazo.h"

void habilitarANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo = 0;
    GetConsoleMode(hOut, &modo);
    SetConsoleMode(hOut, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
void vistas_bienvenida()
{
    printf("+-------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                       \033[0;31m%-29s\033[0m                                   |\n",TITULO);
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    printf("+-------------------------------------------------------------------------------------------------------+\n");
}

void _vistas_repartiendo(int vueltas)
{
    if(vueltas ==0)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REPARTIENDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                   +-------------+                                                     |\n");
        printf("|                                   |             |+                                                    |\n");
        printf("|                                   |             ||+                                                   |\n");
        printf("|                                   |             |||+                                                  |\n");
        printf("|                                   +-------------+|||+                                                 |\n");
        printf("|                                    +-------------+|||+                                                |\n");
        printf("|                                     +-------------+|||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas ==1)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REPARTIENDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                 +-------------+     +-------------+                                                   |\n");
        printf("|                 |             |     |             |                                                   |\n");
        printf("|                 |             |     |             |                                                   |\n");
        printf("|                 |             |     |             |                                                   |\n");
        printf("|                 +-------------+     +-------------+                                                   |\n");
        printf("|                                                                                                       |\n");
        printf("|                                    +-------------+                                                    |\n");
        printf("|                                    |             |+                                                   |\n");
        printf("|                                    |             ||+                                                  |\n");
        printf("|                                    |             |||+                                                 |\n");
        printf("|                                    +-------------+|||+                                                |\n");
        printf("|                                     +-------------+|||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas ==2)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REPARTIENDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                 +-------------+     +-------------+     +-------------+                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 +-------------+     +-------------+     +-------------+                               |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                     +-------------+                                                   |\n");
        printf("|                                     |             |+                                                  |\n");
        printf("|                                     |             ||+                                                 |\n");
        printf("|                                     |             |||+                                                |\n");
        printf("|                                     +-------------+|||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                     +-------------+     +-------------+                               |\n");
        printf("|                                     |             |     |             |                               |\n");
        printf("|                                     |             |     |             |                               |\n");
        printf("|                                     |             |     |             |                               |\n");
        printf("|                                     +-------------+     +-------------+                               |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas ==3)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REPARTIENDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                 +-------------+     +-------------+     +-------------+                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 |             |     |             |     |             |                               |\n");
        printf("|                 +-------------+     +-------------+     +-------------+                               |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                     +-------------+                                                   |\n");
        printf("|                                     |             |+                                                  |\n");
        printf("|                                     |             ||+                                                 |\n");
        printf("|                                     |             |||+                                                |\n");
        printf("|                                     +-------------+|||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                     +-------------+     +-------------+      +-------------+          |\n");
        printf("|                                     |             |     |             |      |             |          |\n");
        printf("|                                     |             |     |             |      |             |          |\n");
        printf("|                                     |             |     |             |      |             |          |\n");
        printf("|                                     +-------------+     +-------------+      +-------------+          |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
}
void vistas_repartiendo()
{
    for(int i=0;i<4;i++)
    {
        system("CLS");
        _vistas_repartiendo(i);
        Sleep(1000);
    }
    system("CLS");
}
void _vistas_remezclando(int vueltas)
{
    if(vueltas == 0)
    {

        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REMEZCLANDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                +-------+ +-------+ +-------+ +-------+ +-------+ +-------+ +-------+                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                +-------+ +-------+ +-------+ +-------+ +-------+ +-------+ +-------+                  |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                +-------+ +-------+ +-------+ +-------+ +-------+ +-------+ +-------+                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                |       | |       | |       | |       | |       | |       | |       |                  |\n");
        printf("|                +-------+ +-------+ +-------+ +-------+ +-------+ +-------+ +-------+                  |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas == 1)
    {

        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REMEZCLANDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                          +-------+ +-------+           +-------+           +-------+                  |\n");
        printf("|                          |       | |       |           |       |           |       |                  |\n");
        printf("|                          |       | |       |           |       |           |       |                  |\n");
        printf("|                          |       | |       |           |       |           |       |                  |\n");
        printf("|                          |       | |       |           |       |           |       |                  |\n");
        printf("|                          +-------+ +-------+           +-------+           +-------+                  |\n");
        printf("|                                                                                                       |\n");
        printf("|                                       +-------------+                                                 |\n");
        printf("|                                       |             |+                                                |\n");
        printf("|                                       |             ||                                                |\n");
        printf("|                                       |             ||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                +-------+                     +-------+                     +-------+                  |\n");
        printf("|                |       |                     |       |                     |       |                  |\n");
        printf("|                |       |                     |       |                     |       |                  |\n");
        printf("|                |       |                     |       |                     |       |                  |\n");
        printf("|                |       |                     |       |                     |       |                  |\n");
        printf("|                +-------+                     +-------+                     +-------+                  |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas == 2)
    {

        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REMEZCLANDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                    +-------+           +-------+                                      |\n");
        printf("|                                    |       |           |       |                                      |\n");
        printf("|                                    |       |           |       |                                      |\n");
        printf("|                                    |       |           |       |                                      |\n");
        printf("|                                    |       |           |       |                                      |\n");
        printf("|                                    +-------+           +-------+                                      |\n");
        printf("|                                      +-------------+                                                  |\n");
        printf("|                                      |             |+                                                 |\n");
        printf("|                                      |             ||+                                                |\n");
        printf("|                                      |             |||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                +-------+                                                   +-------+                  |\n");
        printf("|                |       |                                                   |       |                  |\n");
        printf("|                |       |                                                   |       |                  |\n");
        printf("|                |       |                                                   |       |                  |\n");
        printf("|                |       |                                                   |       |                  |\n");
        printf("|                +-------+                                                   +-------+                  |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    if(vueltas ==3)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        REMEZCLANDO MAZO...                                            |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                    +-------------+                                                    |\n");
        printf("|                                    |             |+                                                   |\n");
        printf("|                                    |             ||+                                                  |\n");
        printf("|                                    |             |||+                                                 |\n");
        printf("|                                    +-------------+|||+                                                |\n");
        printf("|                                     +-------------+|||                                                |\n");
        printf("|                                      +-------------+||                                                |\n");
        printf("|                                       +-------------+|                                                |\n");
        printf("|                                        +-------------+                                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
}
void vistas_remezclando()
{
    for(int i=0;i<4;i++)
    {
        system("CLS");
        _vistas_remezclando(i);
        Sleep(1000);
    }
    system("CLS");
}
void vistas_juego(tJugador* a, tJugador* b, tCarta* ca, tCarta* cb ,unsigned Cant)
{
//    static int primera_vez=1;
    system("CLS");
    printf("\nDEBUG CARTAS IA");
    if(strncmp("IA_",a->nombre,3)==0)
    {
        printf("\nPRIMER CARTA: %s", obtener_stringPoder(&a->mano.mano[0]));
        printf("\nSEGUNDA CARTA: %s", obtener_stringPoder(&a->mano.mano[1]));
        printf("\nTERCER CARTA: %s\n", obtener_stringPoder(&a->mano.mano[2]));
    }else
    {
        printf("\nPRIMER CARTA: %s", obtener_stringPoder(&b->mano.mano[0]));
        printf("\nSEGUNDA CARTA: %s", obtener_stringPoder(&b->mano.mano[1]));
        printf("\nTERCER CARTA: %s\n", obtener_stringPoder(&b->mano.mano[2]));
    }

    if(Cant<36)
    {
        printf("+-------------------------------------------------------------------------------------------------------+\n");
        printf("| +--------++--------++--------+    +----------------------------------+                                |\n");
        printf("| |        ||        ||        |    |                                  |                                |\n");
        if(strncmp("IA_",a->nombre,3)==0)
        {
            printf("| |        ||        ||        |    | Nombre:%-25s |                                |\n",a->nombre);
            printf("| |        ||        ||        |    | Pts:%2d                           |                                |\n",a->puntajeAcumulado);
        }
        else
        {
            printf("| |        ||        ||        |    | Nombre:%-25s |                                |\n",b->nombre);
            printf("| |        ||        ||        |    | Pts:%2d                           |                                |\n",b->puntajeAcumulado);
        }
        printf("| |        ||        ||        |    |                                  |                                |\n");
        printf("| |        ||        ||        |    |                                  |                                |\n");
        printf("| +--------++--------++--------+    +----------------------------------+                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                   +-------------+                                                     |\n");
       if(Cant<2)
       {
            printf("|                                   |             |                              +--------+             |\n");
            if(strncmp("IA_",a->nombre,3)==0)
                printf("|                                   |%-13s|                              |        |+            |\n",obtener_stringPoder(ca));
            else
                printf("|                                   |%-13s|                              |        |+            |\n",obtener_stringPoder(cb));
            printf("|                                   |             |                              |        ||+           |\n");
            printf("|                                   |             |                              |   A    |||+          |\n");
            printf("|                                   |             |      +-------------+         |        ||||          |\n");
            printf("|                                   |             |      |             |         |        ||||          |\n");
            if(strncmp("IA_",a->nombre,3)==0)
                printf("|                                   |             |      |%-13s|         |        ||||          |\n",obtener_stringPoder(cb));
            else
                printf("|                                   |             |      |%-13s|         |        ||||          |\n",obtener_stringPoder(ca));
            printf("|                                   +-------------+      |             |         +--------+|||          |\n");
            printf("|                                                        |             |          +--------+||          |\n");
            printf("|                                                        |             |           +--------+|          |\n");
            printf("|                                                        |             |            +--------+          |\n");
       }
       else{
           if(Cant<16)
           {
                printf("|        +--------+                 |             |                              +--------+             |\n");
                if(strncmp("IA_",a->nombre,3)==0)
                    printf("|        |        |                 |%-13s|                              |        |+            |\n",obtener_stringPoder(ca));
                else
                    printf("|        |        |                 |%-13s|                              |        |+            |\n",obtener_stringPoder(cb));
                printf("|        |        |                 |             |                              |        ||+           |\n");
                printf("|        |   B    |                 |             |                              |   A    |||+          |\n");
                printf("|        |        |                 |             |      +-------------+         |        ||||          |\n");
                printf("|        |        |                 |             |      |             |         |        ||||          |\n");
                if(strncmp("IA_",a->nombre,3)==0)
                    printf("|        |        |                 |             |      |%-13s|         |        ||||          |\n",obtener_stringPoder(cb));
                else
                    printf("|        |        |                 |             |      |%-13s|         |        ||||          |\n",obtener_stringPoder(ca));
                printf("|        +--------+                 +-------------+      |             |         +--------+|||          |\n");
                printf("|                                                        |             |          +--------+||          |\n");
                printf("|                                                        |             |           +--------+|          |\n");
                printf("|                                                        |             |            +--------+          |\n");
           }else
           {
                   if(Cant<34)
                   {
                       printf("|        +--------+                 |             |                              +--------+             |\n");
                        if(strncmp("IA_",a->nombre,3)==0)
                            printf("|        |        |+                |%-13s|                              |        |+            |\n",obtener_stringPoder(ca));
                        else
                            printf("|        |        |+                |%-13s|                              |        |+            |\n",obtener_stringPoder(cb));
                        printf("|        |        ||+               |             |                              |        ||            |\n");
                        printf("|        |   B    |||               |             |                              |   A    ||            |\n");
                        printf("|        |        |||               |             |      +-------------+         |        ||            |\n");
                        printf("|        |        |||               |             |      |             |         |        ||            |\n");
                        if(strncmp("IA_",a->nombre,3)==0)
                            printf("|        |        |||               |             |      |%-13s|         |        ||            |\n",obtener_stringPoder(cb));
                        else
                            printf("|        |        |||               |             |      |%-13s|         |        ||            |\n",obtener_stringPoder(ca));
                        printf("|        +--------+||               +-------------+      |             |         +--------+|            |\n");
                        printf("|         +--------+|                                    |             |          +--------+            |\n");
                        printf("|                                                        |             |                                |\n");
                        printf("|                                                        |             |                                |\n");

                   }else
                   {
                        if(Cant==34)
                        {
                            printf("|        +--------+                 |             |                                                     |\n");
                            if(strncmp("IA_",a->nombre,3)==0)
                                printf("|        |        |+                |%-13s|                                                     |\n",obtener_stringPoder(ca));
                            else
                                printf("|        |        |+                |%-13s|                                                     |\n",obtener_stringPoder(cb));
                            printf("|        |        ||+               |             |                                                     |\n");
                            printf("|        |   B    |||+              |             |                                                     |\n");
                            printf("|        |        ||||              |             |      +-------------+                                |\n");
                            printf("|        |        ||||              |             |      |             |                                |\n");
                            if(strncmp("IA_",a->nombre,3)==0)
                                printf("|        |        ||||              |             |      |%-13s|                                |\n",obtener_stringPoder(cb));
                            else
                                printf("|        |        ||||              |             |      |%-13s|                                |\n",obtener_stringPoder(ca));
                            printf("|        +--------+|||              +-------------+      |             |                                |\n");
                            printf("|         +--------+||                                   |             |                                |\n");
                            printf("|          +--------+|                                   |             |                                |\n");
                            printf("|           +--------+                                   |             |                                |\n");
                        }else
                        {

                            printf("|        +--------+                 |             |                                                     |\n");
                            if(strncmp("IA_",a->nombre,3)==0)
                                printf("|        |        |+                |%-13s|                                                     |\n",obtener_stringPoder(ca));
                            else
                                printf("|        |        |+                |%-13s|                                                     |\n",obtener_stringPoder(cb));
                            printf("|        |        ||+               |             |                                                     |\n");
                            printf("|        |   B    |||+              |             |                                                     |\n");
                            printf("|        |        ||||              |             |      +-------------+                                |\n");
                            printf("|        |        ||||              |             |      |             |                                |\n");
                            if(strncmp("IA_",a->nombre,3)==0)
                                printf("|        |        ||||              |             |      |%-13s|                                |\n",obtener_stringPoder(cb));
                            else
                                printf("|        |        ||||              |             |      |%-13s|                                |\n",obtener_stringPoder(ca));
                            printf("|        +--------+|||              +-------------+      |             |                                |\n");
                            printf("|         +--------+||                                   |             |                                |\n");
                            printf("|          +--------+|                                   |             |                                |\n");
                            printf("|           +--------+                                   |             |                                |\n");
                        }
                   }
           }
        }


        printf("|                                                        |             |                                |\n");
        printf("|                                                        +-------------+                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                        +-------------++-------------++-------------+                  |\n");
        printf("|+----------------------------------+    |             ||             ||             |                  |\n");
       if(strncmp("IA_",a->nombre,3)!=0)
        {
            printf("||                                  |    |%-13s||%-13s||%-13s|                  |\n",obtener_stringPoder(&a->mano.mano[0]),obtener_stringPoder(&a->mano.mano[1]),obtener_stringPoder(&a->mano.mano[2]));
            printf("|| Nombre:%-25s |    |             ||             ||             |                  |\n",a->nombre);
            printf("|| Pts:%2d                           |    |             ||             ||             |                  |\n",a->puntajeAcumulado);
        }
        else
        {
            printf("||                                  |    |%-13s||%-13s||%-13s|                  |\n",obtener_stringPoder(&b->mano.mano[0]),obtener_stringPoder(&b->mano.mano[1]),obtener_stringPoder(&b->mano.mano[2]));
            printf("|| Nombre:%-25s |    |             ||             ||             |                  |\n",b->nombre);
            printf("|| Pts:%2d                           |    |             ||             ||             |                  |\n",b->puntajeAcumulado);
        }
        printf("||                                  |    |             ||             ||             |                  |\n");
        printf("||                                  |    |             ||             ||             |                  |\n");
        printf("|+----------------------------------+    +-------------++-------------++-------------+                  |\n");
        printf("+-------------------------------------------------------------------------------------------------------+\n");
    }
    Sleep(1000);
}
