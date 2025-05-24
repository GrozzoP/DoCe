#include "../../include/mazo.h"
/*
void habilitarANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo = 0;
    GetConsoleMode(hOut, &modo);
    SetConsoleMode(hOut, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}*/
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
void vistas_juego(tJugador * a,tJugador * b,tCarta * ca,tCarta *cb ,unsigned Cant)
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
   if(Cant<1)
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
