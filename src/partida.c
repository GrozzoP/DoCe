#include "../include/partida.h"
void intercambiar_mazos(tLista * mazoA,tLista * mazoB,int * CantidadCartas)
{
    vistas_remezclando();
    *mazoA = *mazoB; //paso la cabeza del maso de descarte al principal
    *mazoB = NULL; //se pone null en el de descarte, porque sino ambos apuntarian a lo mismo
    *CantidadCartas=0;
}
void asignar_puntos(tJugador * jugPrincipal,tJugador * jugContrincante,tCarta * principal, tCarta * contrincante)
{
    if(principal->tipoPoder == SUMAR_2 || principal->tipoPoder == SUMAR_1)
        (principal->tipoPoder == SUMAR_1)? ( jugPrincipal->puntajeAcumulado+=1 ) : ( jugPrincipal->puntajeAcumulado += 2 );
    if(contrincante->tipoPoder == SUMAR_2 || contrincante->tipoPoder == SUMAR_1)
        (contrincante->tipoPoder == SUMAR_1)? ( jugContrincante->puntajeAcumulado += 1 ): ( jugContrincante->puntajeAcumulado += 2 );
    if(principal->tipoPoder == RESTAR_1 || principal->tipoPoder == RESTAR_2)
    {
        if(contrincante->tipoPoder == ESPEJO)
        {
            (principal->tipoPoder == RESTAR_1)? ( jugPrincipal->puntajeAcumulado -= 1 ):( jugPrincipal->puntajeAcumulado -= 2);
            if(jugPrincipal->puntajeAcumulado<0)
                jugPrincipal->puntajeAcumulado=0;
        }else
        {
            (principal->tipoPoder == RESTAR_1) ? ( jugContrincante->puntajeAcumulado -= 1 ) : ( jugContrincante->puntajeAcumulado -=2 );
            if(jugContrincante->puntajeAcumulado<0)
                jugContrincante->puntajeAcumulado=0;
        }
    }
    if(contrincante->tipoPoder == RESTAR_1 || contrincante->tipoPoder == RESTAR_2)
    {
        if(principal->tipoPoder == ESPEJO)
        {
            (contrincante->tipoPoder == RESTAR_1)? (jugContrincante->puntajeAcumulado -= 1) : (jugContrincante->puntajeAcumulado -= 2);
            if(jugContrincante->puntajeAcumulado<0)
                jugContrincante->puntajeAcumulado=0;
        }else
        {
            (contrincante->tipoPoder == RESTAR_1) ? (jugPrincipal->puntajeAcumulado -= 1) : (jugPrincipal->puntajeAcumulado -=2 );
            if(jugPrincipal->puntajeAcumulado<0)
                jugPrincipal->puntajeAcumulado=0;
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
            primera_vez=0;
        }
        fprintf(pf,"%8d|%-25s|%-25s|%-25d|%-25d\n",jugada.nroJugada,jugada.cartaJugada_primer_jugador,jugada.cartaJugada_segundo_jugador,jugada.puntajeAcumulado_primer_jugador,jugada.puntajeAcumulado_segundo_jugador);
    }
}

void almacenar_turno(tCola * cola_regTurnos,tJugador * primer_jugador,tJugador * segundo_jugador,tCarta carta_primer_jugador,tCarta carta_segundo_jugador,int turno)
{
    tJugada reg_jugada;

    reg_jugada.nombreJugador[0]=primer_jugador->nombre;
    reg_jugada.nombreJugador[1]=segundo_jugador->nombre;

    strcpy(reg_jugada.cartaJugada_primer_jugador,obtener_stringPoder(&carta_primer_jugador));
    strcpy(reg_jugada.cartaJugada_segundo_jugador,obtener_stringPoder(&carta_segundo_jugador));

    reg_jugada.puntajeAcumulado_primer_jugador=primer_jugador->puntajeAcumulado;
    reg_jugada.puntajeAcumulado_segundo_jugador=segundo_jugador->puntajeAcumulado;

    reg_jugada.nroJugada=turno;

    enColar(cola_regTurnos,&reg_jugada,sizeof(tJugada));
}

