#include <iostream>
#include <vector>

#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

using namespace std;

class Movimentacao
{
public:
    Movimentacao();
    Movimentacao(int, int);

    void CalcularPosicao();

    float GetPosicaoX();
    float GetPosicaoY();

    void SetPosicaoX(float x);
    void SetPosicaoY(float y);

    int GetPosicaoXMatriz();
    int GetPosicaoYMatriz();

    bool ColisaoEntidade(vector<vector<int>>& mapa);

    bool ColisaoCima(vector<vector<int>>& mapa);
    bool ColisaoBaixo(vector<vector<int>>& mapa);
    bool ColisaoDireita(vector<vector<int>>& mapa);
    bool ColisaoEsquerda(vector<vector<int>>& mapa);

    ~Movimentacao();

private:
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
};
#endif