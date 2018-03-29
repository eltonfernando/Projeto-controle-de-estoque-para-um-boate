#include "telabarmam.h"
#include "ui_telabarmam.h"
#include "boate.h"
#include <QMessageBox>
#include <QDebug>
#include <QJsonArray>
#include <QStandardItemModel>
#include "boate.h"
#include "funcionario.h"
TelaBarmam::TelaBarmam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaBarmam)
{
    ui->setupUi(this);
    ui->lineEdit_marca->setEnabled(false);
    ui->lineEdit_nome->setEnabled(false);
    ui->doubleSpinBox_preco->setEnabled(false);
    ui->doubleSpinBox_precoTotal->setEnabled(false);
    ui->lineEdit_marcaVenda->setEnabled(false);
    ui->lineEdit_nomeVenda->setEnabled(false);
    ui->doubleSpinBox_precoVenda->setEnabled(false);

    plot_tabela_estoque();
    plot_tabela_barman();
    plot_tela_bebidaVendida();
}

TelaBarmam::~TelaBarmam()
{
    delete ui;
}

void TelaBarmam::plot_tabela_estoque()
{

    Boate set;
    set.set_estoque();
    QJsonArray  Jlist=set.JarryBoate;

    if(Jlist.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n estamos sem estoque");
        return;}

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

void TelaBarmam::plot_tabela_barman()
{
    Funcionario set;
    set.set_Barman();
    QJsonArray  Jlist=set.jsonarrayFuncionario;

    if(Jlist.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n estamos sem bebidas");
        return;}

    QJsonObject obj;

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"nome"<<"marca"<<"preco"<<"quant"<<"lucro";

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
    ui->tableView_listBarman->setModel(model);
}

void TelaBarmam::plot_tela_bebidaVendida()
{
    Boate set;
    set.set_bebidasvendidas();
    QJsonArray  Jlist=set.JarryBoate;

  //  if(Jlist.size()==0){
    //    QMessageBox::information(this,"Buscando dados:","não foi vendido nada ainda");
      //  return;}

    QJsonObject obj;

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"nome"<<"marca"<<"valor"<<"quant";

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
    ui->tableView_bebidaVendidas->setModel(model);
}

void TelaBarmam::edit_lista_barman()
{

    QString nome_bebida=ui->lineEdit_nomeVenda->text();
    QString marca=ui->lineEdit_marcaVenda->text();
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
        if(nome_bebida==objt.value("nome").toString() && marca==objt.value("marca").toString())
        {
         continue;
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


void TelaBarmam::on_tableView_estoque_clicked(const QModelIndex &index)
{
    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_nome->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->lineEdit_marca->setText(ind.data().toString());
    ind=index.sibling(index.row(),2);
    ui->doubleSpinBox_preco->setValue(ind.data().toString().toDouble());
}

void TelaBarmam::on_doubleSpinBox_preco_valueChanged(double preco)
{
    double percet=ui->doubleSpinBox_lucro->value();
    int qdt=ui->spinBox_quantidade->value();
    // calcula preço total preco mais lucro vez quantidade
    ui->doubleSpinBox_precoTotal->setValue((preco*percet/100 +preco)*qdt);
    qDebug()<<"valor"<<preco;
}

void TelaBarmam::on_spinBox_quantidade_valueChanged(int qtd)
{
    ui->doubleSpinBox_precoTotal->setValue(ui->doubleSpinBox_precoTotal->value()*qtd);
}

void TelaBarmam::on_doubleSpinBox_lucro_valueChanged(double percent)
{
    double precoTotal=ui->doubleSpinBox_preco->value()*(1+percent/100);
    ui->doubleSpinBox_precoTotal->setValue(precoTotal);
}

void TelaBarmam::on_tableView_listBarman_clicked(const QModelIndex &index)
{
    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_nomeVenda->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->lineEdit_marcaVenda->setText(ind.data().toString());
    ind=index.sibling(index.row(),2);
    ui->doubleSpinBox_precoVenda->setValue(ind.data().toString().toDouble());
    ind=index.sibling(index.row(),3);
    quant=ind.data().toString();
    lucros=ind.data().toString();
    ind=index.sibling(index.row(),4);
}

void TelaBarmam::on_pushButton_barmanVender_clicked()
{
    Boate add;
    add.nome_bebida=ui->lineEdit_nomeVenda->text();
    add.marca=ui->lineEdit_marcaVenda->text();
    add.receita_bebidas=ui->doubleSpinBox_precoVenda->text().replace(",",".");
    add.lucro=lucros;
    add.qtd_bebidasvendidas=quant;
    add.get_bebidasVendidas();
    add.get_receitasbebidas();
     plot_tela_bebidaVendida();
     edit_lista_barman();
     plot_tabela_barman();



}

void TelaBarmam::on_pushButton_edtBebida_clicked()
{
    if(ui->lineEdit_novoNome->text()==""){
        QMessageBox::information(this,"Sem nome","qual é o nome da bebida");
        return;}
    double percent=ui->doubleSpinBox_lucro->value();
    double preco=ui->doubleSpinBox_preco->value();
    double lucro =percent*(preco/100); // calcular lucro
    QString strLucro;
    strLucro=strLucro.setNum(lucro);

    Funcionario add;
    add.nome_bebida=ui->lineEdit_novoNome->text();
    add.receita_bebidas=ui->doubleSpinBox_precoTotal->text().replace(",",".");
    int qtd = ui->spinBox_quantidade->value();
    QString strQtd;
    add.qtd_bebidasvendidas=strQtd.setNum(qtd);
    add.marca=ui->lineEdit_marca->text();
    add.lucro=strLucro;
    add.get_Barman();
    Boate edit;
    edit.nome_bebida=ui->lineEdit_nome->text();
    edit.marca=ui->lineEdit_marca->text();
    edit.qtd_bebidasvendidas=strQtd.setNum(qtd);
    edit.edit_estoque();
    plot_tabela_barman();
    plot_tabela_estoque();
    //limpando
    ui->lineEdit_marca->clear();
    ui->lineEdit_nome->clear();
    ui->doubleSpinBox_lucro->setValue(30);
    ui->doubleSpinBox_preco->clear();
    ui->spinBox_quantidade->setValue(1);
    ui->doubleSpinBox_precoTotal->clear();

}

void TelaBarmam::on_pushButton_limpardados_clicked()
{
   Funcionario limpa;
   limpa.get_LimpezaDados();
 plot_tela_bebidaVendida();

}