void procesar_partida(tLista* mazoA, tLista* mazoB,tCola* cola_regTurnos, tJugador* primer_jugador, tJugador* segundo_jugador, int posIA, ACCION POS_IA)
{
    tCarta vacia, carta_primer_jugador, carta_segundo_jugador;
    int pos;
    int turno = 1,cantidadCartas=0;

    while((primer_jugador->puntajeAcumulado < 12) && (segundo_jugador->puntajeAcumulado < 12))
    {
        vistas_juego(primer_jugador,segundo_jugador,&vacia,&vacia,cantidadCartas);

        do {
            cantidadCartas++;
            if(posIA == 0)
                pos = POS_IA(primer_jugador, NULL, segundo_jugador->puntajeAcumulado);
            else
                pos = obtener_pos_carta_jugador();
            carta_primer_jugador = primer_jugador->mano.mano[pos];

            vistas_juego(primer_jugador, segundo_jugador, &carta_primer_jugador, &vacia, cantidadCartas);

            descartar_carta_mano(mazoB, primer_jugador, pos, cantidadCartas);
            if(pedir_carta_maso(mazoA,primer_jugador,pos) == LISTA_VACIA)
            {
                intercambiar_mazos(mazoA,mazoB,&cantidadCartas);
                pedir_carta_maso(mazoA,primer_jugador,pos);
                vistas_juego(primer_jugador, segundo_jugador, &carta_primer_jugador, &vacia, cantidadCartas);
            }
            if(carta_primer_jugador.tipoPoder == REPETIR_TURNO)
            {
                almacenar_turno(cola_regTurnos,primer_jugador,segundo_jugador,carta_primer_jugador,vacia,turno);
                vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&vacia,cantidadCartas);
            }
        } while(carta_primer_jugador.tipoPoder == REPETIR_TURNO && lista_vacia(mazoA) != LISTA_VACIA );

        do {
            cantidadCartas++;
            if(posIA == 1)
                pos = POS_IA(segundo_jugador,&carta_primer_jugador,primer_jugador->puntajeAcumulado);
            else
                pos = obtener_pos_carta_jugador();

            carta_segundo_jugador = segundo_jugador->mano.mano[pos];

            vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador,cantidadCartas);

            descartar_carta_mano(mazoB,segundo_jugador,pos,cantidadCartas);
            if(pedir_carta_maso(mazoA,segundo_jugador,pos)==LISTA_VACIA)
            {
                intercambiar_mazos(mazoA,mazoB,&cantidadCartas);
                pedir_carta_maso(mazoA,segundo_jugador,pos);
                vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador,cantidadCartas);
            }
            if(carta_segundo_jugador.tipoPoder == REPETIR_TURNO)
            {
                almacenar_turno(cola_regTurnos, primer_jugador, segundo_jugador, carta_primer_jugador, carta_segundo_jugador,turno);
                vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador,cantidadCartas);
            }
        } while( carta_segundo_jugador.tipoPoder == REPETIR_TURNO  && lista_vacia(mazoA) != LISTA_VACIA);

        asignar_puntos(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador);
        almacenar_turno(cola_regTurnos,primer_jugador,segundo_jugador,carta_primer_jugador,carta_segundo_jugador,turno);
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
    if((res=cargar_carta_lista_random(&mazoA,"cartas.txt")) != TODO_OK)
        return res;

    //creo y cargo los jugadores, no interesa el orden con que se creen
    if((posIA = cargar_jugador(&jug[0],&jug[1])) == -12)
    {
        vaciar_lista(&mazoA);
        fclose(pfRegistros);
        return posIA;
    }

    //cargo la mano de cada jugador
    vistas_repartiendo();

    cargar_mano(&jug[0],&mazoA);
    cargar_mano(&jug[1],&mazoA);

    //aca ocurre el juego
    partida(&mazoA, &mazoB, &cola_regTurnos, &jug[0], &jug[1],posIA);

    //grabo los registros
    imprimir_turnos(&cola_regTurnos,pfRegistros);

    system("CLS");
    printf("\n---------[Ganador]---------------\n");

    if(jug[0].puntajeAcumulado > 11)
    {
        printf("\nJugador ganador: [%s]\nPuntos obtenidos:%d\n", jug[0].nombre,jug[0].puntajeAcumulado);
       if(strncmp("IA_",jug[0].nombre,3)!=0)
            enviar_jugador_JSON(&jug[0]);
    }
    else
    {
        printf("\nJugador ganador: [%s]\nPuntos obtenidos:%d\n", jug[1].nombre,jug[1].puntajeAcumulado);
        if(strncmp("IA_",jug[1].nombre,3)!=0)
            enviar_jugador_JSON(&jug[1]);
    }

    printf("\n---------------------------------\n");

    //retiro las 6 cartas que le quedan a los jugadores
    descartar_mano(&jug[0],&mazoB);
    descartar_mano(&jug[1],&mazoB);

    //vacio ambos mazos y cierro archivo de registros
    vaciar_cola(&cola_regTurnos);
    vaciar_lista(&mazoA);
    vaciar_lista(&mazoB);
    fclose(pfRegistros);

    if(lista_vacia(&mazoA)!= LISTA_VACIA || lista_vacia(&mazoB) != LISTA_VACIA || cola_vacia(&cola_regTurnos) != COLA_VACIA)
        return -11;


    return TODO_OK;
}
