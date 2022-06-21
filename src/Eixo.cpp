#include "Eixo.h"
#include "iostream"
#include "stdexcept"
using namespace std;

Eixo::Eixo(string titulo, double minimo, double maximo, bool orientacaoHorizontal)
{
    this->titulo = titulo;
    this->minimo = minimo;
    this->maximo = maximo;
    this->orientacaoHorizontal = orientacaoHorizontal;

    if (minimo >= maximo)
        throw new runtime_error("Minimo maior que o maximo");
}

Eixo::~Eixo()
{
    cout << "Eixo Destruido" << endl;
}

string Eixo::getTitulo()
{
    return titulo;
}

double Eixo::getMinimo()
{
    return minimo;
}

double Eixo::getMaximo()
{
    return maximo;
}

bool Eixo::temOrientacaoHorizontal()
{
    return orientacaoHorizontal;
}
