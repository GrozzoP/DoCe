# DoCe
=================

recordar que en "includes/config.h"  hay varios datos importantes por ejemplo

enum Poderes{
	SUMAR_2,
	SUMAR_1,
	RESTAR_1,
	RESTAR_2,
	REP_TURNO,
	ESPEJO,
 	CANT_PODERES
};
__attribute__((unused)) static const char* STRING_PODER[] = {
    TO_STRING(SUMAR_2),
    TO_STRING(SUMAR_1),
    TO_STRING(RESTAR_1),
    TO_STRING(RESTAR_2),
    TO_STRING(REP_TURNO),
    TO_STRING(ESPEJO)
};

entonces podemos hacer 
STRING_PODER[SUMAR_2]; y nos da "SUMAR_2" lo cual es util para las vistas
