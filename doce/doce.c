
#include 	<stdbool.h>
#include	"doce.h"
#include	"menu/menu_controlador.h"
#include	"partida/partida_controlador.h"


int doce__main()
{
	int ret;
	bool puedeContinuar = true;

	do
	{
		ret = Controlador__menu(&puedeContinuar);
	}
	while (puedeContinuar && ret == 0);


	return ret;
}
int doce__test()
{
	return Controlador__partidaTest();
}
