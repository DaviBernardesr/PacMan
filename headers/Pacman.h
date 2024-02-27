#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include <vector>
#include <cmath>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "Movimentacao.h"

using namespace std;

class Pacman : public Movimentacao {
public:
	Pacman();
	~Pacman();
    void PosicaoPacman();

    bool ColisaoPacman(vector<vector<int>>&);

    void PacmanPegaPirula(vector<vector<int>>&);
    int getPlacar();

    bool ColisaoPacmanCima(vector<vector<int>>&);
    bool ColisaoPacmanBaixo(vector<vector<int>>&);
    bool ColisaoPacmanDireita(vector<vector<int>>&);
    bool ColisaoPacmanEsquerda(vector<vector<int>>&);

    int getPacmanXMatriz();
    int getPacmanYMatriz();

    float getPacmanX();
    float getPacmanY();

    void setPacmanX(float);
    void setPacmanY(float);

    void setPacman(ALLEGRO_BITMAP*, int, int);

    void ComandosPacman(int, vector<vector<int>>&);
    void MovimentacaoPacman(vector<vector<int>>&);

    void DesenhaPacman(int);

private:
    ALLEGRO_BITMAP* PacmanBMP;

	float X;
	float Y;

    //Player Matriz
    int PlayerColisaoX;
    int PlayerColisaoY;

    //Cima
    int CimaX, CimaY;
    int CimaAredondadoX, CimaAredondadoY;

    //Baixo
    int BaixoX, BaixoY;
    int BaixoAredondadoX, BaixoAredondadoY;

    //Direita
    int DireitaX, DireitaY;
    int DireitaAredondadoX, DireitaAredondadoY;

    //Esquerda
    int EsquerdaX, EsquerdaY;
    int EsquerdaAredondadoX, EsquerdaAredondadoY;

    int Placar;

    //Altura e Largura
    int PacmanAltura;
    int PacmanLargura;

    // Direcoes
    bool up;
    bool down;
    bool right;
    bool left;

    //Lado
    int lado;
};

#endif