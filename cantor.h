#ifndef CANTOR_H
#define CANTOR_H
#include "funcionario.h"
#include "cliente.h"
#include <QJsonArray>
class Cantor:public Funcionario
{
    friend class Cliente;
public:
    QString musica,cantor,genero;
  QJsonArray  jsonArrayCantor;
    void set_musica();
    // insere as musicas desejada pelo evento
    void get_musica();

    Cantor();
    void get_salario();
};

#endif // CANTOR_H
