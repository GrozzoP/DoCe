#ifndef JUGADOR_COORDINADOR_H_INCLUDED
#define JUGADOR_COORDINADOR_H_INCLUDED

#ifndef CONFIG_H_INCLUDED
#error "Debe incluir config.h antes de jugador_coordinador.h"
#endif

#include 	"jugador/jugador_publico.h"

typedef		Jugador* JgdorCoord[CANT_JUGADORES];

#endif // JUGADOR_COORDINADOR_H_INCLUDED
