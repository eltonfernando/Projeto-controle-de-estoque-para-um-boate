#ifndef CLIENTE_H
#define CLIENTE_H
#include "pessoa.h"
#include "boate.h"
/*
Classe derivada de Boate e Pessoa, nesta classe servira caso o cliente deseje
alugar o espaço físico da boate, como também ele deseje apenas usufruir da boate
 em um dia normal, apresentando seu código e seu extrato referente ao uso. A seguir
 apresenta-se a funções da classe.
*/

class Cliente:public Pessoa,public Boate
{
public:
    Cliente();
    //Está função apresenta os clientes que são Vips, logo eles possuem
    //vantagens com relação aos clientes normais
    void get_clientevip(QString valor);
    void set_clientevip();
    void get_clientepresente(QString valor);
    // se clente não implemantar ele vira abstract (não pode instancias obj)
    virtual void get_dadospessoais();// herdada de pessoa
    virtual void set_dadospessoais(); //herdada de pessoa

    QString codigo_cliente;
    private:
};

#endif // CLIENTE_H
