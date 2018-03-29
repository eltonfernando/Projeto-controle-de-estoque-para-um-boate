#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QJsonArray>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    void set_login();
   QJsonArray jsonarrayLogin;
   void chama_cantor();
   void chama_barmam();
   void chama_dancariona();
   void chama_gerente();

};

#endif // LOGIN_H
