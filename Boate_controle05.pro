#-------------------------------------------------
#
# Project created by QtCreator 2018-01-28T12:59:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boate_controle05
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cadastro.cpp \
    boate.cpp \
    cantor.cpp \
    cliente.cpp \
    dancarina.cpp \
    funcionario.cpp \
    gerente.cpp \
    compras.cpp \
    alocacao.cpp \
    portaria.cpp \
    teladancarina.cpp \
    login.cpp \
    telabarmam.cpp \
    telacantor.cpp

HEADERS += \
        mainwindow.h \
    cadastro.h \
    boate.h \
    cantor.h \
    cliente.h \
    dancarina.h \
    funcionario.h \
    gerente.h \
    pessoa.h \
    compras.h \
    alocacao.h \
    portaria.h \
    teladancarina.h \
    login.h \
    telabarmam.h \
    telacantor.h

FORMS += \
        mainwindow.ui \
    cadastro.ui \
    compras.ui \
    alocacao.ui \
    portaria.ui \
    teladancarina.ui \
    login.ui \
    telabarmam.ui \
    telacantor.ui

RESOURCES += \
    mures.qrc

DISTFILES +=
