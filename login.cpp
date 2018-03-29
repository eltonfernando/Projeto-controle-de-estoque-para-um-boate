#include "login.h"
#include "ui_login.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include "cantor.h"
#include "alocacao.h"
#include "teladancarina.h"
#include "mainwindow.h"
#include "telabarmam.h"
#include "telacantor.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QStringList lista;
    lista<<"cantor"<<"barmam"<<"dançarina"<<"gerente";
    ui->comboBox_cargo->addItems(lista);
}

Login::~Login()
{
    delete ui;
}

void Login::set_login()
{
    QFile file("login.json");
    QJsonParseError error;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayLogin=get_dados.array();

    qDebug()<< "error  em set_login"<<error.errorString()<<endl;
}

void Login::chama_cantor()
{
TelaCantor *chamar=new TelaCantor();
chamar->show();
}

void Login::chama_barmam()
{
TelaBarmam *ob=new TelaBarmam();
ob->show();
}

void Login::chama_dancariona()
{
TelaDancarina *ob = new TelaDancarina();
ob->show();
}

void Login::chama_gerente()
{
    MainWindow *bo =new MainWindow();
    bo->show();
}

void Login::on_pushButton_login_clicked()
{

    QString nome =ui->comboBox_cargo->currentText();
    QString senha = ui->lineEdit_senha->text();
    ui->lineEdit_senha->clear();

    qDebug()<<nome<<senha;
    QFile file("../Boate_controle05/arquivos/login.json");
    QJsonParseError error;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QJsonDocument get_dados = QJsonDocument::fromJson(file.readAll(),&error);
    file.close();
    jsonarrayLogin=get_dados.array();

    QJsonObject obj;

    for(int i=0;i<jsonarrayLogin.size();i++)
    {

        obj =jsonarrayLogin[i].toObject();
        qDebug()<<"banco "<<obj.value("nome")<<obj.value("senha");
        qDebug()<<"tela "<<nome<<senha;

        if(obj.value("nome").toString()==nome){
            if((nome=="gerente")&&(obj.value("senha").toString()==senha)){
                chama_gerente();return;
            }else if((nome=="cantor")&&(obj.value("senha").toString()==senha)){
                chama_cantor();return;
            }else if((nome=="barmam")&&(obj.value("senha").toString()==senha)){
                chama_barmam();return;
            }else if((nome=="dançarina")&&(obj.value("senha").toString()==senha)){
                chama_dancariona();return;
            }

        }
    }
    qDebug()<< "error"<<error.errorString()<<endl;

}
