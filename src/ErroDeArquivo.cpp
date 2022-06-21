#include "ErroDeArquivo.h"
#include "iostream"
using namespace std;

ErroDeArquivo::ErroDeArquivo (string mensagem) : logic_error(mensagem)
{
    //constructor
}

ErroDeArquivo::~ErroDeArquivo()
{
    //dtor
    cout << "ErroDeArquivo destruido" << endl;
}
