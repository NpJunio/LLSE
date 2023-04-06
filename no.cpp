#include "no.h"
#include "llse.h"
namespace hj{
int NO::getDado() const
{
    return dado;
}

void NO::setDado(int newDado)
{
    dado = newDado;
}

NO* NO::getProximo() const
{
    return proximo;
}

void NO::setProximo(NO *newProximo)
{
    proximo = newProximo;
}

NO::NO():
    dado(0),
    proximo(0)
{

}
NO::NO(int elemento):
    dado(elemento),
    proximo(0)
{

}
}
