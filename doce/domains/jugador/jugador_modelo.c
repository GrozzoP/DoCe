
#include	"jugador/jugador_modelo.h"
#include	"jugador/jugador_privado.h"
#include	<stdlib.h>


Jugador Jugador__nuevo(char* nombre)
{
	return (Jugador){
					 .nombre = nombre};
}
void Jugador__borrar(Jugador* jugador)
{
	free(jugador->nombre);
}
