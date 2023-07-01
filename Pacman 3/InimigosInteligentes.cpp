#include "InimigosInteligentes.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

InimigosInteligentes::InimigosInteligentes()
{
    buffX = 0;
    buffY = 0;
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

InimigosInteligentes::InimigosInteligentes(int x, int y, ALLEGRO_BITMAP* bmpInimigo) :Inimigos(x, y, bmpInimigo)
{
    buffX = 0;
    buffY = 0;

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

void InimigosInteligentes::SetInimigos(float x, float y, ALLEGRO_BITMAP* bmpInimigo)
{
    inimigo = bmpInimigo;

    Inimigos::SetPosicaoX(x);
    Inimigos::SetPosicaoY(y);
}

void InimigosInteligentes::CalcularPosicaoInimigos() {
    Inimigos::CalcularPosicao();
}

float InimigosInteligentes::GetInimigosX() {
    return Inimigos::GetPosicaoX();
}
float InimigosInteligentes::GetInimigosY() {
    return Inimigos::GetPosicaoY();
}
void InimigosInteligentes::SetInimigosX(float x) {
    Inimigos::SetPosicaoX(x);
}
void InimigosInteligentes::SetInimigosY(float y) {
    Inimigos::SetPosicaoY(y);
}

bool InimigosInteligentes::ColisaoInimigos(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoEntidade(mapa);
}

bool InimigosInteligentes::ColisaoInimigosCima(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoCima(mapa);
}
bool InimigosInteligentes::ColisaoInimigosBaixo(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoBaixo(mapa);
}
bool InimigosInteligentes::ColisaoInimigosDireita(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoDireita(mapa);
}
bool InimigosInteligentes::ColisaoInimigosEsquerda(vector<vector<int>>& mapa) {
    return Inimigos::ColisaoEsquerda(mapa);
}

void InimigosInteligentes::SorteioDirecao(vector<vector<int>>& mapa, float x, float y) {
    int direcoes[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };

    int distanciaPacmanX = x - GetInimigosX();
    int distanciaPacmanY = y - GetInimigosY();

    if (distanciaPacmanX < distanciaPacmanY)
    {
        if (distanciaPacmanX > 0)
        {
            Instrucao = direcoes[1];
        }
        else if (distanciaPacmanX >= 0)
        {
            if (distanciaPacmanY >= 0)
            {
                Instrucao = direcoes[3];
            }
            else
            {
                Instrucao = direcoes[2];
            }
        }
        else
        {
            Instrucao = direcoes[0];
        }
    }
    else
    {
        if (distanciaPacmanY > 0)
        {
            Instrucao = direcoes[3];
        }
        else if (distanciaPacmanY == 0)
        {
            if (distanciaPacmanX >= 0)
            {
                Instrucao = direcoes[1];
            }
            else
            {
                Instrucao = direcoes[0];
            }
        }
        else
        {
            Instrucao = direcoes[2];
        }
    }

    if (buffX == GetInimigosX() && buffY == GetInimigosY())
    {

        int flag = 0;
        int posibilidades = 0;

        int direcoes[4];

        for (int i = 0; i < 4; i++)
        {
            direcoes[i] = 0;
        }

        if (Esquerda == true)
        {

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

    buffX = GetInimigosX();
    buffY = GetInimigosY();

}

void InimigosInteligentes::ComandosInimigos(vector<vector<int>>& mapa) {
    Inimigos::ComandosInimigos(mapa);
}

void InimigosInteligentes::MovimentacaoInimigos(vector<vector<int>>& mapa, bool status) {
    Inimigos::MovimentacaoInimigos(mapa, status);
}

void InimigosInteligentes::DesenhaInimigos(int sprite, int tipo) {
    Inimigos::DesenhaInimigos(sprite, tipo);
}


InimigosInteligentes::~InimigosInteligentes()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}