#include "llse.h"
namespace hj{
int LLSE::getQuantidadeElementos() const
{
    return quantidadeElementos;
}

LLSE::LLSE():
    quantidadeElementos(0),
    inicio(0)
{
}
    bool LLSE::estaVazia()const{
        return (quantidadeElementos == 0 );

    }
    void LLSE::inserirInicio(int elemento){
        try{
            NO* aux = new NO(elemento);
                quantidadeElementos++;
                aux->setProximo(inicio);
                inicio = aux;
        }catch (std::bad_alloc &erro){
            throw QString("No não foi criado");
        }
    }
    void LLSE::inserirFim(int elemento){
        try{
            NO* novo = new NO(elemento);
            if(estaVazia()){
                inicio = novo;
                quantidadeElementos++;
                return;
            }
            NO* aux = inicio;
            for(int c =0;c<quantidadeElementos-1;c++){
            aux = aux->getProximo();
            }
            aux->setProximo(novo);
            quantidadeElementos++;

        }catch (std::bad_alloc &erro){
            throw QString("No não foi criado");
        }
    }
    int LLSE::acessarInicio()const{
        if(estaVazia()) throw QString("Lista esta Vazia - acessarInicio");
        NO* aux = inicio;
        int valor = aux->getDado();
        return valor;
    }
    int LLSE::acessarFim()const{
        if(estaVazia()) throw QString("Lista esta Vazia - acessarFim");
        NO* aux = inicio;
         //int quantidadeElementos = getQuantidadeElementos();
        for(int c =0;c<quantidadeElementos-1;c++){
        aux = aux->getProximo();
        }
        return aux->getDado();


    }
    QString LLSE::obterDadosLLSE()const{
        QString dados = "";
        NO* atual = inicio;
        bool vermelho = true;
        if(estaVazia()){
            dados += "<font color='red'>Lista esta vazia</font>";
        }
        while (atual != nullptr) {
            dados += "| ";
            dados += QString::number(atual->getDado());
            if (atual->getProximo() != nullptr) {
                dados += " | ->";
            } else {
                dados += " | ";
            }
            if (vermelho) {
                dados = "<font color='red'>" + dados + "</font>";
            } else {
                dados = "<font color='black'>" + dados + "</font>";
            }
            vermelho = !vermelho;
            atual = atual->getProximo();
        }
        return dados;
    }

int LLSE::retirarInicio(){
    if(estaVazia()) throw QString("Lista esta Vazia - retirarInicio");
    NO* aux = inicio;
    quantidadeElementos--;
    inicio = aux->getProximo();
    int valor = aux->getDado();
    delete aux;
    return valor;
}
int LLSE::retirarFim(){
     if(estaVazia()) {throw QString("Lista esta Vazia - retirarFim");}
     if(quantidadeElementos==1){
         int valor = inicio->getDado();
         delete inicio;
         inicio=0;
         quantidadeElementos--;
         return valor;
     }
     NO* aux= inicio;
     for(int c =0;c<quantidadeElementos-2;c++){
     aux = aux->getProximo();
     }
     int valor = aux->getProximo()->getDado();
     delete aux->getProximo();
     aux->setProximo(0);
     quantidadeElementos--;
     return valor;
     //while(get)
}
}

