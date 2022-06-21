#include "Serie.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

Serie::Serie(string Nome, string NomeDoCanalX, string NomeDoCanalY){

  this->Nome = Nome;
  this->NomeDoCanalX = NomeDoCanalX;
  this->NomeDoCanalY = NomeDoCanalY;
  Pontos = new vector<Ponto*> ();

}

Serie::~Serie(){

  delete Pontos;

}

string Serie::getNome(){
  return Nome;
}

string Serie::getNomeDoCanalX(){
  return NomeDoCanalX;
}

string Serie::getNomeDoCanalY(){
  return NomeDoCanalY;
}

bool Serie::estaVazia(){
  return (Quantidade == 0) ? true : false;
}

int Serie::getQuantidade(){
  return Quantidade;
}

vector<Ponto*>* Serie::getPontos(){
    return Pontos;
}

void Serie::imprimir(){


  cout << "Serie: " << this->Nome << endl;
  int i;
  for (i = 0; i < Quantidade; i++){
    Pontos->at (i)->imprimir();
  }
}


Ponto* Serie::getLimiteSuperior(){

  if(this->estaVazia())
        throw new runtime_error("Serie sem valores");

  else{

      Ponto* PontoSuperior;
      int i;
      double maiorX, maiorY;
      maiorX = this->Pontos->at (0)->getX();
      maiorY = this->Pontos->at (0)->getY();

  //Encontra os maiores valores de X e Y entre os pontos da serie
      for(i = 1; i < Quantidade; i++){
          if((Pontos->at (i))->getX() > maiorX)
            maiorX = (Pontos->at (i)) ->getX();
          if((Pontos->at (i))->getY() > maiorY)
            maiorY = (Pontos->at (i)) ->getY();
      }
  //Atribui ao Atributo PontoSuperior os valores obtidos
      PontoSuperior = new Ponto(maiorX, maiorY);

    return PontoSuperior;
  }

}

Ponto* Serie::getLimiteInferior(){

  if(this->estaVazia())
        throw new runtime_error("Serie sem valores");

  else{

      Ponto* PontoInferior;
      int i;
      double menorX, menorY;
      menorX = (Pontos->at (0))->getX();
      menorY = (Pontos->at (0))->getY();

  //Encontra os menores valores de X e Y entre os pontos da serie
      for(i = 1; i < Quantidade; i++){

          if((Pontos->at (i)->getX()) <  menorX)
                menorX = Pontos->at (i) ->getX();

          if(Pontos->at (i)->getY() < menorY)
                menorY = (Pontos->at (i)) ->getY();
      }
  //Atribui ao Atributo PontoInferior valores obtidos
      PontoInferior = new Ponto(menorX, menorY);

    return PontoInferior;
  }

}

Ponto* Serie::getPosicao(int posicao){

    if(this->estaVazia() || posicao < 0 || posicao > Quantidade - 1){
        throw new out_of_range("Posicao invalida");
    }

    else return Pontos->at (posicao);

}
