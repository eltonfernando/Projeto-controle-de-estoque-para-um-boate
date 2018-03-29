#ifndef BOATE_H
#define BOATE_H
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
//A classe Boate se refere tanto ao estabelecimento físico,
//como a parte de dados econômicos e estoque

class Boate
{
public:
    Boate();

   //Nesta função serão adicionadas as contas da boate.
   //referente a energia, bebidas, pagamentos de funcionários, água entre outras
    void get_conta();

    // Por meio desta função serão agendados os eventos da boate.
    //apresentando a data do evento a quantidade de pessoas da
    //festa a hora de início e final da festa e o tema da festa
    void get_ventos();

    //Por intermédio desta função serão calculados os lucros e as receitas da boate
    void get_economia();

    //Temos uma função especial para bebidas devido ao Barman possuir
    //um caixa, logo controla-se o retorno financeiro de bebidas para
    //uma melhor analise de quantos se deve comprar de bebidas e qual
    //tipo está rendendo mais
    void get_receitasbebidas();

    //Esta função terá como objetivo adicionar as bebidas e seus respectivos nome e marca para um controle maior do bar
    //void get_bebidas(); nudada para get_bebidasVendidas(), motivo mesma função de get_Barman() implementado em funcionaro
    void get_bebidasVendidas();

    void set_contas();
    void set_evento();
    void set_economia();
    void set_estoque();

    void set_bebidasvendidas();
    void edit_estoque();


    QJsonArray JarryBoate;
    QString datafesta,qtd_pessoa,hora_deiniciofesta,hora_terminofesta,tema_festa,estoque_bebida,nome_bebida,nome_contas,qtd_bebidasvendidas,despesas;
    QString valor_entrada,desconto_entrada,lucro,receita_bebidas,marca,receita;
    private:
};



#endif // BOATE_H
