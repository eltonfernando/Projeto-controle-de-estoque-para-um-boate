#include "teladancarina.h"
#include "ui_teladancarina.h"
#include <QJsonArray>
#include <QMessageBox>
#include <QJsonObject>
#include <QStandardItem>
#include <QTreeWidgetItem>
#include <pessoa.h>
#include <dancarina.h>

TelaDancarina::TelaDancarina(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaDancarina)
{
    ui->setupUi(this);

    ui->lineEdit_agendaAbilidade->setEnabled(false);
    ui->lineEdit_AgendaCodigo->setEnabled(false);
    ui->lineEdit_agendaNome->setEnabled(false);
    ui->doubleSpinBox_agendaPreco->setEnabled(false);
    ui->lineEdit_reAbilidade->setEnabled(false);
    ui->lineEdit_reId->setEnabled(false);
    ui->lineEdit_reNome->setEnabled(false);
    ui->doubleSpinBox_raValor->setEnabled(false);

    Pessoa *pessoa = new Dancarina();
    pessoa->set_dadospessoais();
    jsonArrayTelaDancarina=pessoa->jsonarrayPessoa;
    plot_tabela(jsonArrayTelaDancarina);
    plot_abilidades();
    plot_agenda();
    plot_tabelaReceita();

}

TelaDancarina::~TelaDancarina()
{
    delete ui;
}

void TelaDancarina::plot_tabela(QJsonArray jarray)
{
    QJsonObject obj;
   if(jarray.size()==0){
       QMessageBox::information(this,"plot tabela :","lista vazia");
       return;}


   QStringList nomeClunas; // tem que ser igual os do pacote json acima
   nomeClunas <<"id"<<"nome"<<"profissao";

   QStandardItemModel *model = new QStandardItemModel(jarray.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

   for(int i=0;i<nomeClunas.size();i++)
       model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

   for(int row=0;row<jarray.size();row++){
       obj =jarray[row].toObject();
       for(int col=0;col<nomeClunas.size();col++){
           QModelIndex index= model->index(row,col ,QModelIndex());
           model->setData(index,obj.value(nomeClunas[col]));

       }
   }
   ui->tableView_dancarina->setModel(model);
}

void TelaDancarina::addTreaAgenda(QString nome, QStringList abilidades, QStringList tempo, QStringList preco, QString id)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget_agenda);
    treeItem->setText(0, nome);
    for(int n=0;n<abilidades.size();n++) {
         QTreeWidgetItem *treeItem2 = new QTreeWidgetItem();
         treeItem2->setText(1, abilidades[n]);
         treeItem2->setText(2, tempo[n]);
         treeItem2->setText(3, preco[n]);
         treeItem2->setText(4,nome);
         treeItem2->setText(5,id);
         treeItem->addChild(treeItem2);
}
}

void TelaDancarina::addTree(QString nome, QStringList abilidades,QStringList tempo,QStringList preco,QString id)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget_abilidade);
    treeItem->setText(0, nome);
    for(int n=0;n<abilidades.size();n++) {
         QTreeWidgetItem *treeItem2 = new QTreeWidgetItem();
         treeItem2->setText(1, abilidades[n]);
         treeItem2->setText(2, tempo[n]);
         treeItem2->setText(3, preco[n]);
         treeItem2->setText(4,nome);
         treeItem2->setText(5,id);
         treeItem->addChild(treeItem2);
}
}

void TelaDancarina::on_pushButton_addAbilidade_clicked()
{
  Dancarina add;
  add.id_dancarina=ui->lineEdit_id->text();
  add.dancas=ui->lineEdit_abilidade->text();
  add.nome=ui->lineEdit_nome->text();
  add.preco=ui->doubleSpinBox_preco->text().replace(",",".");
  add.tempo_danca=ui->timeEdit_tempo->text();
  add.get_servico();
 plot_abilidades();
  //limpado
  ui->lineEdit_abilidade->clear();
  ui->lineEdit_id->clear();
  ui->lineEdit_nome->clear();
  ui->doubleSpinBox_preco->clear();
  ui->timeEdit_tempo->clear();
  ui->lineEdit_nome->setEnabled(true);

}

void TelaDancarina::on_lineEdit_id_editingFinished()
{
    QJsonObject obj;
    for(int i=0;i<jsonArrayTelaDancarina.size();i++)
    {
        obj =jsonArrayTelaDancarina[i].toObject();
       if(obj.value("id")==ui->lineEdit_id->text()){
     ui->lineEdit_nome->setText(obj.value("nome").toString());
     ui->lineEdit_nome->setDisabled(true);

 }

 }

}

void TelaDancarina::plot_abilidades()
{
  ui->treeWidget_abilidade->clear();
    ui->treeWidget_abilidade->setColumnCount(2);
    ui->treeWidget_abilidade->setHeaderLabels(QStringList() << "Dançarina" << "habilidades"<<"tempo"<<"preço"<<"nome"<<"id");
       Dancarina abilidade;
       abilidade.set_servico();

       for(int i=0;i<abilidade.jsonarrayDancarina.size();i++){
   QJsonObject obj=abilidade.jsonarrayDancarina[i].toObject();
   QStringList listAbilidades=obj.value("habilidade").toString().split(" ");
   QStringList listTempo=obj.value("tempo dança").toString().split(" ");
   QStringList listPreco=obj.value("preço").toString().split(" ");
   addTree(obj.value("dancarina").toString(),listAbilidades,listTempo,listPreco,obj.value("id").toString());

       }
}

