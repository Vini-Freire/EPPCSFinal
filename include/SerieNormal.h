#ifndef SERIENORMAL_H
#define SERIENORMAL_H

#include "Serie.h"



class SerieNormal : public Serie
{
    public:
        SerieNormal(string nome, string nomeDoCanalX, string nomeDoCanalY);
        virtual ~SerieNormal();
        /**
        * Adiciona um novo ponto à Serie, informando sua coordenada x e y.
        */
        virtual void adicionar(double x, double y);

    protected:

    private:
        //Atributo usado para adicionar pontos ao Vector
        Ponto* novoPonto;
};

#endif // SERIENORMAL_H
