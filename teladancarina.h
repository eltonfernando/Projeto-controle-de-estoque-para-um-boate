#ifndef TELADANCARINA_H
#define TELADANCARINA_H

#include <QMainWindow>
#include <QJsonArray>
#include <QTreeWidgetItem>
namespace Ui {
class TelaDancarina;
}

class TelaDancarina : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaDancarina(QWidget *parent = 0);
    ~TelaDancarina();

private slots:
    void on_pushButton_addAbilidade_clicked();

    void on_lineEdit_id_editingFinished();

    void on_treeWidget_abilidade_itemActivated(QTreeWidgetItem *item, int column);


    void on_timeEdit_agendaTempo_userTimeChanged(const QTime &time);



    void on_pushButton_agenda_clicked();

    void on_treeWidget_agenda_itemActivated(QTreeWidgetItem *item, int column);

    void on_pushButton_receita_clicked();

    void on_tableView_dancarina_clicked(const QModelIndex &index);

private:
    Ui::TelaDancarina *ui;
    double precoPorHoras;
    QJsonArray jsonArrayTelaDancarina;
    void plot_tabelaReceita();
    void plot_agenda();
    void plot_abilidades();
    void plot_tabela(QJsonArray jarray);
    void addTreaAgenda(QString nome,QStringList abilidades,QStringList tempo,QStringList preco,QString id);
    void addTree(QString nome,QStringList abilidades,QStringList tempo,QStringList preco,QString id);
};

#endif // TELADANCARINA_H
