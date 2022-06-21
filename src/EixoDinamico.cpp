#include "EixoDinamico.h"
#include "Serie.h"
#include "iostream"
#include "stdexcept"

using namespace std;


EixoDinamico::EixoDinamico(string titulo, double minimoPadrao, double maximoPadrao, list<Serie*>* series, bool orientacaoHorizontal) :
    Eixo(titulo, minimoPadrao, maximoPadrao, orientacaoHorizontal)
{
    this->series = series;

    if (minimoPadrao >= maximoPadrao)
        throw new runtime_error("MinimoPadrao maior que o MaximoPadrao");
    if (series == NULL)
        throw new logic_error("Lista de Series nula");

    double maximoEncontrado;
    double minimoEncontrado;

    list<Serie*>::iterator iter;
    try{
        iter = series->begin();
        if (orientacaoHorizontal == true){
            maximoEncontrado = (*iter)->getLimiteSuperior()->getX();
            for (iter = series->begin(); iter != series->end(); iter++)
                if(maximoEncontrado < (*iter)->getLimiteSuperior()->getX())
                    maximoEncontrado = (*iter)->getLimiteSuperior()->getX();

        }
        else if (orientacaoHorizontal == false){
            maximoEncontrado = (*iter)->getLimiteSuperior()->getY();
            for (iter = series->begin(); iter != series->end(); iter++)
                if(maximoEncontrado < (*iter)->getLimiteSuperior()->getY())
                    maximoEncontrado = (*iter)->getLimiteSuperior()->getY();
        }

        iter = series->begin();
        if (orientacaoHorizontal == true){
            minimoEncontrado = (*iter)->getLimiteInferior()->getX();
            for (iter = series->begin(); iter != series->end(); iter++)
                if(minimoEncontrado < (*iter)->getLimiteInferior()->getX())
                    minimoEncontrado = (*iter)->getLimiteInferior()->getX();
        }
        else if (orientacaoHorizontal == false){
            minimoEncontrado = (*iter)->getLimiteInferior()->getY();
            for (iter = series->begin(); iter != series->end(); iter++)
                if(minimoEncontrado < (*iter)->getLimiteInferior()->getY())
                    minimoEncontrado = (*iter)->getLimiteInferior()->getY();
        }

    } catch(runtime_error* e){
        cout << e->what();
    }

}

double EixoDinamico::getMaximo(){
    if (((maximoEncontrado - minimoEncontrado) <= 1e-5 && (maximoEncontrado - minimoEncontrado) >= -1e-5) || ((minimoEncontrado - maximoEncontrado) <= 1e-5 && (minimoEncontrado - maximoEncontrado) >= -1e-5))
        return maximo;
    return maximoEncontrado;

}

double EixoDinamico::getMinimo(){
    if (((maximoEncontrado - minimoEncontrado) <= 1e-5 && (maximoEncontrado - minimoEncontrado) >= -1e-5) || ((minimoEncontrado - maximoEncontrado) <= 1e-5 && (minimoEncontrado - maximoEncontrado) >= -1e-5))
        return minimo;
    return minimoEncontrado;
}


EixoDinamico::~EixoDinamico()
{
    cout << "EixoDinamico destruido" << endl;
}

