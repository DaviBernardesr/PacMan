#include "D:\Arquivos\UFV\COMP. ORIENTA A OBJETOS\PROJETO PACMAN (OO)\Pacman FINAL\headers\Movimentacao.h"

Movimentacao::Movimentacao()
{
	//Player
	X = 32;
	Y = 32;

	//Player Matrix
	PlayerColisaoX = 0;
	PlayerColisaoY = 0;

	//Cima
	CimaX = 0;
	CimaY = 0;
	CimaAredondadoX = 0;
	CimaAredondadoY = 0;

	//Baixo
	BaixoX = 0;
	BaixoY = 0;
	BaixoAredondadoX = 0;
	BaixoAredondadoY = 0;

	//Direita
	DireitaX = 0;
	DireitaY = 0;
	DireitaAredondadoX = 0;
	DireitaAredondadoY = 0;

	//Esquerda
	EsquerdaX = 0;
	EsquerdaY = 0;
	EsquerdaAredondadoX = 0;
	EsquerdaAredondadoY = 0;
}

Movimentacao::Movimentacao(int x, int y)
{
	//Player
	X = x;
	Y = y;

	//Player
	PlayerColisaoX = 0;
	PlayerColisaoY = 0;

	//Cima
	CimaX = 0;
	CimaY = 0;
	CimaAredondadoX = 0;
	CimaAredondadoY = 0;

	//Baixo
	BaixoX = 0;
	BaixoY = 0;
	BaixoAredondadoX = 0;
	BaixoAredondadoY = 0;

	//Direita
	DireitaX = 0;
	DireitaY = 0;
	DireitaAredondadoX = 0;
	DireitaAredondadoY = 0;

	//Esquerda
	EsquerdaX = 0;
	EsquerdaY = 0;
	EsquerdaAredondadoX = 0;
	EsquerdaAredondadoY = 0;
}

//Pega a pos. do pacman e divide pelo tamanho dos blocos.
void Movimentacao::CalcularPosicao()
{
	//Player
	PlayerColisaoY = ((Y) / 32);
	PlayerColisaoX = ((X) / 32);

	//Cima

	CimaY = ceil(((Y) / 32));
	CimaX = ((X) / 32);
	CimaAredondadoY = ceil(((Y) / 32));
	CimaAredondadoX = ceil(((X) / 32));

	//Baixo
	BaixoY = (((Y) / 32));
	BaixoX = ceil(((X) / 32));
	BaixoAredondadoY = (((Y) / 32));
	BaixoAredondadoX = (((X) / 32));

	//Direita
	DireitaY = ceil(((Y) / 32));
	DireitaX = ((X) / 32);
	DireitaAredondadoY = ((Y) / 32);
	DireitaAredondadoX = ((X) / 32);

	//Esquerda
	EsquerdaY = ceil(((Y) / 32));
	EsquerdaX = ceil(((X) / 32));
	EsquerdaAredondadoY = ((Y) / 32);
	EsquerdaAredondadoX = ceil(((X) / 32));
}

float Movimentacao::GetPosicaoX()
{
	return X;
}

float Movimentacao::GetPosicaoY()
{
	return Y;
}

void Movimentacao::SetPosicaoX(float x)
{
	X = x;
}

void Movimentacao::SetPosicaoY(float y)
{
	Y = y;
}

int Movimentacao::GetPosicaoXMatriz()
{
	return PlayerColisaoX;
}

int Movimentacao::GetPosicaoYMatriz()
{
	return PlayerColisaoY;
}

//Verifica se o bloco do pacman em cima é parede.
bool Movimentacao::ColisaoEntidade(vector<vector<int>>& mapa)
{
	if (mapa[PlayerColisaoY][PlayerColisaoX] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Verifica um bloco acima do pac man.
bool Movimentacao::ColisaoCima(vector<vector<int>>& mapa)
{
	if (mapa[CimaY - 1][CimaX] != 0 && mapa[CimaAredondadoY - 1][CimaAredondadoX] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Verifica um bloco a baixo do pac man.
bool Movimentacao::ColisaoBaixo(vector<vector<int>>& mapa)
{
	if (mapa[BaixoY + 1][BaixoX] != 0 && mapa[BaixoAredondadoY + 1][BaixoAredondadoX] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Verifica um bloco a direita do pac man.
bool Movimentacao::ColisaoDireita(vector<vector<int>>& mapa)
{
	if (mapa[DireitaY][DireitaX + 1] != 0 && mapa[DireitaAredondadoY][DireitaAredondadoX + 1] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Verifica um bloco a esquerda do pac man.
bool Movimentacao::ColisaoEsquerda(vector<vector<int>>& mapa)
{
	if (mapa[EsquerdaY][EsquerdaX - 1] != 0 && mapa[EsquerdaAredondadoY][EsquerdaAredondadoX - 1] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Movimentacao::~Movimentacao()
{
	//Destrutor.
}



