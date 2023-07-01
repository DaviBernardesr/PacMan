#pragma once
#include "Inimigos.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef INIMIGOSINTELIGENTES_H
#define INIMIGOSINTELIGENTES_H

class InimigosInteligentes : public Inimigos
{
public:
	InimigosInteligentes();
	InimigosInteligentes(int, int, ALLEGRO_BITMAP*);

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

	~InimigosInteligentes();

	private:
		float buffX;
		float buffY;

};

#endif