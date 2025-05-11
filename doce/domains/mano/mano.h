#ifndef MANO_H_INCLUDED
#define MANO_H_INCLUDED

#ifndef CONFIG_H_INCLUDED
#error "Debe incluir config.h antes de mano.h"
#endif
#include 	"carta/carta_publico.h"

typedef		Carta* Mano[CANT_MANO];

#endif // MANO_H_INCLUDED
