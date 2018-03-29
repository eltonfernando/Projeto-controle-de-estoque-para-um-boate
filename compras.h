#ifndef COMPRAS_H
#define COMPRAS_H

#include <QMainWindow>

namespace Ui {
class Compras;
}

class Compras : public QMainWindow
{
    Q_OBJECT

public:
    explicit Compras(QWidget *parent = 0);
    ~Compras();

private slots:


    void on_pushButton_Comprar_clicked();


    void on_lineEdit_produto_editingFinished();

    void on_pushButton_addConta_clicked();

private:
    Ui::Compras *ui_telaCompras;
};

#endif // COMPRAS_H
