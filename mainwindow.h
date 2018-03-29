#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtCore>
//#include <QtGui>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void set_lista();
    ~MainWindow();

private slots:
    void on_actionCliente_triggered();

    void on_pushButton_presente_clicked();

    void on_pushButton_todosCliente_clicked();



    void on_actiondados_de_pessoas_triggered();

    void on_pushButton_vip_clicked();

    void on_pushButton_funcionarios_clicked();


    void on_actionAloca_o_triggered();

    void on_actionPortaria_triggered();

    void on_actionDan_arina_triggered();

    void on_actionBarman_triggered();

    void on_actionCantor_triggered();

    void on_pushButton_atualizar_clicked();



    void on_tableView_dados_activated(const QModelIndex &index);

    void on_pushButton_pagarfun_clicked();

    void on_pushButton_pagarConta_clicked();

    void on_tableView_contas_activated(const QModelIndex &index);

private:
    void plot_tabela(QJsonArray Jlist);
    void plot_tabelaEstoque(QJsonArray Jlist);
    void plot_tabelaContas();
    void economia();
    Ui::MainWindow *ui;
    QStandardItemModel *model;

};

#endif // MAINWINDOW_H
