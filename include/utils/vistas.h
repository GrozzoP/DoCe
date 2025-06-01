#ifndef VISTAS_H_INCLUDED
#define VISTAS_H_INCLUDED

#include "../tipoJugador.h"

void habilitarANSI();
void vistas_bienvenida();
void _vistas_repartiendo(int vueltas);
void vistas_repartiendo();
void _vistas_remezclando(int vueltas);
void vistas_remezclando();
void vistas_juego(tJugador * a,tJugador * b,tCarta * ca,tCarta *cb ,unsigned Cant);

#endif // VISTAS_H_INCLUDED
