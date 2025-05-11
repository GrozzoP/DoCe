
#include	"juego/juego_vista.h"
#include	"ui/ui_contexto.h"
#include	<stdio.h>
#include	<windows.h>


char Vista__selecionarCarta()
{
	fflush(stdin);
	return getc(stdin);
}
void Vista__mostrarPartida(const CtxUI* ctx)
{
	system("cls");
	puts  ("\t-----------------------------");
	puts  ("\t|       |  |  |  |          |");
	puts  ("\t|       |  |  |  |          |");
	puts  ("\t|        -- -- --           |");
	printf("\t|                           | ---> jugador: %s\n", ctx->jugadores[1]);
	puts  ("\t|                           |");
	puts  ("\t|                     ____  |");
	puts  ("\t|                    |MAZO| |");
	puts  ("\t|                    |    | |");
	puts  ("\t|                    |____| |");
	puts  ("\t|                           |");
	printf("\t|                           | ---> TURNO de: %s\n", ctx->jugadorActual);
	puts  ("\t|          ____             |");
	printf("\t|         |T   |            | T: %s\n", ctx->ultimaCarta);
	puts  ("\t|         |    |            |");
	puts  ("\t|         |____|            |");
	puts  ("\t|                           |");
	puts  ("\t|                           |");
	printf("\t|                           | ---> jugador: %s\n", ctx->jugadores[0]);
	puts  ("\t|                           |");
	puts  ("\t|                           |");
	puts  ("\t|                           |");
	puts  ("\t|        ---- ---- ----     |");
	printf("\t|       |A   |B   |C   |    | A: %s\n", ctx->cartas[0]);
	printf("\t|       |    |    |    |    | B: %s\n", ctx->cartas[1]);
	printf("\t|       |    |    |    |    | C: %s\n", ctx->cartas[2]);
	puts  ("\t-----------------------------");
}
void Vista__mostrarJugador(char* jugador)
{

}
void Vista__mostrarGanador(char* ganador)
{

}
