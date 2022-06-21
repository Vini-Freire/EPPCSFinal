#ifndef GRAFICO_H
#define GRAFICO_H

#include "Tela.h"
#include "Serie.h"
#include "Eixo.h"

class Grafico
{
    public:

    /**
    * Cria um Grafico informando os Eixos e as Series
    * @throw logic_error Caso o eixo x n�o tenha orienta��o horizontal
    * ou o eixo y n�o tenha orienta��o vertical.
    */
        Grafico(Eixo* x, Eixo* y, vector<Serie*>* series);
        virtual ~Grafico();

        Eixo* getEixoX();
        Eixo* getEixoY();
        vector<Serie*>* getSeries();

        /**
        * Desenha o Grafico na Tela.
        */
        void desenhar();

    protected:

    private:
        double maximo;
        double minimo;
        string titulo;
        //string Nome;
        //string NomeDoCanalX;
        //string NomeDoCanalY;
        Eixo* x;
        Eixo* y;
        vector<Serie*>* series;
        //Serie* serie = new Serie(Nome, NomeDoCanalX, NomeDoCanalY);
        Tela* t;
};

#endif // GRAFICO_H
