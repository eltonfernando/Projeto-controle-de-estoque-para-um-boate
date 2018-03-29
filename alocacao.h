#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <QMainWindow>

namespace Ui {
class Alocacao;
}

class Alocacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alocacao(QWidget *parent = 0);
    ~Alocacao();

private slots:
    void on_calendarWidget_activated(const QDate &date);

    void on_pushButton_agendar_clicked();



private:
    Ui::Alocacao *ui;
    void plot_tabela(QJsonArray jarray);
    void set_tabela();
};

#endif // ALOCACAO_H
