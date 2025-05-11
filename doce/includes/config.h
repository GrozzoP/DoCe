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

enum Perfiles{
	HUMANO,
	IA_FACIL,
	IA_NORMAL,
	IA_DIFICIL,

	CANT_PERFILES
};
#define		STRING_PERFILES		((const char*[]){TO_STRING(HUMANO), TO_STRING(IA_FACIL),\
									TO_STRING(IA_NORMAL), TO_STRING(IA_DIFICIL)})
enum Poderes{
	SUMAR_2,
	SUMAR_1,
	RESTAR_1,
	RESTAR_2,
	REP_TURNO,
	ESPEJO,

	CANT_PODERES
};
#define		STRING_PODER		((const char*[]){TO_STRING(SUMAR_2), TO_STRING(SUMAR_1),\
									TO_STRING(RESTAR_1), TO_STRING(RESTAR_2), TO_STRING(REP_TURNO),\
										TO_STRING(ESPEJO)})
#define  	CANT_PODER_CARTA	((unsigned[]){6, 10, 8, 6, 6, 4})


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
