#include "SerieNormal.h"


SerieNormal::SerieNormal(string nome, string nomeDoCanalX, string nomeDoCanalY) :
    Serie(nome, nomeDoCanalX, nomeDoCanalY)
{
    // Constructor
}

SerieNormal::~SerieNormal()
{
    // Destructor
    cout << "SerieNormal destruida" << endl;
}


void SerieNormal::adicionar(double x, double y)
{
    novoPonto = new Ponto(x, y);
    Pontos->push_back(novoPonto);
    Quantidade++;
    delete novoPonto;
}
