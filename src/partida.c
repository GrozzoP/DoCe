#include "../include/partida.h"
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
    int primera_vez=0;
    tJugada jugada;
    while(desEnColar(cola_regTurnos,&jugada,sizeof(tJugada))!= COLA_VACIA)
    {
        if(primera_vez==0)
        {
            fprintf(pf,"TURNO|JUGADOR             |CARTA SELECCIONADA|PUNTOS AL MOMENTO \n");
            primera_vez++;
        }else
        {
            fprintf(pf,"%5d|%20s|%18s|%-2d \n",jugada.nroJugada,jugada.nombreJugador,jugada.cartaJugada,jugada.puntajeAcumulado);
        }
    }
}
void almacenar_turno(tCola * cola_regTurnos,tJugador * primer_jugador,tCarta carta_primer_jugador,int turno)
{
    tJugada primera_jugada;

    strcpy(primera_jugada.nombreJugador,primer_jugador->nombre);
    strcpy(primera_jugada.cartaJugada,obtener_stringPoder(&carta_primer_jugador));
    primera_jugada.puntajeAcumulado=primer_jugador->puntajeAcumulado;
    primera_jugada.nroJugada=turno;

    enColar(cola_regTurnos,&primera_jugada,sizeof(tJugada));

}
void procesar_partida(tLista * masoA,tLista * masoB,tCola * cola_regTurnos,tJugador *primer_jugador,tJugador * segundo_jugador,int * cantidadCartas,int posIA,ACCION POS_IA)
{
    tCarta vacia,carta_primer_jugador,carta_segundo_jugador;
    int pos;
    static int turno=1;

    vistas_juego(primer_jugador,segundo_jugador,&vacia,&vacia,*cantidadCartas);
    Sleep(1000);
    do{
        (*cantidadCartas)++;
        if(posIA == 0)
            pos=POS_IA(primer_jugador,NULL,segundo_jugador->puntajeAcumulado);
        else
            pos=obtener_pos_carta_jugador();
        carta_primer_jugador=primer_jugador->mano.mano[pos];

        system("CLS");
        vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&vacia,*cantidadCartas);
        Sleep(1000);

        descartar_carta_mano(masoB,primer_jugador,pos,*cantidadCartas);
        pedir_carta_maso(masoA,primer_jugador,pos);
        if(carta_primer_jugador.tipoPoder == REPETIR_TURNO)
        {
            almacenar_turno(cola_regTurnos,primer_jugador,carta_primer_jugador,turno);
            system("CLS");
            vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&vacia,*cantidadCartas);
        }
    }while(carta_primer_jugador.tipoPoder == REPETIR_TURNO && lista_vacia(masoA) != LISTA_VACIA );
    do{

        (*cantidadCartas)++;
        if(posIA == 1)
            pos=POS_IA(segundo_jugador,&carta_primer_jugador,primer_jugador->puntajeAcumulado);
        else
            pos=obtener_pos_carta_jugador();

        carta_segundo_jugador=segundo_jugador->mano.mano[pos];

        system("CLS");
        vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador,*cantidadCartas);
        Sleep(1000);

        descartar_carta_mano(masoB,segundo_jugador,pos,*cantidadCartas);
        pedir_carta_maso(masoA,segundo_jugador,pos);
        if(carta_segundo_jugador.tipoPoder == REPETIR_TURNO)
        {
            almacenar_turno(cola_regTurnos,segundo_jugador,carta_segundo_jugador,turno);
            system("CLS");
            vistas_juego(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador,*cantidadCartas);
        }
    }while( carta_segundo_jugador.tipoPoder == REPETIR_TURNO  && lista_vacia(masoA) != LISTA_VACIA);

    asignar_puntos(primer_jugador,segundo_jugador,&carta_primer_jugador,&carta_segundo_jugador);

    almacenar_turno(cola_regTurnos,primer_jugador,carta_primer_jugador,turno);
    almacenar_turno(cola_regTurnos,segundo_jugador,carta_segundo_jugador,turno);

    turno++;
    system("CLS");
}
void partida(tLista * masoA,tLista * masoB,tCola * cola_regTurnos,tJugador * primer_jugador,tJugador * segundo_jugador,int * cantidadCartas,int posIA)
{
    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_FACIL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_FACIL])==0)
        procesar_partida(masoA,masoB,cola_regTurnos,primer_jugador,segundo_jugador,cantidadCartas,posIA,obtener_pos_carta_IAfacil);

    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_NORMAL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_NORMAL])==0)
        procesar_partida(masoA,masoB,cola_regTurnos,primer_jugador,segundo_jugador,cantidadCartas,posIA,obtener_pos_carta_IAnormal);

    if(strcmpi(primer_jugador->nombre,STRING_PERFILES[IA_DIFICIL])==0 || strcmpi(segundo_jugador->nombre,STRING_PERFILES[IA_DIFICIL])==0)
        procesar_partida(masoA,masoB,cola_regTurnos,primer_jugador,segundo_jugador,cantidadCartas,posIA,obtener_pos_carta_IAdificil);
}
int juegoDOCE()
{
    tLista masoA,masoB;
    tCola cola_regTurnos;
    int vecesVaciado=0,
        cantidadCartas=0,
        posIA;
    tJugador jug[2];
    FILE*pfRegistros=fopen("REGISTROS.txt","wt");
    if(!pfRegistros)
        return -5;

    //creo los masos
    crear_lista(&masoA);
    crear_lista(&masoB);

    crear_cola(&cola_regTurnos);

    //cargo el principal
    int res;
    if((res=cargar_carta_lista_random(&masoA,"cartas.txt"))==ERROR_SOBRECARGA_CARTAS)
        return ERROR_SOBRECARGA_CARTAS;
    if(res == ERROR_OBTENER_TIPOPODER_SEGUN_CARTA)
        return ERROR_OBTENER_TIPOPODER_SEGUN_CARTA;
    system("CLS");
    //creo y cargo los jugadores, no interesa el orden con que se creen
    //lo importante que uno se llame ia(esto para la funcion obtener_pos_carta_jugador())
//    habilitarANSI();
    puts("");
    vistas_bienvenida();
    posIA=cargarJugador(&jug[0],&jug[1]);
    //cargo la mano de cada jugador
    cargar_mano(&jug[0],&masoA);
    cargar_mano(&jug[1],&masoA);;
    while( (jug[1].puntajeAcumulado<12) && (jug[0].puntajeAcumulado<12))//mientras que ninguno supere los 12 puntos
    {

        partida(&masoA,&masoB,&cola_regTurnos,&jug[0],&jug[1],&cantidadCartas,posIA);

        if(lista_vacia(&masoA) == LISTA_VACIA)
        {
            vecesVaciado++;
            masoA=masoB;//paso la cabeza del maso de descarte al principal
            masoB=NULL;//se pone null en el de descarte, porque sino ambos apuntarian a lo mismo
            cantidadCartas=0;
        }
    }
    imprimir_turnos(&cola_regTurnos,pfRegistros);
    system("CLS");
    printf("\nVeces que se remezclo el maso : %d\n",vecesVaciado);
    printf("\n---------[Ganador]---------------\n");
    if(jug[0].puntajeAcumulado>11)
        printf("\nJugador ganador: [%s]\nPuntos obtenidos:%d\n",jug[0].nombre,jug[0].puntajeAcumulado);
    else
        printf("\nJugador ganador: [%s]\nPuntos obtenidos:%d\n",jug[1].nombre,jug[1].puntajeAcumulado);

    printf("\n---------------------------------\n");
    //retiro las 6 cartas que le quedan a los jugadores
    descartar_mano(&jug[0],&masoB);
    descartar_mano(&jug[1],&masoB);
    //vacio ambos masos
    vaciar_cola(&cola_regTurnos);
    vaciar_lista(&masoA);
    vaciar_lista(&masoB);
    fclose(pfRegistros);
    if(lista_vacia(&masoA)!= LISTA_VACIA || lista_vacia(&masoB)!= LISTA_VACIA)
        printf(".......hubo perdida de datos........");
    return 1;
}
