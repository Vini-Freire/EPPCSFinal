#ifndef ERRODEARQUIVO_H
#define ERRODEARQUIVO_H
#include "stdexcept"

class ErroDeArquivo : public logic_error
{
    public:
        ErroDeArquivo(string mensagem);
        virtual ~ErroDeArquivo();


};

#endif // ERRODEARQUIVO_H
