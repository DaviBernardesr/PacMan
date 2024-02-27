#include "D:\Arquivos\UFV\COMP. ORIENTA A OBJETOS\PROJETO PACMAN (OO)\Pacman FINAL\headers\Pilula.h"
#include "allegro5/allegro.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Pilula::Pilula() {
	pilula = NULL;
	x = 0;
	y = 0;
	if (pilula) {
		printf("Erro no bloco!\n");
	}
}

//Destruir a pilula.
Pilula::~Pilula() {
	al_destroy_bitmap(pilula);

}

int Pilula::getPirulaX()const
{
	return x;
}

int Pilula::getPirulaY()const
{
	return y;
}

//Carrega a pilula.
void Pilula::setPilula() {
	pilula = al_load_bitmap("pilula.png");
}

void Pilula::setPirulaImg(ALLEGRO_BITMAP* Bmp)
{
	pilula = Bmp;
}

void Pilula::desenha_pilula() {
	al_draw_bitmap(pilula, x * 32, y * 32, 0);
}

void Pilula::setcordenadas(int i, int j) {
	x = i;
	y = j;
}