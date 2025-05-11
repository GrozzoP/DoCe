
#include	"interfaces/juego_ia/juego_ia_interfaz.h"
#include 	"juego/juego_modelo.h"
#include 	"ia/ia_servicio.h"


char Juego_IA__generarRespuesta(const Juego* j)
{
	CtxIA nuevo = {.puntajeIa = 0};
	/*nuevo = (CtxIA){
		.puntajeIa = j->jugadores[1].puntos,
		.puntajeContricante = j->jugadores[0].puntos,
		.manoIa = j->jugadores[1].mano,
		.ultimaCarta = j->ultimaCarta
	};*/
	return Servicio__estrategiaIA(nuevo);
}
