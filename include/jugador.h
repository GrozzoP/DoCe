#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#define TAM_CAD 50

typedef struct {
   char nombre[TAM_CAD];
   int esIA;
   int puntajeAcumulado;
   // Faltaria el tMano
} tJugador;

#endif // JUGADOR_H_INCLUDED
