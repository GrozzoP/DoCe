
#include 	<stdbool.h>
#include	"menu/menu_controlador.h"
#include	"menu/menu_vista.h"
#include	"partida/partida_controlador.h"
#include	"ranking/ranking_controlador.h"
#include	"includes/config.h"


int Controlador__menu(bool* puedeContinuar)
{
	int ret = 0;

	Vista__mostrarMenu();

	switch(Vista__ingresarOpcion())
	{
		case JUGAR:
			ret = Controlador__partida();
			break;

		case VER_RANKING:
			ret = Controlador__ranking();
			break;

		case SALIR:
			*puedeContinuar = false;
			break;

		default:
			Vista__ingresoIncorrecto();
	}

	return ret;
}
