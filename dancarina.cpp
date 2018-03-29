#include "dancarina.h"
#include <QDebug>
#include "cliente.h"
#include "pessoa.h"
#include "boate.h"
Dancarina::Dancarina()
{

}
void Dancarina::get_danca()
{
    QFile file("../Boate_controle05/arquivos/agendaDancarina.json");
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

        if(id_dancarina==objt.value("id").toString()){
            objt["habilidade"]=objt.value("habilidade").toString()+" "+dancas;
            objt["tempo dança"]=objt.value("tempo dança").toString()+" "+tempo_danca;
            objt["preço"]=objt.value("preço").toString()+" "+preco;

            axi=false;
        }
        jarray.append(objt);

    }
    if(axi){
        QJsonObject dancarina;
        dancarina["id"]=id_dancarina;
        dancarina["dancarina"]=nome;
        dancarina["habilidade"]=dancas;
        dancarina["preço"]=preco;
        dancarina["tempo dança"]=tempo_danca;
        jarray.append(dancarina);
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    qDebug()<< "get_sevico erro "<<error.errorString()<<endl;
}

void Dancarina::set_servico()
{
    QFile file("../Boate_controle05/arquivos/abilidadeDancarina.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayDancarina=get_dados.array();

    qDebug()<< "error  em set_servico"<<error.errorString()<<endl;

}

void Dancarina::set_danca()
{
    QFile file("../Boate_controle05/arquivos/agendaDancarina.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayDancarina=get_dados.array();

    qDebug()<< "error  em set_servico"<<error.errorString()<<endl;
}

void Dancarina::get_receitadanca()
{
    // removendo da lista de agenda
    QFile file("../Boate_controle05/arquivos/agendaDancarina.json");
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

        if(id_dancarina==objt.value("id").toString()){
            QStringList listAbili= objt.value("habilidade").toString().split(" ");
            QStringList listPreco=objt.value("preço").toString().split(" ");
            QStringList listTempo=objt.value("tempo dança").toString().split(" ");
            QString novaAbilida, novoTempo;
            QString novoPreco;
            for(int j=0;j<listAbili.size();j++){
                if(listAbili[j]==" ")continue;
                if(listAbili[j]=="")continue;
                if((listAbili[j]==dancas) && (listPreco[j]==preco)) {
                    continue;
                }
                novaAbilida=listAbili[j]+" "+novaAbilida;
                novoPreco=listPreco[j]+" "+novoPreco;
                novoTempo=listTempo[j]+" "+novoTempo;
                qDebug()<<"novaAbili"<<novaAbilida;
            }

            objt["habilidade"]=novaAbilida;
            objt["preço"]=novoPreco;
            objt["tempo dança"]=novoTempo;
        }
        jarray.append(objt);

    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    //add receita
    QFile file2("../Boate_controle05/arquivos/receitaDanca.json");


    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;
    QJsonDocument get_dados2 = QJsonDocument::fromJson(file2.readAll(),&error);
    file2.close();
    QJsonArray dado2=get_dados2.array();
    QJsonArray jarray2;

    bool axi=true;
    for(int i=0;i<dado2.size();i++){
        QJsonObject objt2 = dado2[i].toObject();

        if(id_dancarina==objt2.value("id").toString()){
            float p=objt2.value("preço").toString().toFloat()+ preco.toFloat();
            objt2["preço"]=preco.setNum(p);
            axi=false;
        }
        jarray2.append(objt2);

    }
    if(axi){
        QJsonObject dancarina;
        dancarina["id"]=id_dancarina;
        dancarina["dancarina"]=nome;
        dancarina["preço"]=preco;
        jarray2.append(dancarina);
    }
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc2(jarray2);
    QByteArray pacote2 = jsdoc2.toJson();
    file2.write(pacote2);
    file2.close();
}

void Dancarina::get_servico()
{
    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file("../Boate_controle05/arquivos/abilidadeDancarina.json");
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

        if(id_dancarina==objt.value("id").toString()){
            objt["habilidade"]=objt.value("habilidade").toString()+" "+dancas;
            objt["tempo dança"]=objt.value("tempo dança").toString()+" "+tempo_danca;
            objt["preço"]=objt.value("preço").toString()+" "+preco;

            axi=false;
        }
        jarray.append(objt);

    }
    if(axi){
        QJsonObject dancarina;
        dancarina["id"]=id_dancarina;
        dancarina["dancarina"]=nome;
        dancarina["habilidade"]=dancas;
        dancarina["preço"]=preco;
        dancarina["tempo dança"]=tempo_danca;
        jarray.append(dancarina);
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();

    qDebug()<< "get_sevico erro "<<error.errorString()<<endl;
}

void Dancarina::set_receitadanca()
{

    QFile file("../Boate_controle05/arquivos/receitaDanca.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayDancarina=get_dados.array();

    qDebug()<< "error set_receitadanca"<<error.errorString()<<endl;
}

void Dancarina::get_salario()
{
    salario=100;
    qDebug()<<"get salario dancarina";
}

void Dancarina::set_dadospessoais()
{
    qDebug() <<"chamando ser_dadospessoais de dancarina";
    QFile file("../Boate_controle05/arquivos/funcionarios.json");
    QJsonParseError error;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayPessoa=get_dados.array();
    QJsonArray listDancaria;
    QJsonObject obj;
    for(int i=0;i<jsonarrayPessoa.size();i++)
    {
        obj =jsonarrayPessoa[i].toObject();
        if(obj.value("profissao")=="Dançarina"){
            qDebug()<<"print Dancarina"<<obj.value("profissao")<<obj.value("id");
            listDancaria.append(obj);
        }

    }
    jsonarrayPessoa=listDancaria;
}
