#ifndef TELACANTOR_H
#define TELACANTOR_H

#include <QMainWindow>

namespace Ui {
class TelaCantor;
}

class TelaCantor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaCantor(QWidget *parent = 0);
    ~TelaCantor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TelaCantor *ui;
    void plot_tela_musica();
};

#endif // TELACANTOR_H
