#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "cadastro.h"
#include "pessoa.h"
#include "funcionario.h"
#include "compras.h"
#include "cliente.h"
#include "gerente.h"
#include "dancarina.h"
#include "cantor.h"
#include "alocacao.h"
#include "portaria.h"
#include "teladancarina.h"
#include "login.h"
#include "telabarmam.h"
#include "telacantor.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    set_lista();// carrega tabela com todos clientes cadastrados
    plot_tabelaContas();
    economia();
    ui->lineEdit_pagarContaNome->setEnabled(false);
    ui->lineEdit_pagarID->setEnabled(false);
    ui->lineEdit_pagarNome->setEnabled(false);
    ui->doubleSpinBox_pagarContaValor->setEnabled(false);
    ui->doubleSpinBox_pagarValor->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCliente_triggered()
{
    // chama tela cadastro
    Cadastro *ob = new Cadastro(this);
    ob->show();

}

void MainWindow::set_lista()
{
    QJsonArray list;
    Pessoa *pessoa = new Cliente();
    pessoa->set_dadospessoais();
    list=pessoa->jsonarrayPessoa;

    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n não temos clientes cadastrado");
    }else
        plot_tabela(list);

    // estoque

    Boate set;
    set.set_estoque();
    list=set.JarryBoate;

    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n estamos sem estoque");
    }else
        plot_tabelaEstoque(list);


}

void MainWindow::on_pushButton_presente_clicked()
{

    QJsonArray list,listVip;
    Pessoa *pessoa = new Cliente();
    pessoa->set_dadospessoais();
    list=pessoa->jsonarrayPessoa;

    // remove não presente
    QJsonObject obj;
    for(int i=0;i<list.size();i++)
    {
        obj =list[i].toObject();
        if(obj.value("presente")=="yes"){

            qDebug()<<"print presente"<<obj.value("id")<<obj.value("presente");
            listVip.append(obj);

        }
    }
    plot_tabela(listVip);

}

void MainWindow::on_pushButton_todosCliente_clicked()
{
    set_lista();
}

void MainWindow::on_actiondados_de_pessoas_triggered()
{
    Compras *cp = new Compras(this);
    cp->show();

}

void MainWindow::on_pushButton_vip_clicked()
{

    QJsonArray listVip;
    Pessoa *pessoa;// = new Cliente();
    Cliente cliente;
    cliente.set_clientevip();
    pessoa=&cliente;
    listVip=pessoa->jsonarrayPessoa;
    //delete pessoa;
    // remove não vip
    if(listVip.size()==0){
        QMessageBox::information(this,"Buscando dados:","lista vip vazia");
    }else
        plot_tabela(listVip);
}

