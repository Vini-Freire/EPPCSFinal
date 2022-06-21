#include "Grafico.h"
#include <stdexcept>


Grafico::Grafico(Eixo* x, Eixo* y, vector<Serie*>* series){
    this->x = x;
    this->y = y;
    this->series = series;
    if (x->temOrientacaoHorizontal() == false)
        throw new logic_error("Eixo x com orientacao errada");
    if (y->temOrientacaoHorizontal() == true)
        throw new logic_error("Eixo y com orientacao errada");
    if (series == NULL)
        throw new logic_error("Vector series nulo");

}

Grafico::~Grafico(){
    /*Destructor*/
    cout << "Grafico destruido" << endl;
}

Eixo* Grafico::getEixoX(){
    return x;
}

Eixo* Grafico::getEixoY(){
    return y;
}

vector<Serie*>* Grafico::getSeries()
{
    return series;
}


void Grafico::desenhar(){
    int i;

    t = new Tela;
    t->setEixoX(x->getTitulo(), x->getMinimo(), x->getMaximo());
    t->setEixoY(y->getTitulo(), y->getMinimo(), y->getMaximo());

    for (int j = 0; j < series->size(); j++){

        for(i = 0; i < series->at (j)->getQuantidade(); i++){

            t->plotar(series->at (j)->getNome(), series->at (j)->getPontos()->at (i)->getX() , series->at (j)->getPontos()->at (i)->getY());

        }
    }

    t->mostrar();
    delete t;
}
