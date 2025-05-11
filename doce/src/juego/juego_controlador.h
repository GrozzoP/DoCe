#ifndef JUEGO_CONTROLADOR_H_INCLUDED
#define JUEGO_CONTROLADOR_H_INCLUDED

typedef 	struct Juego 	Juego;
typedef 	struct JugadaCoord 	JugadaCoord;

Juego* Controlador__empezarJuego(const char* nombres[], unsigned cantJugadores, JugadaCoord* jugadas);
const bool* Controlador__terminarJuego(Juego* juego);
void Controlador__bucleJuego(Juego* juego);

#endif // JUEGO_CONTROLADOR_H_INCLUDED
