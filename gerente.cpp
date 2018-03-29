#include "gerente.h"
#include "funcionario.h"
#include <QDebug>

Gerente::Gerente()
{

}

void Gerente::get_comprar(QString nome,QString marca, QString preco, QString quant)
{

    printf("o gente esta fazendo comprar .......\n");

    QFile file("../Boate_controle05/arquivos/estoque.json");
    QJsonParseError error;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
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

    QJsonObject produto;
            produto["nome"]=nome;
            produto["marca"]=marca;
            produto["preco"]=preco;
            produto["quantidade"]=quant;


            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            jarray.append(produto);
            QJsonDocument jsdoc(jarray);
            QByteArray pacote = jsdoc.toJson();
            file.write(pacote);
            file.close();
            qDebug()<< "Gerente erro open arquivo estoque"<<error.errorString()<<endl;
}

void Gerente::get_salario()
{
    salario=300;
    qDebug()<<"get salario gerente";
}

