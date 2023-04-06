#ifndef LLSE_H
#define LLSE_H
#include <no.h>
#include <QString>

namespace hj{
class LLSE
{
    //atributos
private:
    int quantidadeElementos;
    NO *inicio;
public:
    LLSE();
    bool estaVazia()const;
    void inserirInicio(int elemento);
    void inserirFim(int elemento);
    int retirarInicio();
    int retirarFim();
    int acessarFim()const;
    int acessarInicio()const;
    QString obterDadosLLSE()const;
    int getQuantidadeElementos() const;
};
}
#endif // LLSE_H
