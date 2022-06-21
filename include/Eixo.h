#ifndef EIXO_H
#define EIXO_H
#include "string"
using namespace std;

class Eixo
{
    public:

        /**
        * Cria um Eixo informando o título, o mínimo, o máximo e
        * a orientação (true se for horizontal e false se for vertical).
        * @throw runtime_error Caso o minimo >= maximo.
        */
        Eixo( string titulo, double minimo, double maximo, bool orientacaoHorizontal);
        virtual ~Eixo() = 0;

        virtual string getTitulo();
        virtual double getMinimo();
        virtual double getMaximo();
        virtual bool temOrientacaoHorizontal();

    protected:
        string titulo;
        double minimo;
        double maximo;
        bool orientacaoHorizontal;
    private:
};

#endif // EIXO_H
