#include "boate.h"
#include <stdio.h>
#include <QDebug>
Boate::Boate()
{
    // contrutor
}

void Boate::get_conta()
{

    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file("../Boate_controle05/arquivos/contas.json");
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

    QJsonObject conta;

    conta["nome"]=nome_contas;
    conta["valor"]=despesas;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    jarray.append(conta);
    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error classe Boate "<<error.errorString()<<endl;


}

void Boate::get_ventos()
{
    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file("../Boate_controle05/arquivos/alocacao.json");
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
    QJsonObject evento;

    evento["data"]=datafesta;
    evento["quantidade de pessoa"]=qtd_pessoa;
    evento["tema da festa"]=tema_festa;
    evento["hora inicio"]=hora_deiniciofesta;
    evento["hora fim"]=hora_terminofesta;
    evento["desconto de entrada"]=desconto_entrada;
    evento["valor de entrada"]=valor_entrada;



    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    jarray.append(evento);
    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error classe Boate get_evento"<<error.errorString()<<endl;
}

void Boate::get_economia()
{
    QFile file("../Boate_controle05/arquivos/caixa.json");
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
        double var =objt.value("valor").toDouble();
        double lu=objt.value("lucro").toDouble();
        var+=receita.toDouble();
        lu+=lucro.toDouble();
        objt["valor"]=var;
        objt["lucro"]=lu;
        jarray.append(objt);

    }


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    qDebug()<< "get_receitasbebidas erro "<<error.errorString()<<endl;
}

void Boate::get_receitasbebidas()
{
    QFile file("../Boate_controle05/arquivos/caixa.json");
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
        double var =objt.value("valor").toDouble();
        double lu=objt.value("lucro").toDouble();
        var+=receita_bebidas.toDouble();
        lu+=lucro.toDouble();
        objt["valor"]=var;
        objt["lucro"]=lu;
        jarray.append(objt);

    }


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    qDebug()<< "get_receitasbebidas erro "<<error.errorString()<<endl;
}

void Boate::get_bebidasVendidas()
{
    QFile file("../Boate_controle05/arquivos/bebibasVendidas.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    QJsonArray dado=get_dados.array();
    QJsonArray jarray;
    int tamanho=dado.size();
    bool axi=true;
    for(int i=0;i<tamanho;i++){
        QJsonObject objt = dado[i].toObject();

        jarray.append(objt);

    }

    QJsonObject dancarina;
    dancarina["nome"]=nome_bebida;
    dancarina["marca"]=marca;
    dancarina["valor"]=receita_bebidas;
    dancarina["quant"]=qtd_bebidasvendidas;
    dancarina["lucro"]=lucro;
    jarray.append(dancarina);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    qDebug()<< "get_sevico erro "<<error.errorString()<<endl;
}

void Boate::set_contas()
{
    QFile file("../Boate_controle05/arquivos/contas.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    JarryBoate =get_dados.array();
    qDebug()<< "error  em set_conta"<<error.errorString()<<endl;
}

void Boate::set_evento()
{
    QFile file("../Boate_controle05/arquivos/alocacao.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    JarryBoate =get_dados.array();
    qDebug()<< "error  em set_evento"<<error.errorString()<<endl;
}

void Boate::set_economia()
{
    QFile file("../Boate_controle05/arquivos/caixa.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    JarryBoate =get_dados.array();
    qDebug()<< "error  em set_economia"<<error.errorString()<<endl;
}

void Boate::set_estoque()
{

    QFile file("../Boate_controle05/arquivos/estoque.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    JarryBoate =get_dados.array();

    file.close();
    qDebug()<< "boate set_estoque erro"<<error.errorString()<<endl;
}

void Boate::set_bebidasvendidas()
{
    QFile file("../Boate_controle05/arquivos/bebibasVendidas.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    JarryBoate =get_dados.array();

    file.close();
    qDebug()<< "boate set efdstoque erro"<<error.errorString()<<endl;
}

void Boate::edit_estoque()
{
    // edita teg presente parar yes dado um id
    QFile file("../Boate_controle05/arquivos/estoque.json");
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
        if(nome_bebida==objt.value("nome").toString() && marca==objt.value("marca").toString())
            if(objt.value("quantidade").toString().toInt()>0){
                qDebug()<<"tese "<<objt.value("quantidade").toString().toInt()<<qtd_bebidasvendidas.toInt();
            int quant=objt.value("quantidade").toString().toInt()-qtd_bebidasvendidas.toInt();
            QString srtQuand;
                objt["quantidade"]=srtQuand.setNum(quant);

            }else{
               qDebug()<<"vazio edit_estoque";
               return;
            }
        jarray.append(objt);

    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;

    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error edit_estoque "<<error.errorString()<<endl;
}



