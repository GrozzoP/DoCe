#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define		TO_STRING(X)	#X

#define		COD_GRUPO	"handler"
#define		PREFIX		"informe-juego_"
#define		EXTENSION 	".txt"


#define 	CANT_JUGADORES 	2
#define		CANT_MANO 		3
#define		CANT_MAZO		40
#define		CANT_PUNTOS		12
/*
enum Perfiles{
	IA_FACIL,
	IA_NORMAL,
	IA_DIFICIL,

	CANT_PERFILES
};*/
__attribute__((unused)) static const char* STRING_PERFILES[] = {
	TO_STRING(IA_FACIL),
	TO_STRING(IA_NORMAL),
	TO_STRING(IA_DIFICIL)
};


/*
enum Poderes{
	SUMAR_2,
	SUMAR_1,
	RESTAR_1,
	RESTAR_2,
	REPETIR_TURNO,
	ESPEJO,

	CANT_PODERES
};*/
__attribute__((unused)) static const char* STRING_PODER[] = {
    TO_STRING(RESTAR_2),
    TO_STRING(RESTAR_1),
    TO_STRING(SUMAR_1),
    TO_STRING(SUMAR_2),
    TO_STRING(REPETIR_TURNO),
    TO_STRING(ESPEJO)
};
__attribute__((unused)) static int CANT_PODER_CARTA[] = {
	6,
	8,
	10,
	6,
	6,
	4
};


#define		TITULO			("--- Bienvenido a DoCe ---")
enum Menu{
    JUGAR = 'A',
    VER_RANKING = 'B',
    SALIR = 'C',

    CANT_OPCNES = 3
};
#define		MENSAJES		((const char*[]){TO_STRING(JUGAR), TO_STRING(VER_RANKING), TO_STRING(SALIR)})
#define		OPCIONES 		((const char[]){JUGAR, VER_RANKING, SALIR})

#undef		TO_STRING


#endif // CONFIG_H_INCLUDED
