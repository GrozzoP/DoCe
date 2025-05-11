#ifndef TIPO_JUGADOR_H_INCLUDED
#define TIPO_JUGADOR_H_INCLUDED

#ifndef CONFIG_H_INCLUDED
#error "Debe incluir config.h antes de tipo_jugador.h"
#endif

struct TipoJugador
{
	enum Perfiles		tipo;
};

typedef		struct TipoJugador 	TipoJugador;

#endif // TIPO_JUGADOR_H_INCLUDED
