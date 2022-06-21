#include "EixoEstatico.h"
#include "iostream"

EixoEstatico::EixoEstatico(string titulo, double minimo, double maximo, bool orientacaoHorizontal):
     Eixo(titulo, minimo, maximo, orientacaoHorizontal)
{

}

EixoEstatico::~EixoEstatico()
{
    cout << "EixoEstatico destruido" << endl;
}
