#include "alocacao.h"
#include "ui_alocacao.h"
#include <QDebug>
#include <QDebug>
#include <QStandardItem>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <boate.h>

Alocacao::Alocacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alocacao)
{
    ui->setupUi(this);
    set_tabela();

}

Alocacao::~Alocacao()
{
    delete ui;
}

void Alocacao::on_calendarWidget_activated(const QDate &date)
{
    qDebug()<<date;
    QString data =date.toString("dd.MM.yyyy");
    data=data.replace(".","/");
    ui->lineEdit_dataFesta->setText(data);
}
void Alocacao::plot_tabela(QJsonArray Jlist)
{
    QJsonObject obj;
    if(Jlist.size()==0){
        QMessageBox::information(this,"plot tabela :","lista vazia");
        return;}
    /*
   evento["data"]=datafesta;
   evento["quantidade de pessoa"]=qtd_pessoa;
   evento["tema da festa"]=tema_festa;
   evento["hora inicio"]=hora_deiniciofesta;
   evento["hora fim"]=hora_terminofesta;
   evento["desconto de entrada"]=desconto_entrada;
   evento["valor de entrada"]=valor_entrada;*/

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"data"<<"tema da festa"<<"hora inicio"<<"hora fim"<<"quantidade de pessoa"<<"desconto de entrada"<<"valor de entrada";
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
    ui->tableView_agenda->setModel(model);
}

void Alocacao::set_tabela()
{
    QJsonArray list;
    Boate set;
    set.set_evento();
    list=set.JarryBoate;
    if(list.size()==0){
        QMessageBox::information(this,"Buscando dados:","\n não temos eventos agendado");
    }else
        plot_tabela(list);

}

void Alocacao::on_pushButton_agendar_clicked()
{

    Boate get;
    get.datafesta=ui->lineEdit_dataFesta->text();
    get.hora_deiniciofesta=ui->timeEdit_inicio->text();
    get.hora_terminofesta=ui->timeEdit_fim->text();
    get.desconto_entrada=ui->doubleSpinBox_desconto->text().replace(",",".");
    get.valor_entrada=ui->doubleSpinBox_valorEntrada->text().replace(",",".");
    get.tema_festa=ui->lineEdit_temaFesta->text();
    get.qtd_pessoa=ui->spinBox_qtdPessoas->text();
    get.get_ventos();
    set_tabela();
}


