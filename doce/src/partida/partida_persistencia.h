#ifndef PARTIDA_PERSISTENCIA_H_INCLUDED
#define PARTIDA_PERSISTENCIA_H_INCLUDED

typedef 	struct JugadaCoord 	JugadaCoord;

void Persistencia__grabarInforme(const char* fileName, JugadaCoord* jugadas);
void Persistencia__leerInforme(const char* fileName);

#endif // PARTIDA_PERSISTENCIA_H_INCLUDED
