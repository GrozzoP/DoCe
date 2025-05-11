#ifndef JUGADOR_PRIVADO_H_INCLUDED
#define JUGADOR_PRIVADO_H_INCLUDED

#include	"includes/config.h"
#include	"mano/mano.h"
#include	"tipo_jugador/tipo_jugador.h"

struct Jugador
{
	char* 			nombre;
	unsigned 		puntajeAcumulado;
	Mano 			mano;
	TipoJugador 	tipoJugador;
};

#endif // JUGADOR_PRIVADO_H_INCLUDED
