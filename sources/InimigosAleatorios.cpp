#include "D:\Arquivos\UFV\COMP. ORIENTA A OBJETOS\PROJETO PACMAN (OO)\Pacman\headers\InimigosAleatorios.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

InimigosAleatorios::InimigosAleatorios()
{
    inimigo = NULL;

    //Altura e Largura da Sprite
    Altura = 32;
    Largura = 32;

    //Variaveis de Direcao
    Cima = false;
    Direita = false;
    Baixo = false;
    Esquerda = false;

    lado = 0;

    Instrucao = 0;

}

InimigosAleatorios::InimigosAleatorios(int x, int y, ALLEGRO_BITMAP* bmpInimigo):Inimigos(x, y, bmpInimigo)
{
    inimigo = bmpInimigo;

    //Altura e Largura da Sprite
    Altura = 32;
    Largura = 32;

    //Variaveis de Direcao
    Cima = false;
    Direita = false;
    Baixo = false;
    Esquerda = false;

    lado = 0;

    Instrucao = 0;
}

void InimigosAleatorios::SetInimigos(float x, float y, ALLEGRO_BITMAP* bmpInimigo)
{
    inimigo = bmpInimigo;

    Inimigos::SetPosicaoX(x);
    Inimigos::SetPosicaoY(y);
}

void InimigosAleatorios::CalcularPosicaoInimigos() {
    Inimigos::CalcularPosicao();
}

float InimigosAleatorios::GetInimigosX() {
    return Inimigos::GetPosicaoX();
}
float InimigosAleatorios::GetInimigosY() {
    return Inimigos::GetPosicaoY();
}
void InimigosAleatorios::SetInimigosX(float x) {
    Inimigos::SetPosicaoX(x);
}
void InimigosAleatorios::SetInimigosY(float y) {
    Inimigos::SetPosicaoY(y);
}

bool InimigosAleatorios::ColisaoInimigos(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoEntidade(mapa);
}

bool InimigosAleatorios::ColisaoInimigosCima(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoCima(mapa);
}
bool InimigosAleatorios::ColisaoInimigosBaixo(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoBaixo(mapa);
}
bool InimigosAleatorios::ColisaoInimigosDireita(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoDireita(mapa);
}
bool InimigosAleatorios::ColisaoInimigosEsquerda(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoEsquerda(mapa);
}

void InimigosAleatorios::SorteioDirecao(vector<vector<int>>& mapa, float x, float y) {
    int flag = 0;
    int posibilidades = 0;

    int direcoes[4];

    for (int i = 0; i < 4; i++)
    {
        direcoes[i] = 0;
    }


    //Verifica cada pos. que o inimigo pode estar indo.
    if (Esquerda == true)
    {
        //Ele verifica cada pos. possivel de ser assumida, e salva nas possibilidades.
        //Pode assumir estes 3 caminhos, para nao andar para tras.
        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        //Sorteio das direcoes.
        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

    }

    else if (Direita == true)
    {

        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

    }

    else if (Cima == true)
    {

        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

    }

    else if (Baixo == true)
    {

        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

    }


    //Quando o jogo inicia, cai neste else porque esta parado.
    else
    {
        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }


    }
}

//Verifica qual a direcao pode ser liberada sem colisao, verifica se não esta voltando para trás.
void InimigosAleatorios::ComandosInimigos(vector<vector<int>>& mapa) {
    //Cima
    if (Instrucao == ALLEGRO_KEY_UP && ColisaoInimigosCima(mapa) == true && Baixo != true && Cima != true)
    {
        Cima = true;
        Baixo = false;
        Esquerda = false;
        Direita = false;
        lado = 0;
    }
    //Baixo
    if (Instrucao == ALLEGRO_KEY_DOWN && ColisaoInimigosBaixo(mapa) == true && Cima != true && Baixo != true)
    {
        Baixo = true;
        Cima = false;
        Esquerda = false;
        Direita = false;
        lado = 1;
    }
    //Esquerda
    if (Instrucao == ALLEGRO_KEY_LEFT && ColisaoInimigosEsquerda(mapa) == true && Direita != true && Esquerda != true)
    {
        Esquerda = true;
        Cima = false;
        Baixo = false;
        Direita = false;
        lado = 3;
    }
    //Direita
    if (Instrucao == ALLEGRO_KEY_RIGHT && ColisaoInimigosDireita(mapa) == true && Esquerda != true && Direita != true)
    {
        Direita = true;
        Cima = false;
        Baixo = false;
        Esquerda = false;
        lado = 2;
    }
}

//Faz a movimentacao.
void InimigosAleatorios::MovimentacaoInimigos(vector<vector<int>>& mapa, bool status) {

    if (status == false)
    {
        //Executa a movimentacao

        //Movimetacao para Cima
        if (Cima == true && ColisaoInimigosCima(mapa) == true) {
            SetInimigosY(GetInimigosY() - 2.0);
        }

        //Movimentacao para Baixo
        if (Baixo == true && ColisaoInimigosBaixo(mapa) == true) {
            SetInimigosY(GetInimigosY() + 2.0);
        }

        //Movimentacao para Esquerda
        if (Esquerda == true && ColisaoInimigosEsquerda(mapa) == true) {
            SetInimigosX(GetInimigosX() - 2.0);
        }

        //Movimentacao para Direita
        if (Direita == true && ColisaoInimigosDireita(mapa) == true) {
            SetInimigosX(GetInimigosX() + 2.0);
        }
    }
}

void InimigosAleatorios::DesenhaInimigos(int sprite, int tipo) {
    al_draw_bitmap_region(inimigo, lado * Largura, tipo * Altura, Largura, Altura, Inimigos::GetPosicaoX(), Inimigos::GetPosicaoY(), 0);
}


InimigosAleatorios::~InimigosAleatorios()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}


