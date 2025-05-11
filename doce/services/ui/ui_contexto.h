#ifndef UI_CONTEXTO_H_INCLUDED
#define UI_CONTEXTO_H_INCLUDED

struct ContextoUI
{
	unsigned cantMano;
	const char** jugadores;
	unsigned cantJugadores;

	char** cartas;
	char* ultimaCarta;
	char* jugadorActual;
};
typedef 	struct ContextoUI 	CtxUI;

#endif // UI_CONTEXTO_H_INCLUDED
