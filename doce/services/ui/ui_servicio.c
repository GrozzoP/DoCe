
#include	"ui/ui_servicio.h"
#include	<stddef.h>
#include	<stdlib.h>

CtxUI*	crearContextoUI(const char** jugadores, unsigned cantJugadores, unsigned cantMano)
{
    CtxUI *nuevo = malloc(sizeof *nuevo);
    if (!nuevo) return NULL;

    nuevo->jugadores     = jugadores;
    nuevo->cantJugadores = cantJugadores;
    nuevo->cantMano      = cantMano;

    nuevo->cartas        = NULL;
    nuevo->ultimaCarta   = NULL;
    nuevo->jugadorActual = NULL;

    return nuevo;
}
void	borrarContextoUI(CtxUI* ctx)
{
	free(ctx);
}
