#ifndef PESSOA_H
#define PESSOA_H
#include <QJsonArray>
#include <QString>
// classe abstract Pessoa
// seus métodos são implementados em
// cliente, funcionario
 class  Pessoa
{
public:

    //Por meio desta função será preenchido os dados pessoais como RG, CPF, endereço, e-mail, sexo, telefone, CEP.
    virtual void get_dadospessoais()=0;

    //Apresenta-se uma função especifica para dados bancários pois esta pode ser optativa para cadastro do cliente, enquanto que para os funcionários ela se torna relevante em razão que por intermédio dela poderá efetuar os pagamentos diretos em conta
    // virtual void get_dadosbancarios();


    virtual void set_dadospessoais()=0;
    //virtual void set_dadobancario();
   QString nome,email,endereco,sexo,orgaoexpedidor,profissao;
    QString cep,idade,carteiradetrabalho;
    QString rg;
    QString cpf,telefone,id;
    QString vip="NO";
    QString agenciabanco="NO";
    QString contabanco="NO";
    QString banco= "NO";
    QString presente ="NO";
    QJsonArray jsonarrayPessoa;
    virtual ~Pessoa()
    {

    }

};

#endif // PESSOA_H
