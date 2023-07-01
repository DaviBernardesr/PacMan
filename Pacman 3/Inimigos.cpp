#include "Inimigos.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

Inimigos::Inimigos()
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

Inimigos::Inimigos(int x, int y, ALLEGRO_BITMAP* bmpInimigo) :Movimentacao(x, y)
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

void Inimigos::SetInimigos(float x, float y, ALLEGRO_BITMAP* bmpInimigo)
{
    inimigo = bmpInimigo;

    Movimentacao::SetPosicaoX(x);
    Movimentacao::SetPosicaoY(y);
}

void Inimigos::CalcularPosicaoInimigos() {
    Movimentacao::CalcularPosicao();
}

float Inimigos::GetInimigosX() {
    return Movimentacao::GetPosicaoX();
}
float Inimigos::GetInimigosY() {
    return Movimentacao::GetPosicaoY();
}
void Inimigos::SetInimigosX(float x) {
    Movimentacao::SetPosicaoX(x);
}
void Inimigos::SetInimigosY(float y) {
    Movimentacao::SetPosicaoY(y);
}

bool Inimigos::ColisaoInimigos(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoEntidade(mapa);
}

bool Inimigos::ColisaoInimigosCima(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoCima(mapa);
}
bool Inimigos::ColisaoInimigosBaixo(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoBaixo(mapa);
}
bool Inimigos::ColisaoInimigosDireita(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoDireita(mapa);
}
bool Inimigos::ColisaoInimigosEsquerda(vector<vector<int>>& mapa) {
    return Movimentacao::ColisaoEsquerda(mapa);
}

void Inimigos::SorteioDirecao(vector<vector<int>>& mapa, float x, float y) {
    
}

//Comandos dos inimigos
void Inimigos::ComandosInimigos(vector<vector<int>>& mapa) {
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

void Inimigos::MovimentacaoInimigos(vector<vector<int>>& mapa, bool status) {
    //Executa a movimentacao
    if (status == false)
    {

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

void Inimigos::DesenhaInimigos(int sprite, int tipo) {
    al_draw_bitmap_region(inimigo, lado * Largura, tipo * Altura, Largura, Altura, Movimentacao::GetPosicaoX(), Movimentacao::GetPosicaoY(), 0);
}


Inimigos::~Inimigos()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}