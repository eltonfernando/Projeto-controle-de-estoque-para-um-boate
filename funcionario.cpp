#include "funcionario.h"
#include "cadastro.h"
#include "ui_cadastro.h"
#include <QJsonObject>
#include <QDebug>

Funcionario::Funcionario()
{

}

//metodo da class abstract (Pessoa)
//Por meio desta função será preenchido os dados pessoais
//como RG, CPF, endereço, e-mail, sexo, telefone, CEP.
void Funcionario::get_dadospessoais()
{

    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file("../Boate_controle05/arquivos/funcionarios.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    QJsonArray dado=get_dados.array();
    QJsonArray jarray;
   int tamanho=dado.size();
    for(int i=0;i<tamanho;i++){
        QJsonObject objt = dado[i].toObject();
        jarray.append(objt);

    }

qDebug()<< "id"<<dado.size()<<endl;

    QJsonObject pessoa;
            pessoa["id"]=id.setNum(tamanho);
            pessoa["nome"]=nome;
            pessoa["email"]=email;
            pessoa["endereco"]=endereco;
            pessoa["banco"]=banco;
            pessoa["sexo"]=sexo;
            pessoa["orgaoexpedidor"]=orgaoexpedidor;
            pessoa["profissao"]=profissao;
            pessoa["cep"]=cep;
            pessoa["agenciabanco"]=agenciabanco;
            pessoa["idade"]=idade;
            pessoa["carteiradetrabalho"]=carteiradetrabalho;
            pessoa["rg"]=rg;
            pessoa["contabanco"]=contabanco;
            pessoa["cpf"]=cpf;
            pessoa["telefone"]=telefone;
            pessoa["vip"]="NO";
            pessoa["presente"]=presente;
            pessoa["salario"]=salario;
            pessoa["expediente"]=expediente;
            pessoa["tempodecontrato"]=tempodecontrato;


            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
                return;

            jarray.append(pessoa);
            QJsonDocument jsdoc(jarray);
            QByteArray pacote = jsdoc.toJson();
            file.write(pacote);
            file.close();
            qDebug()<< "error"<<error.errorString()<<endl;
}

void Funcionario::get_salario()
{
    // implementação obrigatoria
}

void Funcionario::get_LimpezaDados()
{
     QFile file("../Boate_controle05/arquivos/bebibasVendidas.json");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
         return;
     file.write("");
     file.close();
}

void Funcionario::get_Barman()
{
    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file("../Boate_controle05/arquivos/bebidaBarman.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    QJsonArray dado=get_dados.array();
    QJsonArray jarray;
   int tamanho=dado.size();
    for(int i=0;i<tamanho;i++){
        QJsonObject objt = dado[i].toObject();
        jarray.append(objt);
    }
    QJsonObject vendas;

            vendas["nome"]=nome_bebida;
            vendas["preco"]=receita_bebidas;
            vendas["quant"]=qtd_bebidasvendidas;
            vendas["marca"]=marca;
            vendas["lucro"]=lucro;


            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
                return;
            jarray.append(vendas);
            QJsonDocument jsdoc(jarray);
            QByteArray pacote = jsdoc.toJson();
            file.write(pacote);
            file.close();
            qDebug()<< "error classe Boate get_bebidas"<<error.errorString()<<endl;
}

void Funcionario::set_Barman()
{
    QFile file("../Boate_controle05/arquivos/bebidaBarman.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
   jsonarrayFuncionario =get_dados.array();
   qDebug()<< "error  em set_Barman"<<error.errorString()<<endl;
}
void Funcionario::set_dadospessoais()
{
    QFile file("../Boate_controle05/arquivos/funcionarios.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
   jsonarrayPessoa=get_dados.array();

qDebug()<< "error  em set_dados"<<error.errorString()<<endl;


}
