#ifndef EIXODINAMICO_H
#define EIXODINAMICO_H
#include "Eixo.h"
#include "Serie.h"
#include "list"

class EixoDinamico : public Eixo
{
    public:
        /**
        * Cria um EixoDinamico informando o t�tulo, o m�nimo e o m�ximo
        * padr�o, a lista de Series que devem ser consideradas e a orienta��o
        * (true se for horizontal e false se for vertical).
        * @throw runtime_error Caso o minimoPadrao >= maximoPadrao.
        */
        EixoDinamico(string titulo, double minimoPadrao, double maximoPadrao,
                     list<Serie*>* series, bool orientacaoHorizontal);
        virtual ~EixoDinamico();

        virtual double getMinimo();
        virtual double getMaximo();

    protected:
        double maximoEncontrado;
        double minimoEncontrado;
        list<Serie*>* series;

    private:
};

#endif // EIXODINAMICO_H
