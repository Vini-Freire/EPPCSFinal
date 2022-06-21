#ifndef PERSISTENCIADESERIE_H
#define PERSISTENCIADESERIE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Serie.h"
#include "SerieNormal.h"
#include "SerieTemporal.h"
#include "ErroDeArquivo.h"


using namespace std;


class PersistenciaDeSerie
{
    public:
        PersistenciaDeSerie(string arquivo);
        virtual ~PersistenciaDeSerie();

        Serie* obter(string nome);
        vector<string>* getNomes();
        void inserir(string nome, Serie* s);

    protected:

    private:

        string arquivo;
        vector<Serie*> *series;
        Serie* retorno;
        ifstream input;
        ofstream output;
};

#endif // PERSISTENCIADESERIE_H
