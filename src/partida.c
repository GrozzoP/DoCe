#include "../include/partida.h"
void intercambiar_mazos(tLista * mazoA,tLista * mazoB,int * CantidadCartas)
{
    vistas_remezclando();
    *mazoA = *mazoB;
    *mazoB = NULL;
    *CantidadCartas=0;
}
void asignar_puntos(tJugador* jugPrincipal, tJugador* jugContrincante, tCarta* principal, tCarta* contrincante)
{
    if(principal->tipoPoder == SUMAR_2 || principal->tipoPoder == SUMAR_1)
        (principal->tipoPoder == SUMAR_1)? ( jugPrincipal->puntajeAcumulado+=1 ) : ( jugPrincipal->puntajeAcumulado += 2);

    if(contrincante->tipoPoder == SUMAR_2 || contrincante->tipoPoder == SUMAR_1)
        (contrincante->tipoPoder == SUMAR_1)? ( jugContrincante->puntajeAcumulado += 1 ) : ( jugContrincante->puntajeAcumulado += 2);

    if(principal->tipoPoder == RESTAR_1 || principal->tipoPoder == RESTAR_2)
    {
        if(contrincante->tipoPoder == ESPEJO)
        {
            (principal->tipoPoder == RESTAR_1) ? (jugPrincipal->puntajeAcumulado -= 1 ) : ( jugPrincipal->puntajeAcumulado -= 2);
            if(jugPrincipal->puntajeAcumulado < 0)
                jugPrincipal->puntajeAcumulado = 0;
        }else
        {
            (principal->tipoPoder == RESTAR_1) ? ( jugContrincante->puntajeAcumulado -= 1 ) : ( jugContrincante->puntajeAcumulado -= 2);
            if(jugContrincante->puntajeAcumulado < 0)
                jugContrincante->puntajeAcumulado = 0;
        }
    }

    if(contrincante->tipoPoder == RESTAR_1 || contrincante->tipoPoder == RESTAR_2)
    {
        if(principal->tipoPoder == ESPEJO)
        {
            (contrincante->tipoPoder == RESTAR_1)? (jugContrincante->puntajeAcumulado -= 1) : (jugContrincante->puntajeAcumulado -= 2);
            if(jugContrincante->puntajeAcumulado < 0)
                jugContrincante->puntajeAcumulado = 0;
        }else
        {
            (contrincante->tipoPoder == RESTAR_1) ? (jugPrincipal->puntajeAcumulado -= 1) : (jugPrincipal->puntajeAcumulado -= 2 );
            if(jugPrincipal->puntajeAcumulado < 0)
                jugPrincipal->puntajeAcumulado = 0;
        }
    }
}

void imprimir_turnos(tCola * cola_regTurnos,FILE*pf)
{
    tJugada jugada;
    static int primera_vez=1;
    while(desEnColar(cola_regTurnos,&jugada,sizeof(tJugada))!= COLA_VACIA)
    {
        if(primera_vez)
        {
            fprintf(pf,"%-8s|%-25s|%-25s|%-25s|%-25s\n","TURNO","CARTA SELECCIONADA","CARTA SELECCIONADA","PUNTOS AL MOMENTO","PUNTOS AL MOMENTO");
            fprintf(pf,"%-8s|%-25s|%-25s|%-25s|%-25s\n","JUGADOR",jugada.nombreJugador[0],jugada.nombreJugador[1],jugada.nombreJugador[0],jugada.nombreJugador[1]);
            primera_vez = 0;
        }
        fprintf(pf, "%8d|%-25s|%-25s|%-25d|%-25d\n", jugada.nroJugada, jugada.cartaJugada_primer_jugador, jugada.cartaJugada_segundo_jugador, jugada.puntajeAcumulado_primer_jugador, jugada.puntajeAcumulado_segundo_jugador);
    }
}