void MainWindow::plot_tabela(QJsonArray Jlist)
{
    QJsonObject obj;
    if(Jlist.size()==0){
        QMessageBox::information(this,"plot tabela :","lista vazia");
        return;}

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"id"<<"nome"<<"idade"<<"vip"<<"presente"<<""
                                                           "sexo"<<"cpf"<<"rg"<<"orgaoexpedidor"<<"carteiradetrabalho"
                                                                                                  ""<<"profissao"<<"email"<<"telefone"<<"endereco"<<"cep"<<""
                                                                                                                                                           "banco"<<"agenciabanco"<<"contabanco"<<"tempodecontrato"<<"expediente"<<"salario";
    QStandardItemModel *model = new QStandardItemModel(Jlist.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

    for(int i=0;i<nomeClunas.size();i++)
        model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

    for(int row=0;row<Jlist.size();row++){
        obj =Jlist[row].toObject();
        for(int col=0;col<nomeClunas.size();col++){
            QModelIndex index= model->index(row,col ,QModelIndex());
            model->setData(index,obj.value(nomeClunas[col]));

        }
    }

    ui->tableView_dados->setModel(model);
}

void MainWindow::plot_tabelaEstoque(QJsonArray Jlist)
{
    QJsonObject obj;

    /*       produto["nome"]=nome;
            produto["marca"]=marca;
            produto["preco"]=preco;
            produto["quantidade"]=quant;*/
    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"nome"<<"marca"<<"preco"<<"quantidade";

    QStandardItemModel *model = new QStandardItemModel(Jlist.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

    for(int i=0;i<nomeClunas.size();i++)
        model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

    for(int row=0;row<Jlist.size();row++){
        obj =Jlist[row].toObject();
        for(int col=0;col<nomeClunas.size();col++){
            QModelIndex index= model->index(row,col ,QModelIndex());
            model->setData(index,obj.value(nomeClunas[col]));

        }
    }
    ui->tableView_estoque->setModel(model);


}

void MainWindow::plot_tabelaContas()
{
    Boate set;
    set.set_contas();
    QJsonArray list=set.JarryBoate;

    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n estamos sem estoque");
        return;}
    QJsonObject obj;


    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"nome"<<"valor";

    QStandardItemModel *model = new QStandardItemModel(list.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

    for(int i=0;i<nomeClunas.size();i++)
        model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

    for(int row=0;row<list.size();row++){
        obj =list[row].toObject();
        for(int col=0;col<nomeClunas.size();col++){
            QModelIndex index= model->index(row,col ,QModelIndex());
            model->setData(index,obj.value(nomeClunas[col]));

        }
    }
    ui->tableView_contas->setModel(model);
}

void MainWindow::economia()
{
    Boate set;
    set.set_economia();
    QJsonArray list=set.JarryBoate;
    QJsonObject obj;
    obj =list[0].toObject();
    double lucro= obj.value("lucro").toDouble();
    double valor=obj.value("valor").toDouble();
    QString strValor,strLucro;
    strValor= strValor.setNum(valor);
    strLucro=strLucro.setNum(lucro);


    QString StrLucro="Lucro: R$ "+strLucro;
    QString StrValor="Valor em caixa: R$ "+strValor;
    qDebug()<<"valor "<<valor<<strValor<<StrValor;
    ui->label_lucro->setText(StrLucro);
    ui->label_valor->setText(StrValor);

}
void MainWindow::on_pushButton_funcionarios_clicked()
{
    Funcionario *gerente= new Gerente();
    Funcionario *cantor=new Cantor();
    Funcionario *danca=new Dancarina();
    gerente->get_salario();
    cantor->get_salario();
    danca->get_salario();

    QJsonArray list;
    Pessoa *pessoa = new Funcionario();
    pessoa->set_dadospessoais();
    list=pessoa->jsonarrayPessoa;

    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n não temos funcionarios cadastrado");
        return;}
    plot_tabela(list);
}

void MainWindow::on_actionAloca_o_triggered()
{
    Alocacao *aloca= new Alocacao(this);
    aloca->show();
}

void MainWindow::on_actionPortaria_triggered()
{
    Portaria *chamar=new Portaria();
    chamar->show();
}

void MainWindow::on_actionDan_arina_triggered()
{
    TelaDancarina *ob=new TelaDancarina();
    ob->show();
}

void MainWindow::on_actionBarman_triggered()
{
    TelaBarmam *chamar =new TelaBarmam();
    chamar->show();
}

void MainWindow::on_actionCantor_triggered()
{
    TelaCantor *chamar =new TelaCantor();
    chamar->show();
}

void MainWindow::on_pushButton_atualizar_clicked()
{
    economia();
}


void MainWindow::on_tableView_dados_activated(const QModelIndex &index)
{

    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_pagarID->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->lineEdit_pagarNome->setText(ind.data().toString());
    ind=index.sibling(index.row(),20);
    ui->doubleSpinBox_pagarValor->setValue(ind.data().toString().toDouble());

}

void MainWindow::on_pushButton_pagarfun_clicked()
{
    // botao pagar
    if(ui->lineEdit_pagarID->text()==""){
        QMessageBox::information(this,"Sem funcionario","clik no botão funcionario e depois escolha clicando na tabelas");
    return;
    }
    double valor = ui->doubleSpinBox_pagarValor->value();
    Boate caixa;
    valor = valor*-1;
    QString strValor;
    strValor= strValor.setNum(valor);
    caixa.receita=strValor;
    caixa.lucro=strValor;
    caixa.get_economia();
    economia();
    ui->lineEdit_pagarID->clear();
    ui->lineEdit_pagarNome->clear();
    ui->doubleSpinBox_pagarValor->clear();
}

void MainWindow::on_pushButton_pagarConta_clicked()
{
    // botao pagar
    if(ui->lineEdit_pagarContaNome->text()==""){
        QMessageBox::information(this,"Sem conta","escolha clicando na tabelas");
    return;
    }
    double valor = ui->doubleSpinBox_pagarContaValor->value();
    Boate caixa;
    valor = valor*-1;
    QString strValor;
    strValor= strValor.setNum(valor);
    caixa.receita=strValor;
    caixa.lucro=strValor;
    caixa.get_economia();
    economia();
    ui->lineEdit_pagarContaNome->clear();
    ui->doubleSpinBox_pagarContaValor->clear();
}

void MainWindow::on_tableView_contas_activated(const QModelIndex &index)
{

    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_pagarContaNome->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->doubleSpinBox_pagarContaValor->setValue(ind.data().toString().toDouble());
}
