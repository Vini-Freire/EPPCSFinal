#include "ErroDeArquivo.h"

ErroDeArquivo::ErroDeArquivo(string mensagem) : logic_error(mensagem)
{
    //constructor chamando o construtor da logic_error
}

ErroDeArquivo::~ErroDeArquivo()
{
    //destructor
}
