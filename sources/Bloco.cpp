#include "D:\\Arquivos\\UFV\\COMP. ORIENTA A OBJETOS\\PROJETO PACMAN (OO)\\Pacman\\headers\\Bloco.h"
#include "allegro5/allegro.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Bloco::Bloco() {
	bloco = NULL;
	x = 0;
	y = 0;
	if (bloco) {
		printf("Erro no bloco!\n");
	}
}

//Destruir o bloco.
Bloco::~Bloco() {
	al_destroy_bitmap(bloco);

}

//Carrega o bloco.
void Bloco::setBloco() {
	bloco = al_load_bitmap("D:\\Arquivos\\UFV\\COMP. ORIENTA A OBJETOS\\PROJETO PACMAN (OO)\\Pacman\\assets\\images\\bloco.png");
}

void Bloco::desenha_bloco() {
	al_draw_bitmap(bloco, x * 32, y * 32, 0);
 }

void Bloco::setcordenadas(int i, int j){
	x = i;
	y = j;
}