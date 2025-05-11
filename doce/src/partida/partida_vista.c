
#include	"partida/partida_vista.h"
#include	<stdio.h>
#include	<stddef.h>
#include	<string.h>

unsigned Vista__cantidadJugadores()
{
	return 2;
}
const char* Vista__ingresarNombre()
{
    char buf[128];

    if (fgets(buf, sizeof buf, stdin) == NULL) return NULL;
    buf[strcspn(buf, "\n")] = '\0';
    return strdup(buf);
}

