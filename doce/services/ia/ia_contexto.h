#ifndef IA_CONTEXTO_H_INCLUDED
#define IA_CONTEXTO_H_INCLUDED

#include	"includes/config.h"
#include	"carta/carta_publico.h"
#include	"mano/mano.h"

struct ContextoIA
{
	unsigned puntajeIa;
	unsigned puntajeContricante;
	Mano* manoIa;
	Carta* ultimaCarta;
};

#endif // IA_CONTEXTO_H_INCLUDED
