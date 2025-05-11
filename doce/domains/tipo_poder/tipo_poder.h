#ifndef TIPO_PODER_H_INCLUDED
#define TIPO_PODER_H_INCLUDED

#ifndef CONFIG_H_INCLUDED
#error "Debe incluir config.h antes de tipo_poder.h"
#endif

struct TipoPoder
{
	enum Poderes 	tipo;
};

typedef		struct TipoPoder 	TipoPoder;

#endif // TIPO_PODER_H_INCLUDED
