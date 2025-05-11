
#include	"partida/partida_controlador.h"
#include 	"partida/partida_vista.h"
#include	"partida/partida_persistencia.h"
#include	"partida/partida_remoto.h"

#include	"jugada/jugada_coordinador.h"
#include	"juego/juego_controlador.h"
#include	"includes/config.h" /// de aca sacamos el nombre del archivo o eso y se lo pasamos a remoto y persistencia
#include	<stddef.h>
#include	<stdlib.h>


int Controlador__partida()
{
	unsigned cant = Vista__cantidadJugadores();
	const char** nombres = malloc(sizeof *nombres * cant);

	for (unsigned i = 0; 	i < cant; 	++i)
	{
		nombres[i] = Vista__ingresarNombre();
		if (!nombres[i]) { /* error */ }
	}

	Juego* j = Controlador__empezarJuego(nombres, 2, NULL);
	Controlador__bucleJuego(j);
	Controlador__terminarJuego(j);

	return 0;
}
int Controlador__partidaTest()
{
	const char* nombres[] = {"test", "ia"};
	const bool ganadores[] = {true,false};
	JugadaCoord* jugadas = iniciarJugadas();

	Juego* j = Controlador__empezarJuego(nombres, 2, jugadas);

	Controlador__bucleJuego(j);

	__attribute__((unused)) const bool* Ganadores = Controlador__terminarJuego(j);

	//una vez que termina el juego se sube a la nube y se guarda localmente
	Persistencia__grabarInforme("test.txt", jugadas);
	Remoto__subirPartida(nombres, ganadores, 2);

	return 0;
}
