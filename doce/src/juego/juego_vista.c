
#include	"juego/juego_vista.h"
#include	<stdio.h>
#include	<windows.h>


char Vista__selecionarCarta()
{
	fflush(stdin);
	return getc(stdin);
}
void Vista__mostrarPartida(char d[static 4], char* jugador)
{
	system("cls");
	puts  ("\t-----------------------------");
	puts  ("\t|       |  |  |  |          |");
	puts  ("\t|       |  |  |  |          |");
	puts  ("\t|        -- -- --           |");
	printf("\t|                           | ---> %s \n", "IA");
	puts  ("\t|                           |");
	puts  ("\t|                     ____  |");
	puts  ("\t|                    |MAZO| |");
	puts  ("\t|                    |    | |");
	puts  ("\t|                    |____| |");
	puts  ("\t|                           |");
	printf("\t|                           | ---> %s %s\n", "TURNO de ", jugador);
	puts  ("\t|          ____             |");
	printf("\t|         |%c    |            |\n", d[3]);
	puts  ("\t|         |    |            |");
	puts  ("\t|         |____|            |");
	puts  ("\t|                           |");
	puts  ("\t|                           |");
	printf("\t|                           | ---> %s \n", "jugador");
	puts  ("\t|         A    B    C       |");
	puts  ("\t|        ---- ---- ----     |");
	printf("\t|       |%c    |%c    |%c    |    |\n", d[0],d[1],d[2]);
	puts  ("\t|       |    |    |    |    |");
	puts  ("\t|       |    |    |    |    |");
	puts  ("\t-----------------------------");
}
void Vista__mostrarJugador(char* jugador)
{

}
void Vista__mostrarGanador(char* ganador)
{

}
