#ifndef JUEGO_MODELO_H_INCLUDED
#define JUEGO_MODELO_H_INCLUDED

#include	"includes/config.h"
#include	"jugador/jugador_coordinador.h"
#include	"mazo/mazo_coordinador.h"
#include	"jugada/jugada_coordinador.h"
#include	"ui/ui_servicio.h"

typedef		struct Juego	Juego;

struct Juego
{
	JgdorCoord 		jugadores;
	MazoCoord		mazo;
	JugadaCoord* 	jugada;

	unsigned 		turnoActual;
	CtxUI*			datosSerializados;
};

unsigned Modelo__puntuacionAlta(Juego* juego);
void Modelo__procesar(Juego* juego, char carta);
char Modelo__estrategiaIA(Juego* juego);

#endif // JUEGO_MODELO_H_INCLUDED
