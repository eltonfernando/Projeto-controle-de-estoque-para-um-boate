#include "cantor.h"
#include <QDebug>
void Cantor::set_musica()
{
    QFile file("../Boate_controle05/arquivos/musica.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonArrayCantor =get_dados.array();

    file.close();
    qDebug()<< "boate set_estoque erro"<<error.errorString()<<endl;
}

void Cantor::get_musica()
{
    // lendo pega todos elemento do json coloca em uma QJsonArray
    // transforma em um QJsonObject e adiciona no inicio do novo QJsonArray jarray
    QFile file;
    file.setFileName("../Boate_controle05/arquivos/musica.json");
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

    QJsonObject addMusica;
    addMusica["musica"]=musica;
    addMusica["cantor"]=cantor;
    addMusica["genero"]=genero;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//QFile::Append WriteOnly
        return;

    jarray.append(addMusica);
    QJsonDocument jsdoc(jarray);
    QByteArray pacote = jsdoc.toJson();
    file.write(pacote);
    file.close();
    qDebug()<< "error"<<error.errorString()<<endl;
}

Cantor::Cantor()
{

}

void Cantor::get_salario()
{
    salario=100;
    qDebug()<<"get salario canto";
}
