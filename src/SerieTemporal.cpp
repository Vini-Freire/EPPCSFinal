#include <iostream>
#include <vector>

#include "SerieTemporal.h"



using namespace std;

SerieTemporal::SerieTemporal(string nome, string nomeDoCanalY) : Serie(nome, "Tempo", nomeDoCanalY){
    tempo = 1.0;
}

SerieTemporal::~SerieTemporal(){
    /*Destructor*/
    cout << "SerieTemporal destruido" << endl;
}

void SerieTemporal::adicionar(double valor){

    novoPonto = new Ponto(tempo++, valor);
    Pontos->push_back(novoPonto);
    delete novoPonto;
}