void almacenar_turno(tCola* cola_regTurnos, tJugador* primer_jugador, tJugador* segundo_jugador, tCarta carta_primer_jugador, tCarta carta_segundo_jugador, int turno)
{
    tJugada reg_jugada;

    reg_jugada.nombreJugador[0] = primer_jugador->nombre;
    reg_jugada.nombreJugador[1] = segundo_jugador->nombre;

    strcpy(reg_jugada.cartaJugada_primer_jugador,obtener_stringPoder(&carta_primer_jugador));
    strcpy(reg_jugada.cartaJugada_segundo_jugador,obtener_stringPoder(&carta_segundo_jugador));

    reg_jugada.puntajeAcumulado_primer_jugador=primer_jugador->puntajeAcumulado;
    reg_jugada.puntajeAcumulado_segundo_jugador=segundo_jugador->puntajeAcumulado;

    reg_jugada.nroJugada=turno;

    enColar(cola_regTurnos,&reg_jugada,sizeof(tJugada));
}

void procesar_jugada(tLista* mazoA, tLista* mazoB,tCola* cola_regTurnos, tJugador* jugador_actual, tJugador* jugador_contrincante,
                    tCarta* carta_jugador_actual,tCarta* carta_jugador_contrincante, int* cantidadCartas, int turno, ACCION POS_IA)
{
    int pos;
    do {
            (*cantidadCartas)++;
            if(POS_IA)
                pos = POS_IA(jugador_actual, carta_jugador_contrincante, jugador_contrincante->puntajeAcumulado);
            else
                pos = obtener_pos_carta_jugador();
            *carta_jugador_actual = jugador_actual->mano.mano[pos];

            vistas_juego(jugador_actual, jugador_contrincante, carta_jugador_actual, carta_jugador_contrincante, *cantidadCartas);

            descartar_carta_mano(mazoB, jugador_actual, pos, *cantidadCartas);
            if(pedir_carta_mazo(mazoA,jugador_actual,pos) == LISTA_VACIA)
            {
                intercambiar_mazos(mazoA, mazoB, cantidadCartas);
                pedir_carta_mazo(mazoA, jugador_actual, pos);
                vistas_juego(jugador_actual, jugador_contrincante, carta_jugador_actual, carta_jugador_contrincante, *cantidadCartas);
            }

            if(carta_jugador_actual->tipoPoder == REPETIR_TURNO)
            {
                almacenar_turno(cola_regTurnos, jugador_actual, jugador_contrincante, *carta_jugador_actual, *carta_jugador_contrincante, turno);
                vistas_juego(jugador_actual, jugador_contrincante, carta_jugador_actual, carta_jugador_contrincante, *cantidadCartas);
            }

        } while(carta_jugador_actual->tipoPoder == REPETIR_TURNO);
}

void procesar_partida(tLista* mazoA, tLista* mazoB, tCola* cola_regTurnos, tJugador* primer_jugador, tJugador* segundo_jugador, int posIA, ACCION POS_IA)
{
    tCarta vacia, carta_primer_jugador, carta_segundo_jugador;
    int turno = 1,cantidadCartas=0;

    while((primer_jugador->puntajeAcumulado < 12) && (segundo_jugador->puntajeAcumulado < 12))
    {
        vistas_juego(primer_jugador, segundo_jugador, &vacia, &vacia, cantidadCartas);

        if(posIA == 0)
        {
            procesar_jugada(mazoA,mazoB,cola_regTurnos,primer_jugador,segundo_jugador,&carta_primer_jugador,&vacia,&cantidadCartas,turno,POS_IA);
            procesar_jugada(mazoA,mazoB,cola_regTurnos,segundo_jugador,primer_jugador,&carta_segundo_jugador,&carta_primer_jugador,&cantidadCartas,turno,NULL);
        }
        else
        {
            procesar_jugada(mazoA,mazoB,cola_regTurnos,primer_jugador,segundo_jugador,&carta_primer_jugador,&vacia,&cantidadCartas,turno,NULL);
            procesar_jugada(mazoA,mazoB,cola_regTurnos,segundo_jugador,primer_jugador,&carta_segundo_jugador,&carta_primer_jugador,&cantidadCartas,turno,POS_IA);
        }
        asignar_puntos(primer_jugador, segundo_jugador, &carta_primer_jugador, &carta_segundo_jugador);
        almacenar_turno(cola_regTurnos, primer_jugador, segundo_jugador, carta_primer_jugador, carta_segundo_jugador,turno);
        turno++;
    }
}

