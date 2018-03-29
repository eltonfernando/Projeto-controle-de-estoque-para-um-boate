#include "compras.h"
#include "ui_compras.h"
#include "gerente.h"
#include <QDebug>
#include <QMessageBox>
#include "boate.h"

Compras::Compras(QWidget *parent) :
    QMainWindow(parent),
    ui_telaCompras(new Ui::Compras)
{
    ui_telaCompras->setupUi(this);

}

Compras::~Compras()
{
    delete ui_telaCompras;
}

void Compras::on_pushButton_Comprar_clicked()
{
    qDebug()<<"fechando comprar ";
    QString nome, marca, preco, quant;
    nome=ui_telaCompras->lineEdit_produto->text();
    marca=ui_telaCompras->lineEdit_marca->text();
    preco=ui_telaCompras->doubleSpinBox_precoCompras->text().replace(",",".");
    quant=ui_telaCompras->spinBox_qtdCompra->text();

    if(nome==""){
        QMessageBox::information(this,"Inválido","O nome do produto não\n pode ser nulo");

    }else if(marca==""){
        QMessageBox::information(this,"Inválido","A marca não\n pode ser nulo");

    }else if(preco=="0.00"){
        QMessageBox::information(this,"Inválido","O preço não\n pode ser nulo");
    }else if(quant=="0"){
        QMessageBox::information(this,"Inválido","A quantidade não\n pode ser nulo");
    }else{
        Gerente gr;
        gr.get_comprar(nome,marca,preco,quant);
        Boate addconta;
        addconta.nome_contas=nome;

        float despe=preco.toFloat();
        despe=despe*quant.toInt();
        QString QSdes= QString::number(despe);
        addconta.despesas=QSdes;
        addconta.get_conta();
    }
}


void Compras::on_lineEdit_produto_editingFinished()
{
    if(ui_telaCompras->lineEdit_produto->text()=="")
        QMessageBox::information(this,"Inválido","O nome do produto não\n pode ser nulo");
}

void Compras::on_pushButton_addConta_clicked()
{
    Boate addconta;
    addconta.nome_contas = ui_telaCompras->lineEdit_nomeConta->text();
    addconta.despesas=ui_telaCompras->doubleSpinBox_valorConta->text().replace(",",".");
    addconta.get_conta();
}
