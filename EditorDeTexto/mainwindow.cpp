//Jhojan Felipe Sánchez Zapata

#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    ui->tamanoDeLetra->setEditText("12");
}

MainWindow::~MainWindow()
{
    delete ui;
}













