#ifndef SERIETEMPORAL_H
#define SERIETEMPORAL_H
#include "Serie.h"
#include "Ponto.h"

class SerieTemporal : public Serie
{
    public:

        SerieTemporal(string nome, string nomeDoCanalY);
        virtual ~SerieTemporal();

        virtual void adicionar (double valor);

    protected:

    private:
        double tempo;
        Ponto* novoPonto;
};

#endif // SERIETEMPORAL_H
