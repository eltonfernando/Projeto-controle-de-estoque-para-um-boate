#include "telacantor.h"
#include "ui_telacantor.h"
#include "QMessageBox"
#include "cantor.h"
#include <QStandardItemModel>

TelaCantor::TelaCantor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaCantor)
{
    ui->setupUi(this);
    plot_tela_musica();
}

TelaCantor::~TelaCantor()
{
    delete ui;
}

void TelaCantor::on_pushButton_clicked()
{
    if(ui->lineEdit_musica->text()==""){
        QMessageBox::information(this,"sem nome","de um nome para mucisa");
                return;
    }
    Cantor add;
    add.musica=ui->lineEdit_musica->text();
    add.cantor=ui->lineEdit_cantor->text();
    add.genero=ui->lineEdit_genero->text();
    add.get_musica();
plot_tela_musica();
    //limpar
    ui->lineEdit_musica->clear();
    ui->lineEdit_cantor->clear();
    ui->lineEdit_genero->clear();

}

void TelaCantor::plot_tela_musica()
{
    Cantor set;
    set.set_musica();
    QJsonArray  Jlist=set.jsonArrayCantor;

    if(Jlist.size()==0){
        QMessageBox::information(this,"Buscando dados:","não foi possivel carregar informação,"
                                                        "\n estamos sem bebidas");
        return;}

    QJsonObject obj;

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"musica"<<"cantor"<<"genero";

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
    ui->tableView_musicas->setModel(model);

}
