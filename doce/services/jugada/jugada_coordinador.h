#ifndef JUGADA_COORDINADOR_H_INCLUDED
#define JUGADA_COORDINADOR_H_INCLUDED

#include	"jugada/jugada_contexto.h"
typedef 	struct JugadaCoord 	JugadaCoord;

JugadaCoord* iniciarJugadas();
const Jugada* gestionarJugadas(JugadaCoord* coord);

#endif // JUGADA_COORDINADOR_H_INCLUDED
