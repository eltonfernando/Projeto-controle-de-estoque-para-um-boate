#ifndef GERENTE_H
#define GERENTE_H
#include "funcionario.h"
//#include <QCoreApplication>


/*
Classe derivada de funcionário, e como o nome já explicita responsável por gerenciar a boate e
efetuar compras analisar currículos adicionar despesas entre outras. A classe apresenta
as respectivas funções.*/
class Gerente:public Funcionario
{
public:
    //Função responsável pela administração de compras de objetos para a boate.
    void get_comprar(QString nome,QString marca, QString preco, QString quant);
    void set_corriculos();
    //void set_salario();
    void get_salario();
   // void get_dadospessoais();
    //void set_expediente();
    //void get_expediente();
    //void set_tempodecontrato();
   // void get_tempodecontrato();

    Gerente();
};

#endif // GERENTE_H
