#include "allegro5/allegro.h"
#ifndef BLOCO_H
#define BLOCO_H

class Bloco{
	public:
		Bloco();
		~Bloco();
		void desenha_bloco();
		void setBloco();
		void setcordenadas(int i, int j);
	private:
		ALLEGRO_BITMAP* bloco;
		int x;
		int y;
};

#endif