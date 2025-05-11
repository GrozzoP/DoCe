#ifndef JUGADA_CONTEXTO_H_INCLUDED
#define JUGADA_CONTEXTO_H_INCLUDED

struct Jugada
{
	unsigned nroJugada;
	char* nombreJugador;
	char* tipoCartaJugada;
	unsigned puntoJugador;
};
typedef 	struct Jugada 	Jugada;

#endif // JUGADA_CONTEXTO_H_INCLUDED
