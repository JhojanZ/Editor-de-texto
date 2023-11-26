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

    //connect(ui->editorDeTexto, &QTextEdit::textChanged, this, &MainWindow::aplicarFormatoAlNuevoTexto);

    //TO DO:
    /*
     * ARREGLAR LOS CAMBIOS DE COLOR NO INTENCIONADOS
     * ARREGLAR EL COLOR SIN SELECCION
     * COmpletar el readme
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}





