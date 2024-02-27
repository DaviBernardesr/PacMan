#pragma once
#include "Movimentacao.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef INIMIGOS_H
#define INIMIGOS_H

class Inimigos : public Movimentacao
{
public:
	Inimigos();
	Inimigos(int, int, ALLEGRO_BITMAP*);

	void SetInimigos(float, float, ALLEGRO_BITMAP*);

	void CalcularPosicaoInimigos();

	float GetInimigosX();
	float GetInimigosY();

	void SetInimigosX(float);
	void SetInimigosY(float);

	bool ColisaoInimigos(vector<vector<int>>&);

	bool ColisaoInimigosCima(vector<vector<int>>&);
	bool ColisaoInimigosBaixo(vector<vector<int>>&);
	bool ColisaoInimigosDireita(vector<vector<int>>&);
	bool ColisaoInimigosEsquerda(vector<vector<int>>&);

	virtual void SorteioDirecao(vector<vector<int>>&, float, float);

	void ComandosInimigos(vector<vector<int>>&);
	void MovimentacaoInimigos(vector<vector<int>>&, bool status);

	void DesenhaInimigos(int, int);

	~Inimigos();

protected:
	ALLEGRO_BITMAP* inimigo;

	//Variaveis de Tamanho da Sprite
	int Altura;
	int Largura;

	//Variaveis de Direcao
	bool Cima, Direita, Baixo, Esquerda;
	int lado;

	int Instrucao;
};

#endif