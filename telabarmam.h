#ifndef TELABARMAM_H
#define TELABARMAM_H

#include <QMainWindow>

namespace Ui {
class TelaBarmam;
}

class TelaBarmam : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaBarmam(QWidget *parent = 0);
    ~TelaBarmam();

private slots:

    void on_tableView_estoque_clicked(const QModelIndex &index);

    void on_doubleSpinBox_preco_valueChanged(double arg1);

    void on_spinBox_quantidade_valueChanged(int arg1);

    void on_doubleSpinBox_lucro_valueChanged(double arg1);

    void on_tableView_listBarman_clicked(const QModelIndex &index);

    void on_pushButton_barmanVender_clicked();

    void on_pushButton_edtBebida_clicked();

    void on_pushButton_limpardados_clicked();

private:
    Ui::TelaBarmam *ui;
    void plot_tabela_estoque();
    void plot_tabela_barman();
    void plot_tela_bebidaVendida();
    void edit_lista_barman();
    QString lucros,quant;
};

#endif // TELABARMAM_H
