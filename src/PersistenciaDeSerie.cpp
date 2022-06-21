#include "PersistenciaDeSerie.h"



PersistenciaDeSerie::PersistenciaDeSerie(string arquivo)
{
    int Qtde, tipo;
    string nome, nomeX, nomeY;
    double x, y;
    series = new vector<Serie*>();

    this->arquivo = arquivo;
    input.open(arquivo);


    while(!input.eof()){

        input >> nome;

        if (nome == "") break;

        input >> tipo;

        if (input.eof()) break;

        input >> Qtde;

        if(input.fail())
                throw new ErroDeArquivo("Falha na leitura");

        if(tipo == 1){

            input >> nomeX;
            input >> nomeY;

            if(input.fail())
                    throw new ErroDeArquivo("Falha na leitura");

            SerieNormal* s = new SerieNormal(nome, nomeX, nomeY);

            for(int i = 0; i < Qtde; i++){

                input >> x;
                input >> y;

                if(input.fail())
                    throw new ErroDeArquivo("Falha na leitura");

                s->adicionar(x, y);
            }
            series->push_back(s);
            s->imprimir();

        }
        else{
            input >> nomeY;

            if(input.fail())
                    throw new ErroDeArquivo("Falha na leitura");

            SerieTemporal *s = new SerieTemporal(nome, nomeY);

            for(int i = 0; i < Qtde; i++){

                input >> y;

                if(input.fail())
                    throw new ErroDeArquivo("Falha na leitura");

                s->adicionar(y);
            }
            series->push_back(s);
        }
    }

    input.close();

}

PersistenciaDeSerie::~PersistenciaDeSerie()
{
    unsigned int i;

    for(i = 0; i < series->size(); i++)
        delete series->at(i);

    delete series;
}

Serie* PersistenciaDeSerie::obter(string nome)
{
    unsigned int i;

    for(i = 0; i < series->size() ; i++){
        if((series->at (i))->getNome() == nome)
                return series->at(i);
    }

    return NULL;

}

void PersistenciaDeSerie::inserir(string nome, Serie* s)
{
    unsigned int i;
    for(i = 0; i < series->size(); i++){
        if((series->at(i))->getNome() == nome)
            throw new ErroDeArquivo("Nome ja existente");
    }

    output.open(arquivo, ios_base::app);

    if(output.fail())
        throw new ErroDeArquivo("Erro ao escrever");
    else
        output << nome << "\n";

    /* Verifica se a Serie é normal */
    if(SerieNormal *e = dynamic_cast<SerieNormal*> (s)){ // Retorna True caso efetivo

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << "1" << "\n";

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << e->getQuantidade() << "\n";

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << e->getNomeDoCanalX() << "\n";

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << e->getNomeDoCanalY() << "\n";

        for(int i = 0; i < e->getQuantidade() ; i++){

            if(output.fail())
                throw new ErroDeArquivo("Erro ao escrever");
            else
                output << (e->getPosicao(i))->getX() << "\n";

            if(output.fail())
                throw new ErroDeArquivo("Erro ao escrever");
            else
                output << (e->getPosicao(i))->getY() << "\n";
        }
        delete e;

    }

    else{

        SerieTemporal* d = dynamic_cast<SerieTemporal*>(s);

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << "0";

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << d->getQuantidade();

        if(output.fail())
            throw new ErroDeArquivo ("Erro ao escrever");
        else
            output << d->getNomeDoCanalY();

        for(int i = 0; i < d->getQuantidade(); i++){
            if(output.fail())
                throw new ErroDeArquivo("Erro ao escrever");
            else
                output << (d->getPosicao(i))->getY();
        }
        delete d;

    }

    output.close();

}

vector<string>* PersistenciaDeSerie::getNomes()
{
    vector<string> *nomes = new vector<string>();
    unsigned int i;


    for(i = 0; i < series->size(); i++){
        nomes->push_back((series->at(i))->getNome());
    }

    return nomes;
}
