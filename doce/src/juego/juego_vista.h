#ifndef JUEGO_VISTA_H_INCLUDED
#define JUEGO_VISTA_H_INCLUDED

typedef 	struct ContextoUI 	CtxUI;

char Vista__selecionarCarta();
void Vista__mostrarPartida(const CtxUI* ctx);
void Vista__mostrarJugador(char* jugador);
void Vista__mostrarGanador(char* ganador);

#endif // JUEGO_VISTA_H_INCLUDED
