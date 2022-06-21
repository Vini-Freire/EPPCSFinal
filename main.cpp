#include <iostream>
#include <string>

#include "Ponto.h"
#include "InterfaceSerial.h"
#include "Serie.h"
#include "SerieNormal.h"
#include "SerieTemporal.h"
#include "Eixo.h"
#include "EixoDinamico.h"
#include "EixoEstatico.h"
#include "Grafico.h"
#include "ErroDeArquivo.h"
#include "Tela.h"
#include "PersistenciaDeSerie.h"

#define COMM "\\\\.\\COM3"

using namespace std;

int main() {

    vector<string>*nomes = new vector<string>();

    int tamanho;
    int escolha;
    Grafico* graphic;
    Eixo *X;
    Eixo *Y;
    SerieNormal *ser1;
    SerieTemporal *ser2;
    InterfaceSerial* is = new InterfaceSerial(COMM);
    is->inicializar();
    PersistenciaDeSerie* persiste;

    char choose = 's' ;

    bool orientacaoHorizontal = true;

    list<Serie*> *listSeries = new list<Serie*>;
    vector<Serie*> *vectorSeries = new vector<Serie*>;

    string arquivo;
    string title;
    string canalX;
    string canalY;
    string nomeSerie;
    string nomeSalvar;

    double minimo, maximo, x, y;

    int i = 0;
    int quantidadeCanais = is->getQuantidadeDeCanais();
    int escolhaX, escolhaY;
    int quantidade;


    cout << "Aperte o botao reset da placa." << endl;
  // Obtem o nome e o atribui a serie ser
    cout << "Informe o nome do arquivo:" << endl;
    cin >> arquivo;

    try{
        persiste = new PersistenciaDeSerie(arquivo);
    }catch(ErroDeArquivo* e){
        cout << e->what();
        delete e;
    }

    while (choose == 's'){
        cout << "Informe o nome da serie: ";
        cin >> nomeSerie;
        cout << endl;

  // Obtem  os canais escolhidos
  //Imprime a lista de canais para X
        cout << "Escolha o Canal X: " << endl;
        cout << "0) Tempo" << endl;
        for(i=0; i < quantidadeCanais; i++){
            cout << i + 1 << ") " << is->getNomeDosCanais()[i] << endl;
        }
        cin >> escolhaX;

        if(escolhaX == 0)
            canalX = "Tempo";
        else
            canalX = is->getNomeDosCanais()[escolhaX - 1];

  //Imprime a lista de canais para Y
        cout << "Escolha o Canal Y: " << endl;
        for(i=0; i < quantidadeCanais; i++){
            cout << i + 1 << ") " << is->getNomeDosCanais()[i] << endl;
        }
        cin >> escolhaY;
        canalY = is->getNomeDosCanais()[escolhaY - 1];

        if (escolhaX == 0){
            ser2 = new SerieTemporal(nomeSerie, canalY);
            listSeries->push_back(ser2);
            vectorSeries->push_back(ser2);
        }
        else{
            ser1 = new SerieNormal(nomeSerie, canalX, canalY);
            listSeries->push_back(ser1);
            vectorSeries->push_back(ser1);
        }

        cout << "Adicionar uma outra serie (s/n):" << endl;
        cin >> choose;
    }


  // Obtem o numero de Pontos a adicionar
    cout << "Obter quantos pontos? ";
    cin >> quantidade;
    cout << endl;
    cout << "Obtendo pontos." << endl;



    cout << "Deseja carregar alguma serie? (s/n)" << endl;
    cin >> choose;

    while(choose == 's'){

        nomes = persiste->getNomes();
        tamanho = nomes->size();


        for(i = 0; i < tamanho; i++){
            cout << i + 1 << ") " << nomes-> at(i) << endl;
        }
        cout << "Escolha a serie para carregar:";
        cin >> escolha;
        cout << endl;
        vectorSeries->push_back(persiste->obter(nomes->at(escolha - 1)));
        listSeries->push_back(persiste->obter(nomes->at(escolha - 1)));
        cout << "Deseja carregar outra serie? (s/n)" << endl;
        cin >> choose;
    }

        for(i = 0; i < vectorSeries->size(); i++){
        if(SerieTemporal* st = dynamic_cast<SerieTemporal*>(vectorSeries->at(i))){
            y = is->getValor(st->getNomeDoCanalY());
            is->atualizar();
            st->adicionar(y);
        }

        else{
            SerieNormal* sn = dynamic_cast<SerieNormal*>(vectorSeries->at(i));
            x = is->getValor(sn->getNomeDoCanalX());
            y = is->getValor(sn->getNomeDoCanalY());
            is->atualizar();
            sn->adicionar(x, y);
        }
    }

    cout << "O eixo X e estatico ou dinamico (e/d):";
    cin >>  choose;
    cout << endl;

    if(choose == 'e'){
        cout << "Informe o titulo:";
        cin >> title;
        cout << endl << "Valor minimo:";
        cin >> minimo;
        cout << endl << "Valor maximo:";
        cin >> maximo;
        cout << endl;

        X = new EixoEstatico(title, minimo, maximo, orientacaoHorizontal);
    }
    else{
        cout << "Informe o titulo:";
        cin >> title;
        cout << "Valor minimo padrao:";
        cin >> minimo;
        cout << endl << "Valor maximo padrao:";
        cin >> maximo;
        cout << endl;

        if(canalX != "Tempo"){
            X = new EixoDinamico(title, minimo, maximo, listSeries, orientacaoHorizontal);
        }
        else{
            X = new EixoDinamico("Tempo", minimo, maximo, listSeries, orientacaoHorizontal);
        }
    }

    cout << "O eixo Y e estatico ou dinamico (e/d):";
    cin >>  choose;
    cout << endl;

    if(choose == 'e'){
        cout << "Informe o titulo:";
        cin >> title;
        cout << endl << "Valor minimo:";
        cin >> minimo;
        cout << endl << "Valor maximo:";
        cin >> maximo;
        cout << endl;

        Y = new EixoEstatico(title, minimo, maximo, false);
    }
    else{
        cout << "Informe o titulo:";
        cout << "Valor minimo padrao:";
        cin >> minimo;
        cout << endl << "Valor maximo padrao:";
        cin >> maximo;
        cout << endl;

        if(canalX != "Tempo"){
            Y = new EixoDinamico(title, minimo, maximo, listSeries, false);
        }
        else{
            Y = new EixoDinamico(title, minimo, maximo, listSeries, false);
        }
    }

    graphic = new Grafico(X, Y, vectorSeries);

    graphic->desenhar();



    cout << "Deseja salvar alguma serie? (s/n)";
    cin >> choose;
    cout << endl;

    while(choose == 's'){

        tamanho = vectorSeries->size();

        for(i = 0 ; i < tamanho; i++ ){
            cout << i + 1 << ") " << (vectorSeries->at(i))->getNome();
        }

        cout << "Escolha a serie para salvar:";
        cin >> escolha;
        cout << endl << "Salvar a serie com qual nome?";
        cin >> nomeSalvar;
        cout << endl;

        try{
            persiste->inserir(nomeSalvar, vectorSeries->at(escolha - 1));
        }catch( ErroDeArquivo* e){
            cout << e->what();
            delete e;
        }

        cout << "Deseja salvar outra serie?";
        cin >> choose;

    }

    return 0;

}
