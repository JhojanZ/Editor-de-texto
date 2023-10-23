#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <filesystem>
#include <fstream>
#include <string>

#include <QString>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ----------------------------------------Funciones con Archivos
QString direccionArchivo = "";

void MainWindow::on_actionNuevo_triggered()//DONE
{
    MainWindow *nuevaVentana = new MainWindow();
    nuevaVentana->show();
}

void MainWindow::on_actionAbrir_triggered() //DONE
{
    direccionArchivo = QFileDialog::getOpenFileName(this, "Abrir Archivo", QDir::homePath());
    if (!direccionArchivo.isEmpty()) {
        QFile archivo(direccionArchivo);
        if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&archivo);
            if(archivo.size() == 0){
                QMessageBox::information(this, "Archivo vacío", "El archivo está vacío.");
            }else{
                QString contenidoDelArchivo = in.readAll();
                ui->editorDeTexto->setPlainText(contenidoDelArchivo);
            }
            archivo.close();
        }else {
            QMessageBox::critical(this, "Error", "No se pudo abrir el archivo.");
        }
    }
}

void MainWindow::on_actionGuardar_triggered() //DONE (mejorar)
{
    if(direccionArchivo.isEmpty()){
        direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt)");//;;Todos los archivos (*.*)
        if(!direccionArchivo.isEmpty()){
            QFile archivo(direccionArchivo);
            if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&archivo);
                out<<ui->editorDeTexto->toPlainText();
                archivo.close();
            } else {
                QMessageBox::critical(this, "Error", "No se pudo crear el archivo.");
            }
        }
    }else{//Reducir el codigo copy-paste
        qDebug()<<direccionArchivo;
        QFile archivo(direccionArchivo);
        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&archivo);
            out<<ui->editorDeTexto->toPlainText();
            archivo.close();
        } else {
            QMessageBox::critical(this, "Error", "No se pudo crear el archivo.");
        }
    }
}

void MainWindow::on_actionExportar_triggered() //DONE
{
    QString direccionArchivo = QFileDialog::getSaveFileName(this, "Exportar a PDF", QDir::homePath(), "Archivos PDF (*.pdf)");
    if (!direccionArchivo.isEmpty()) {
        QTextDocument documento;
        QTextCursor cursor(&documento);
        cursor.insertText(ui->editorDeTexto->toPlainText());

        QPrinter imprimir(QPrinter::PrinterResolution);
        imprimir.setOutputFormat(QPrinter::PdfFormat);
        imprimir.setOutputFileName(direccionArchivo);
        documento.print(&imprimir);
    }
}

void MainWindow::on_actionSalir_triggered() //DONE
{
    close();
}

// ----------------------------------------Funciones de Diseño de Texto