void partida(tLista * mazoA,tLista * mazoB,tCola * cola_regTurnos,tJugador * primer_jugador,tJugador * segundo_jugador,int posIA)
{
    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_FACIL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_FACIL])==0)
        procesar_partida(mazoA,mazoB,cola_regTurnos,primer_jugador,segundo_jugador,posIA,obtener_pos_carta_IA_facil);

    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_NORMAL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_NORMAL])==0)
        procesar_partida(mazoA,mazoB,cola_regTurnos,primer_jugador,segundo_jugador,posIA,obtener_pos_carta_IA_normal);

    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_DIFICIL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_DIFICIL])==0)
        procesar_partida(mazoA, mazoB, cola_regTurnos, primer_jugador, segundo_jugador, posIA, obtener_pos_carta_IA_dificil);
}

void mostrar_y_subir_jugador_ganador_API(tJugador * primer_jugador,tJugador * segundo_jugador)
{
    system("CLS");
    printf("\n---------------[Jugador Ganador]---------------\n");

    if(primer_jugador->puntajeAcumulado > 11)
    {
        printf("\n[Nombre del Jugador]: %s\n[Puntos obtenidos]: %d\n", primer_jugador->nombre, primer_jugador->puntajeAcumulado);
        if(strncmp("IA_",primer_jugador->nombre,3) != 0)
            enviar_jugador_JSON(primer_jugador);
    }
    else
    {
        printf("\n[Nombre del Jugador]: %s\n[Puntos obtenidos]: %d\n", segundo_jugador->nombre, segundo_jugador->puntajeAcumulado);
        if(strncmp("IA_",segundo_jugador->nombre,3) != 0)
            enviar_jugador_JSON(segundo_jugador);
    }
    printf("\n-----------------------------------------------\n");
}

void crear_archivo_informes(FILE ** pInforme)
{
    char hora[32], nombre_reg[37];
    time_t fecha = time(NULL);
    struct tm* hora_local = localtime(&fecha);
    strftime(hora,sizeof(hora),"informe-juego_%Y-%m-%d-%H-%M",hora_local);
    snprintf(nombre_reg,sizeof(nombre_reg),"%s.txt",hora);
    *pInforme=fopen(nombre_reg,"wt");
}

int juegoDOCE()
{

    FILE* pfRegistros;
    tLista mazoA,mazoB;
    tCola cola_regTurnos;
    int posIA, res;
    tJugador jug[2];

    //creo el archivo informe con la fecha
    crear_archivo_informes(&pfRegistros);
    if(!pfRegistros)
        return ERROR_ARCHIVO;

    // Creo los mazos
    crear_lista(&mazoA);
    crear_lista(&mazoB);
    //creo la cola de registros
    crear_cola(&cola_regTurnos);

    //cargo el mazo principal
    if((res=cargar_carta_lista_random(&mazoA, "cartas.txt")) != TODO_OK)
        return res;

    //creo y cargo los jugadores, no interesa el orden con que se creen
    if((posIA = cargar_jugador(&jug[0], &jug[1])) == JUGADOR_NO_CARGADO)
    {
        vaciar_lista(&mazoA);
        fclose(pfRegistros);
        return posIA;
    }

    //cargo la mano de cada jugador
    vistas_repartiendo();

    cargar_mano(&jug[0], &mazoA);
    cargar_mano(&jug[1], &mazoA);

    //aca ocurre el juego
    partida(&mazoA, &mazoB, &cola_regTurnos, &jug[0], &jug[1],posIA);

    //grabo los registros
    imprimir_turnos(&cola_regTurnos, pfRegistros);

    //muestra en pantalla quien gano y se sube a la api en caso de ser humano
    mostrar_y_subir_jugador_ganador_API(&jug[0],&jug[1]);

    //retiro las 6 cartas que le quedan a los jugadores
    descartar_mano(&jug[0],&mazoB);
    descartar_mano(&jug[1],&mazoB);

    //vacio ambos mazos y cierro archivo de registros
    vaciar_cola(&cola_regTurnos);
    vaciar_lista(&mazoA);
    vaciar_lista(&mazoB);
    fclose(pfRegistros);

    if(lista_vacia(&mazoA)!= LISTA_VACIA || lista_vacia(&mazoB) != LISTA_VACIA || cola_vacia(&cola_regTurnos) != COLA_VACIA)
        return PERDIDA_DE_DATOS;

    return TODO_OK;
}
