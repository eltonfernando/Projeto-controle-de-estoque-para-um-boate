#ifndef DANCARINA_H
#define DANCARINA_H
#include "funcionario.h"
#include <QString>
#include <QDebug>
#include "pessoa.h"
/*
Classe derivada de Funcionários e amiga de Clientes, está classe irá
apresentar as funções e serviços da Dançarina, aonde a mesma ira gerenciar
os serviços que ela efetuou. A seguir apresenta-se a funções da classe
*/

class Dancarina:public Funcionario
{
    friend class Cliente;
public:

    //Função destinada a inserção de quais tipos de
    //dança a dançarina irá fazer na festa
    void get_danca();

    //Função destinada inserção do valor conquistados com a dança na festa.
    void get_receitadanca();
    //Função destinada a inserção de quais habilidades a adicionais a dançarina
    //possui e o valor arrecadado com esta habilidade
    void get_servico();

    void set_receitadanca();
    void set_servico();

    void set_danca();

    void get_salario();

    void set_dadospessoais();
    QString dancas,preco,receita_danca,desconto_danca,nome,id_dancarina,tempo_danca;
    QJsonArray jsonarrayDancarina;
    Dancarina();


};

#endif // DANCARINA_H
