#ifndef CADASTRO_H
#define CADASTRO_H

#include <QMainWindow>

namespace Ui {
class Cadastro;
}

class Cadastro : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cadastro(QWidget *parent = 0);
    ~Cadastro();

private slots:
    void on_lineEdit_Cpf_editingFinished();

    void on_lineEdit_Cpf_textEdited(const QString &CPF);

    void on_pushButton_novoCliente_clicked();

    void on_pushButton_contratar_clicked();

private:
    Ui::Cadastro *ui;
};

#endif // CADASTRO_H
