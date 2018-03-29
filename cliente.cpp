#include "cliente.h"
#include "pessoa.h"
#include "pessoa.h"
#include "funcionario.h"
#include "QMessageBox"
#include "QDebug"
Cliente::Cliente()
{

}

void Cliente::get_clientevip(QString valor)
{
    // edita teg presente parar yes dado um id
    QFile file("../Boate_controle05/arquivos/clientes.json");
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
        if(codigo_cliente==objt.value("id").toString())
            objt["vip"]=valor;
        jarray.append(objt);

    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;

    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error"<<error.errorString()<<endl;
}

void Cliente::set_clientevip()
{
    QFile file("../Boate_controle05/arquivos/clientes.json");
    QJsonParseError error;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayPessoa=get_dados.array();
    QJsonArray listVip;
    QJsonObject obj;
    for(int i=0;i<jsonarrayPessoa.size();i++)
    {
        obj =jsonarrayPessoa[i].toObject();
        if(obj.value("vip")=="yes"){

            qDebug()<<"print vip"<<obj.value("id")<<obj.value("vip");
            listVip.append(obj);
        }


    }

    qDebug()<< "error  em set_dados"<<error.errorString()<<endl;

    jsonarrayPessoa=listVip;
}

void Cliente::get_clientepresente(QString valor)
{

    // edita teg presente parar yes dado um id

    QFile file("../Boate_controle05/arquivos/clientes.json");
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
        if(codigo_cliente==objt.value("id").toString())
            objt["presente"]=valor;
        jarray.append(objt);

    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;

    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error"<<error.errorString()<<endl;
}

void Cliente::get_dadospessoais()
{
    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file;
    file.setFileName("../Boate_controle05/arquivos/clientes.json");
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


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;

    jarray.append(pessoa);
    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error"<<error.errorString()<<endl;
}

void Cliente::set_dadospessoais()
{
    QFile file("../Boate_controle05/arquivos/clientes.json");
    QJsonParseError error;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayPessoa=get_dados.array();
    qDebug()<< "error  em set_dados"<<error.errorString()<<endl;

}


