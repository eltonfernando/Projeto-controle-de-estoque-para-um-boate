#ifndef PORTARIA_H
#define PORTARIA_H
#include <QMainWindow>
#include <QStandardItemModel>
namespace Ui {
class Portaria;
}

class Portaria : public QMainWindow
{
    Q_OBJECT

public:
    explicit Portaria(QWidget *parent = 0);
    ~Portaria();

private slots:
    void on_pushButton_entrar_clicked();

    void on_pushButton_sair_clicked();

    void on_pushButton_addvip_clicked();

    void on_pushButton_removelistavip_clicked();

    void on_tableView_clientes_clicked(const QModelIndex &index);

private:
    Ui::Portaria *ui;
    void plot_tabela(QJsonArray Jlist);
    void set_tabela();
    QStandardItemModel *model;
};

#endif // PORTARIA_H
