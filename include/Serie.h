#ifndef SERIE_H
#define SERIE_H

#include <string>
#include "Ponto.h"
#include <iostream>
#include <vector>

using namespace std;

class Serie {
public:

  Serie(string Nome, string NomeDoCanalX, string NomeDoCanalY);

  // Faça o destrutor ser abstrato (puramente virtual)
  virtual ~Serie() = 0;

  // Permite obter o nome, o nomeDoCanalX e o nomeDoCanalY.
  virtual string getNome();
  virtual string getNomeDoCanalX();
  virtual string getNomeDoCanalY();

  virtual int getQuantidade();
  virtual bool estaVazia();
  virtual vector<Ponto*>* getPontos();
  virtual void imprimir();
  virtual Ponto* getLimiteInferior();
  virtual Ponto* getLimiteSuperior();
  virtual Ponto* getPosicao(int posicao);

protected:

    vector<Ponto*>* Pontos;
    string Nome;
    string NomeDoCanalX;
    string NomeDoCanalY;
    int Quantidade = 0;
    bool Normal;




};

#endif // SERIE_H


