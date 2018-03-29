#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "boate.h"
#include "pessoa.h"
#include <QJsonArray>
//Está classe é derivada das Classes Boate e Pessoa, logo apresenta as seguintes funções:
class Funcionario: public Pessoa, public Boate
{
public:
    void set_dadospessoais();
    void get_dadospessoais();

    //virtual void set_salario();
  //  virtual void set_expediente();
/*
    Como o próprio nome já deixa claro, função tem está que tem como objetivo inserir o salário
    do funcionário, fizemos a parte devido existir funcionários que serão
    apenas contratados por uma festa logo terá seu salário fixo enquanto outros terão comissão */
     virtual void get_salario();


   // virtual void get_expediente();

   // Por intermédio desta função serão inseridos os tempos de contratos
    //que podem ser de uma festa até meses anos.
 //   virtual void get_tempodecontrato();


  //  virtual void set_tempodecontrato();

    //Está será uma função especifica dentro da classe Funcionários,
    //aonde será apenas preenchido os dados do barman
    void get_BarmanDados();

    /*  Apresenta-se também como uma função especifica da classe para limpeza da boate,
       logo será apenas para preenchimentos dos dados pessoais e bancários e horários de
       serviço tempo de contrato, pois esses dados são importantes para economia da boate. */
    void get_LimpezaDados();



    //Função especifica do Barman que tem como objetivo gerenciar o bar, a venda e o
    //estoque de bebidas assim como atribuição de nomes.
    void get_Barman();

    void set_Barman();

   QString salario; // dados em float use toFloat()
   QString tempodecontrato,expediente;
   QJsonArray jsonarrayFuncionario;
    Funcionario();

private:


};

#endif // FUNCIONARIO_H
