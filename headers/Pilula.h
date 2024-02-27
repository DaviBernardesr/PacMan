#include "allegro5/allegro.h"
#ifndef PILULA_H
#define PILULA_H

class Pilula{
	public:
		Pilula();
		~Pilula();
		void desenha_pilula();
		int getPirulaX()const;
		int getPirulaY()const;
		void setPilula();
		void setPirulaImg(ALLEGRO_BITMAP* Img);
		void setcordenadas(int i, int j);
	private:
		ALLEGRO_BITMAP* pilula;
		int x;
		int y;
};

#endif