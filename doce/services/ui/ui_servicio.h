#ifndef UI_SERVICIO_H_INCLUDED
#define UI_SERVICIO_H_INCLUDED

#include	"ui/ui_contexto.h"

CtxUI*	crearContextoUI(const char** jugadores, unsigned cantJugadores, unsigned cantMano);
void	borrarContextoUI(CtxUI* ctx);

#endif // UI_SERVICIO_H_INCLUDED