void TelaDancarina::on_treeWidget_abilidade_itemActivated(QTreeWidgetItem *item, int column)
{
QString tempo =item->text(2);
QTime time = QTime::fromString(tempo,"hh:m");

int hora= time.hour();
int minuto=time.minute();
double valor = item->text(3).toDouble();

double tempoHoras= hora +minuto/60;
 precoPorHoras=valor/tempoHoras;

     ui->lineEdit_agendaNome->setText(item->text(4));
     ui->lineEdit_AgendaCodigo->setText(item->text(5));

      ui->doubleSpinBox_agendaPreco->setValue(valor);
      ui->timeEdit_agendaTempo->setTime(time);
     ui->lineEdit_agendaAbilidade->setText(item->text(1));


}

void TelaDancarina::on_timeEdit_agendaTempo_userTimeChanged(const QTime &time)
{
    if(ui->timeEdit_agendaTempo->hasFocus()){

    ui->doubleSpinBox_agendaPreco->setEnabled(true);
    int hora= time.hour();
    int minuto=time.minute();
    double tempoHoras= hora;
    tempoHoras+=minuto*0.016667;
    qDebug()<<"text"<<hora<<minuto<<minuto*0.016667;
    ui->doubleSpinBox_agendaPreco->setValue(precoPorHoras*tempoHoras);
ui->doubleSpinBox_agendaPreco->setEnabled(false);
    }
}

void TelaDancarina::on_pushButton_agenda_clicked()
{
    Dancarina add;
    add.id_dancarina=ui->lineEdit_AgendaCodigo->text();
    add.dancas=ui->lineEdit_agendaAbilidade->text();
    add.nome=ui->lineEdit_agendaNome->text();
    add.preco=ui->doubleSpinBox_agendaPreco->text().replace(",",".");
    add.tempo_danca=ui->timeEdit_agendaTempo->text();
    add.get_danca();
     plot_agenda();

    //limpado
    ui->lineEdit_agendaAbilidade->clear();
    ui->lineEdit_AgendaCodigo->clear();
    ui->lineEdit_agendaNome->clear();
    ui->doubleSpinBox_agendaPreco->clear();
    ui->timeEdit_agendaTempo->clear();



}

void TelaDancarina::on_treeWidget_agenda_itemActivated(QTreeWidgetItem *item, int column)
{
    ui->lineEdit_reNome->setText(item->text(4));
    ui->lineEdit_reAbilidade->setText(item->text(1));
    ui->lineEdit_reId->setText(item->text(5));
    ui->doubleSpinBox_raValor->setValue(item->text(3).toDouble());

}

void TelaDancarina::on_pushButton_receita_clicked()
{
    Dancarina dados;
    dados.id_dancarina=ui->lineEdit_reId->text();
    dados.nome=ui->lineEdit_reNome->text();
    dados.dancas=ui->lineEdit_reAbilidade->text();
    dados.preco=ui->doubleSpinBox_raValor->text().replace(",",".");
    dados.get_receitadanca();
    plot_agenda();
    plot_tabelaReceita();

    ui->lineEdit_reId->clear();
    ui->lineEdit_reAbilidade->clear();
    ui->doubleSpinBox_raValor->clear();
}

void TelaDancarina::plot_tabelaReceita()
{
    Dancarina receit;
    receit.set_receitadanca();
    QJsonArray jarray=receit.jsonarrayDancarina;
    QJsonObject obj;
   if(jarray.size()==0){
       QMessageBox::information(this,"plot tabela :","lista vazia");
       return;}


   QStringList nomeClunas; // tem que ser igual os do pacote json acima
   nomeClunas <<"id"<<"dancarina"<<"preço";

   QStandardItemModel *model = new QStandardItemModel(jarray.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

   for(int i=0;i<nomeClunas.size();i++)
       model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

   for(int row=0;row<jarray.size();row++){
       obj =jarray[row].toObject();
       for(int col=0;col<nomeClunas.size();col++){
           QModelIndex index= model->index(row,col ,QModelIndex());
           model->setData(index,obj.value(nomeClunas[col]));

       }
   }
   ui->tableView_receita->setModel(model);

}

void TelaDancarina::plot_agenda()
{
    ui->treeWidget_agenda->clear();
      ui->treeWidget_agenda->setColumnCount(2);
      ui->treeWidget_agenda->setHeaderLabels(QStringList() << "Dançarina" << "habilidades"<<"tempo"<<"preço"<<"nome"<<"id");
         Dancarina abilidade;
         abilidade.set_danca();

         for(int i=0;i<abilidade.jsonarrayDancarina.size();i++){
     QJsonObject obj=abilidade.jsonarrayDancarina[i].toObject();
     QStringList listAbilidades=obj.value("habilidade").toString().split(" ");
     QStringList listTempo=obj.value("tempo dança").toString().split(" ");
     QStringList listPreco=obj.value("preço").toString().split(" ");
     for(int j=0;j<listAbilidades.size();j++)
     {

         if(listAbilidades[j]==""){
      listAbilidades.removeAt(j);
      listPreco.removeAt(j);
      listTempo.removeAt(j);

         }
     }

     qDebug()<<"lisad telaos"<<listAbilidades;
     addTreaAgenda(obj.value("dancarina").toString(),listAbilidades,listTempo,listPreco,obj.value("id").toString());
}
}

void TelaDancarina::on_tableView_dancarina_clicked(const QModelIndex &index)
{
    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_id->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->lineEdit_nome->setText(ind.data().toString());


}
