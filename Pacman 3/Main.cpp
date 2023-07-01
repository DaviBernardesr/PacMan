#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"//Biblioteca de Fonte
#include "allegro5/allegro_ttf.h"//Biblioteca de Texto
#include "Pilula.h"
#include "Bloco.h"
#include "Pacman.h"
#include "InimigosAleatorios.h"
#include "Inimigos.h"
#include "InimigosInteligentes.h"

const float FPS = 60;

using namespace std;


int main() {

	int i;
	int j;

	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();//Iniciando Addon de Fontes
	al_init_ttf_addon();//Iniciando Addon de Texto
	

	vector<vector<int>> matriz = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0},
		{0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,1,1,0},
		{0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0},
		{0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,0},
		{0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0},
		{0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0},
		{0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0},
		{0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0},
	};

	//Def. das variaveis do Allegro.
	ALLEGRO_DISPLAY* display = al_create_display(576, 512);
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_FONT* Fonte = al_load_font("Roboto-Regular.ttf", 30, 0); //Crição de Variavel de Fonte

	//Def. das variaveis lógicas do programa.
	bool done = false;
	bool redraw = true;

	int cont1 = 0;
	int cont2 = 0;

	//Vetor de Teclas
	bool teclas[255] = { false };

	//Variaveis de Tempo
	int sprite = 0, fator = 1;
	int tempo, miliseg = 200;

	//Variavel para armazenar comando do teclado
	int proximaIntrucao = 0;


	//Registra os comandos no teclado, display e tela.
	al_register_event_source(queue, al_get_keyboard_event_source()); 
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));


	//Def. a quantidade de blocos e pilulas.
	Bloco* b = new Bloco[147];
	Pilula* p = new Pilula[130];
	Pacman pacman;
	
	ALLEGRO_BITMAP* bmpPacman = al_load_bitmap("pacman.png");

	ALLEGRO_BITMAP* bmpInimigos = al_load_bitmap("InimigosT.png");

	ALLEGRO_BITMAP* bmpfundo = al_load_bitmap("fundo.png");

	//Spawn do pacman.
	pacman.setPacman(bmpPacman, 288,226);


	Inimigos* vector[4];
	InimigosAleatorios inimigo1, inimigo2, inimigo3;
	InimigosInteligentes inimigo4;
	vector[0] = &inimigo1;
	vector[1] = &inimigo2;
	vector[2] = &inimigo3;
	vector[3] = &inimigo4;

	vector[0]->SetInimigos(64, 420, bmpInimigos);
	vector[1]->SetInimigos(288, 420, bmpInimigos);
	vector[2]->SetInimigos(420, 420, bmpInimigos);
	vector[3]->SetInimigos(288, 420, bmpInimigos);


	for (i =0; i <16; i++) {
		for (j = 0; j <18; j++) {
			if (matriz[i][j] == 0) {
				b[cont1].setBloco();
				b[cont1].setcordenadas(j, i);
				cont1++;
			}
			else if(matriz[i][j] == 1){
				p[cont2].setPilula();
				p[cont2].setcordenadas(j, i);
				cont2++;
			}
		}
	}

	//Inicia o timer.
	al_start_timer(timer);

	bool jogo = true;

	//LOOP Principal do jogo (onde o jogo roda).
	while (jogo) {

		pacman.PosicaoPacman();
		pacman.PacmanPegaPirula(matriz);


		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);
		//al_wait_for_event(queue, &event);
		tempo = al_get_timer_count(timer);//Inicianlizando a variavel tempo

		if (ev.type == ALLEGRO_EVENT_TIMER) {


			//Timer para trocar de bitmap
			if (tempo == ((60 * miliseg) / 1000) || tempo > ((60 * miliseg) / 1000)) {
				al_set_timer_count(timer, 0);
				sprite = sprite + fator;
				if (sprite == 0) fator = 1;
				if (sprite == 2) fator = -1;
			}


			for (int i = 0; i < 4; i++)
			{
				vector[i]->CalcularPosicao();
				vector[i]->SorteioDirecao(matriz, pacman.getPacmanX(), pacman.getPacmanY());

				vector[i]->ComandosInimigos(matriz);
				vector[i]->MovimentacaoInimigos(matriz, false);
			}

			//Recebe o comando do teclado

			if (teclas[ALLEGRO_KEY_UP])
			{
				proximaIntrucao = ALLEGRO_KEY_UP;
			}
			if (teclas[ALLEGRO_KEY_DOWN])
			{
				proximaIntrucao = ALLEGRO_KEY_DOWN;
			}
			if (teclas[ALLEGRO_KEY_LEFT])
			{
				proximaIntrucao = ALLEGRO_KEY_LEFT;
			}
			if (teclas[ALLEGRO_KEY_RIGHT])
			{
				proximaIntrucao = ALLEGRO_KEY_RIGHT;

			}

			pacman.ComandosPacman(proximaIntrucao, matriz);
			pacman.MovimentacaoPacman(matriz);

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			redraw = false;
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			teclas[ev.keyboard.keycode] = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			teclas[ev.keyboard.keycode] = false;

		}

		if (redraw && al_is_event_queue_empty(queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 129; i++) {
				p[i].desenha_pilula();
				if (pacman.getPacmanXMatriz() == p[i].getPirulaX() && pacman.getPacmanYMatriz() == p[i].getPirulaY())
				{
					p[i].setPirulaImg(bmpfundo);
				}
			}
			for (int i = 0; i < 147; i++) {
				b[i].desenha_bloco();
			}
			

			pacman.DesenhaPacman(sprite);

			for (int i = 0; i < 4; i++)
			{
				vector[i]->DesenhaInimigos(0, i);
			}

			//Desenha o texto de Score na Tela.
			al_draw_textf(Fonte, al_map_rgb(200, 0, 0), 119, 480, 0, "SOBREVIVA!!! PLACAR: %d", pacman.getPlacar());

			al_flip_display();
			redraw = false;
		}

		//Verifica a batida do boneco com inimigo.
		for (int i = 0; i < 4; i++)
		{
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() && pacman.getPacmanY() == vector[i]->GetInimigosY())
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() + 2 && pacman.getPacmanY() == vector[i]->GetInimigosY())
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() - 2 && pacman.getPacmanY() == vector[i]->GetInimigosY())
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() && pacman.getPacmanY() == vector[i]->GetInimigosY() + 2)
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() && pacman.getPacmanY() == vector[i]->GetInimigosY() - 2)
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() + 2 && pacman.getPacmanY() == vector[i]->GetInimigosY() + 2)
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() - 2 && pacman.getPacmanY() == vector[i]->GetInimigosY() + 2)
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() - 2 && pacman.getPacmanY() == vector[i]->GetInimigosY() - 2)
			{
				jogo = false;
			}
			if (pacman.getPacmanX() == vector[i]->GetInimigosX() + 2 && pacman.getPacmanY() == vector[i]->GetInimigosY() - 2)
			{
				jogo = false;
			}
		}


	}

	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	al_destroy_display(display);

	return 0;
}