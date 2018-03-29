#include "cadastro.h"
#include "ui_cadastro.h"
#include <QJsonArray>
#include <boate.h>
#include <funcionario.h>
#include <pessoa.h>
#include <cliente.h>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
Cadastro::Cadastro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    QStringList lista;
    lista<<"Cantor"<<"Dançarina"<<"Faxineira"<<"Gerente";
    ui->comboBox_cargo->addItems(lista);
}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::on_lineEdit_Cpf_editingFinished()
{
    QString cpf=ui->lineEdit_Cpf->text();
    ui->Label_Cpf->setText("CPF: estou verificando se o cliente ja possui cadastro....");
    QJsonArray list;
    Pessoa *pessoa = new Cliente();
    pessoa->set_dadospessoais();
    list=pessoa->jsonarrayPessoa;
    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n não temos clientes cadastrado");
        return;
    }

    for(int i=0;i<list.size();i++)
    {
        QJsonObject jdados=list[i].toObject();
        if(jdados.value("cpf").toString()==cpf){
            QString infor;
            infor="Ciente ja cadastrado \n seu codigo é ";
            infor+=jdados.value("id").toString();
            QMessageBox::information(this,"Cadastro",infor);
            return;

        }
    }

    ui->Label_Cpf->setText("CPF: ok");

}

void Cadastro::on_lineEdit_Cpf_textEdited(const QString &CPF)
{


}

void Cadastro::on_pushButton_novoCliente_clicked()
{
    Pessoa *pessoa;
    Cliente cadastra;
    pessoa=&cadastra;

    pessoa->cpf=ui->lineEdit_Cpf->text();
    pessoa->rg=ui->lineEdit_Rg->text();
    pessoa->orgaoexpedidor=ui->lineEdit_Ssp->text();
    pessoa->nome=ui->lineEdit_Nome->text();
    pessoa->email=ui->lineEdit_Email->text();
    pessoa->telefone=ui->lineEdit_Telefone->text();
    pessoa->idade=ui->spinBox_idade->text();
    pessoa->carteiradetrabalho=ui->lineEdit_CatriraTrabalho->text();
    pessoa->profissao=ui->lineEdit_Profissao->text();
    pessoa->sexo=ui->lineEdit_Sexo->text();
    pessoa->endereco=ui->lineEdit_Endereco->text();
    pessoa->cep=ui->lineEdit_Cep->text();
    pessoa->banco=ui->lineEdit_Banco->text();
    pessoa->contabanco=ui->lineEdit_Conta->text();
    pessoa->agenciabanco=ui->lineEdit_Agencia->text();
    cadastra.get_dadospessoais();

    // limpa
    ui->lineEdit_Cpf->setText("");
    ui->lineEdit_Rg->setText("");
    ui->lineEdit_Ssp->setText("");
    ui->lineEdit_Nome->setText("");
    ui->lineEdit_Email->setText("");
    ui->lineEdit_Telefone->setText("");
    ui->spinBox_idade->setValue(0);
    ui->lineEdit_CatriraTrabalho->setText("");
    ui->lineEdit_Profissao->setText("");
    ui->lineEdit_Sexo->setText("");
    ui->lineEdit_Endereco->setText("");
    ui->lineEdit_Cep->setText("");
    ui->lineEdit_Banco->setText("");
    ui->lineEdit_Conta->setText("");
    ui->lineEdit_Agencia->setText("");

}

void Cadastro::on_pushButton_contratar_clicked()
{
    Pessoa *pessoa;
    Funcionario cadastra;
    pessoa=&cadastra;

    pessoa->cpf=ui->lineEdit_Cpf->text();
    pessoa->rg=ui->lineEdit_Rg->text();
    pessoa->orgaoexpedidor=ui->lineEdit_Ssp->text();
    pessoa->nome=ui->lineEdit_Nome->text();
    pessoa->email=ui->lineEdit_Email->text();
    pessoa->telefone=ui->lineEdit_Telefone->text();
    pessoa->idade=ui->spinBox_idade->text();
    pessoa->carteiradetrabalho=ui->lineEdit_CatriraTrabalho->text();
    // pessoa->profissao=ui->lineEdit_Profissao->text();
    pessoa->sexo=ui->lineEdit_Sexo->text();
    pessoa->endereco=ui->lineEdit_Endereco->text();
    pessoa->cep=ui->lineEdit_Cep->text();
    pessoa->banco=ui->lineEdit_Banco->text();
    pessoa->contabanco=ui->lineEdit_Conta->text();
    pessoa->agenciabanco=ui->lineEdit_Agencia->text();
    cadastra.tempodecontrato=ui->lineEdit_tempoContrato->text();
    cadastra.salario=ui->doubleSpinBox_salario->text().replace(",",".");
    cadastra.expediente=ui->lineEdit_expediente->text();
    cadastra.profissao=ui->comboBox_cargo->currentText();
    cadastra.get_dadospessoais();

    // limpa
    ui->lineEdit_Cpf->setText("");
    ui->lineEdit_Rg->setText("");
    ui->lineEdit_Ssp->setText("");
    ui->lineEdit_Nome->setText("");
    ui->lineEdit_Email->setText("");
    ui->lineEdit_Telefone->setText("");
    ui->spinBox_idade->setValue(0);
    ui->lineEdit_CatriraTrabalho->setText("");
    ui->lineEdit_Profissao->setText("");
    ui->lineEdit_Sexo->setText("");
    ui->lineEdit_Endereco->setText("");
    ui->lineEdit_Cep->setText("");
    ui->lineEdit_Banco->setText("");
    ui->lineEdit_Conta->setText("");
    ui->lineEdit_Agencia->setText("");
    ui->doubleSpinBox_salario->setValue(0);
    ui->lineEdit_expediente->setText("");
    ui->lineEdit_tempoContrato->setText("");
}
