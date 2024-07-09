#include "D:\\Arquivos\\UFV\\COMP. ORIENTA A OBJETOS\\PROJETO PACMAN (OO)\\Pacman\\headers\\Pacman.h"
#include "allegro5/allegro.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>


using namespace std;

Pacman::Pacman()
{
    Placar = 0;

    //Altura e Largura
    PacmanAltura = 32;
    PacmanLargura = 32;

    //Direçoes
    up = false;
    right = false;
    down = false;
    left = false;

    //Lado
    lado = 0;

}

void Pacman::PosicaoPacman() {
    Movimentacao::CalcularPosicao();
}

bool Pacman::ColisaoPacman(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoEntidade(mapa);
}

//Pega e some a pilula.
void Pacman::PacmanPegaPirula(vector<vector<int>>& mapa) {
    if (mapa[getPacmanYMatriz()][getPacmanXMatriz()] == 1)
    {
        mapa[getPacmanYMatriz()][getPacmanXMatriz()] = 2;
        Placar++;
    }

}

int Pacman::getPlacar() {
    return Placar;
}

bool Pacman::ColisaoPacmanCima(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoCima(mapa);
}
bool Pacman::ColisaoPacmanBaixo(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoBaixo(mapa);
}
bool Pacman::ColisaoPacmanDireita(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoDireita(mapa);
}
bool Pacman::ColisaoPacmanEsquerda(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoEsquerda(mapa);
}

int Pacman::getPacmanXMatriz() {
    return Movimentacao::GetPosicaoXMatriz();
}
int Pacman::getPacmanYMatriz() {
    return Movimentacao::GetPosicaoYMatriz();
}

float Pacman::getPacmanX() {
    return Movimentacao::GetPosicaoX();
}
float Pacman::getPacmanY() {
    return Movimentacao::GetPosicaoY();
}
void Pacman::setPacmanX(float CorX) {
    return Movimentacao::SetPosicaoX(CorX);;
}
void Pacman::setPacmanY(float CorY) {
    return Movimentacao::SetPosicaoY(CorY);
}

void Pacman::setPacman(ALLEGRO_BITMAP* BMP,int CorX,int CorY) {
    PacmanBMP = BMP;
    
    X = CorX;
    Y = CorY;
    //X = 288;
    //Y = 224;
}

//Recebe a tecla da main, e verifica oque tem em cima.
void Pacman::ComandosPacman(int Comando, vector<vector<int>>& mapa) {
    // Cima
    if (Comando == ALLEGRO_KEY_UP && ColisaoPacmanCima(mapa) == true)
    {
        up = true;
        down = false;
        right = false;
        left = false;

        //sprite.
        lado = 3;
    }
    
    //Recebe a tecla da main, e verifica oque tem em baixo.
    //Baixo
    if (Comando == ALLEGRO_KEY_DOWN && ColisaoPacmanBaixo(mapa) == true)
    {
        up = false;
        down = true;
        right = false;
        left = false;

        lado = 1;
    }

    //Recebe a tecla da main, e verifica oque tem em cima.
    //Direita
    if (Comando == ALLEGRO_KEY_RIGHT && ColisaoPacmanDireita(mapa) == true)
    {
        up = false;
        down = false;
        right = true;
        left = false;

        lado = 0;
    }

    //Recebe a tecla da main, e verifica oque tem em esquerda.
    //Esquerda
    if (Comando == ALLEGRO_KEY_LEFT && ColisaoPacmanEsquerda(mapa) == true)
    {
        up = false;
        down = false;
        right = false;
        left = true;

        lado = 2;
    }
}

//Faz a andar do pacman realmente.
void Pacman::MovimentacaoPacman(vector<vector<int>>& mapa) {

    //Movimentação

    // Cima
    if (up == true && ColisaoPacmanCima(mapa) == true)
    {
        setPacmanY(getPacmanY() - 2.0);
    }
    //Baixo
    if (down == true && ColisaoPacmanBaixo(mapa) == true)
    {
        setPacmanY(getPacmanY() + 2.0);
    }
    //Direita
    if (right == true && ColisaoPacmanDireita(mapa) == true)
    {
        setPacmanX(getPacmanX() + 2.0);
    }
    //Esquerda
    if (left == true && ColisaoPacmanEsquerda(mapa) == true)
    {
        setPacmanX(getPacmanX() - 2.0);
    }
}

void Pacman::DesenhaPacman(int sprite) {
    al_draw_bitmap_region(PacmanBMP, lado * PacmanLargura, sprite * PacmanAltura, PacmanLargura, PacmanAltura, getPacmanX(), getPacmanY(), 0);
}

Pacman::~Pacman() {
	//al_destroy_bitmap(PacmanBMP);
}