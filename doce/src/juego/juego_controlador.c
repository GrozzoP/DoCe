
#include	<stdbool.h>
#include	"juego/juego_controlador.h"
#include 	"juego/juego_modelo.h"
#include 	"juego/juego_vista.h"
#include	"jugada/jugada_servicio.h"
#include	"juego_ia/juego_ia_interfaz.h"
#include	<stddef.h>


Juego* Controlador__empezarJuego(const char* nombres[], unsigned cantJugadores, JugadaCoord* jugadas)
{
	static Juego j = {.turnoActual = 0};

	return &j;
}
const bool* Controlador__terminarJuego(Juego* j)
{
	return NULL;
}
void Controlador__bucleJuego(Juego* j)
{
	char entrada;


	do
	{
		//actualizar pantalla
		Vista__mostrarPartida(Modelo__datosSerializados(j), Modelo__nombreTurno(j));

		//recibir input
		entrada = 	j->turnoActual == HUMANO? 	Vista__selecionarCarta():
												Juego_IA__generarRespuesta(j);

		//procesar logica()
		Modelo__procesar(j, entrada);

	}
	while (Modelo__puntuacionAlta(j) < CANT_PUNTOS);



	/*char* nombreJugadorGanador = Modelo__jugadorGanador(j);
	if (nombreJugadorGanador != NULL)
		Vista__mostrarGanador(nombreJugadorGanador);*/
}
