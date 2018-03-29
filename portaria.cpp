#include "portaria.h"
#include "ui_portaria.h"
#include "cliente.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDebug>
Portaria::Portaria(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Portaria)
{
    ui->setupUi(this);

    set_tabela();
}

Portaria::~Portaria()
{
    delete ui;
}

void Portaria::on_pushButton_entrar_clicked()
{
    // entrada de cliente
    QString id=ui->lineEdit_entradaCodigo->text();
    QString valor_entrada=ui->doubleSpinBox_precoEntrada->text().replace(",",".");
    bool  descontoEstudante=ui->checkBox_DescontoEstudante->isChecked();
    bool  descontoVip=ui->checkBox_descontoVip->isChecked();
// add ao caixa
Cliente idEdit;
idEdit.codigo_cliente = id;
idEdit.get_clientepresente("yes");
Boate caixa;
caixa.receita=ui->doubleSpinBox_precoEntrada->text().replace(",",".");
caixa.lucro=ui->doubleSpinBox_precoEntrada->text().replace(",",".");
caixa.get_economia();
}

void Portaria::on_pushButton_sair_clicked()
{
    // saida de cliente
Cliente idEdit;
idEdit.codigo_cliente = ui->lineEdit_entradaCodigo->text();
idEdit.get_clientepresente("NO");
}

void Portaria::on_pushButton_addvip_clicked()
{
    Cliente idEdit;
    idEdit.codigo_cliente = ui->lineEdit_entradaCodigo->text();
    idEdit.get_clientevip("yes");
}

void Portaria::on_pushButton_removelistavip_clicked()
{
    Cliente idEdit;
   idEdit.codigo_cliente = ui->lineEdit_entradaCodigo->text();
    idEdit.get_clientevip("NO");
}
void Portaria::plot_tabela(QJsonArray Jlist)
{
     QJsonObject obj;
    if(Jlist.size()==0){
        QMessageBox::information(this,"plot tabela :","lista vazia");
        return;}

    QStringList nomeClunas; // tem que ser igual os do pacote json acima
    nomeClunas <<"id"<<"nome"<<"cpf"<<"rg";/*<<"presente"<<""
   "sexo"<<"cpf"<<"rg"<<"orgaoexpedidor"<<"carteiradetrabalho"
   ""<<"profissao"<<"email"<<"telefone"<<"endereco"<<"cep"<<""
   "banco"<<"agenciabanco"<<"contabanco"<<"tempodecontrato"<<"expediente"<<"salario";*/
    QStandardItemModel *model = new QStandardItemModel(Jlist.size(),nomeClunas.size(),this); //2 Rows and 3 Columns (2,3,this)

    for(int i=0;i<nomeClunas.size();i++)
        model->setHorizontalHeaderItem(i, new QStandardItem(nomeClunas[i]));

   // QList<QStandardItem *> items;

    for(int row=0;row<Jlist.size();row++){
        obj =Jlist[row].toObject();
        for(int col=0;col<nomeClunas.size();col++){
           // QString elemento=obj.value(nomeClunas[col]).toString();
            QModelIndex index= model->index(row,col ,QModelIndex());
            model->setData(index,obj.value(nomeClunas[col]));

        }
    }

    ui->tableView_clientes->setModel(model);
}

void Portaria::set_tabela()
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
}

void Portaria::on_tableView_clientes_clicked(const QModelIndex &index)
{
    QModelIndex ind=index.sibling(index.row(),0);
    ui->lineEdit_entradaCodigo->setText(ind.data().toString());
    ind=index.sibling(index.row(),1);
    ui->lineEdit_nome->setText(ind.data().toString());
   }
