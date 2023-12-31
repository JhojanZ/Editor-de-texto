#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_nuevoArchivo_clicked()
{
    MainWindow *nuevaVentana = new MainWindow();
    nuevaVentana->show();
}
void MainWindow::on_actionNuevo_triggered()//DONE
{
    on_abrirArchivo_clicked();
}

void MainWindow::on_abrirArchivo_clicked()
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
void MainWindow::on_actionAbrir_triggered() //DONE
{
    on_abrirArchivo_clicked();
}

void MainWindow::on_guardarArchivo_clicked()
{
    if(direccionArchivo.isEmpty()){
        direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto enriquecido(*.rtf);;Archivos de texto (*.txt);;Archivo Html (.html);;Todos los archivos (*.*)");
        if(!direccionArchivo.isEmpty()){
            guardarArchivo(direccionArchivo);
        }
    }else{
        guardarArchivo(direccionArchivo);
    }
}
void MainWindow::on_actionGuardar_triggered() //DONE
{
    on_guardarArchivo_clicked();
}
void MainWindow::on_guardar_clicked()
{
    on_guardarArchivo_clicked();
}
void MainWindow::guardarArchivo(QString direccionArchivo){
    QFile archivo(direccionArchivo);
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream insertar(&archivo);
        insertar<<ui->editorDeTexto->toHtml();
        archivo.close();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo crear el archivo.");
    }
}

void MainWindow::guardarPDF(QString direccionArchivo)
{
    if (!direccionArchivo.isEmpty()) {
        QTextDocument documento;
        QTextCursor cursor(&documento);
        cursor.insertHtml(ui->editorDeTexto->toHtml());

        QPrinter imprimir(QPrinter::PrinterResolution);
        imprimir.setOutputFormat(QPrinter::PdfFormat);
        imprimir.setOutputFileName(direccionArchivo);
        documento.print(&imprimir);

        //En caso de que falle, activar este codigo
        /*QPainter pintar;
        pintar.begin(&printer);

        documento.drawContents(&pintar);

        pintar.end();*/
    }
}
void MainWindow::on_actionExportar_triggered() //DONE
{
    guardarPDF(QFileDialog::getSaveFileName(this, "Exportar a PDF", QDir::homePath(), "Archivos PDF (*.pdf)"));
}

void MainWindow::on_imprimirArchivo_clicked()
{
    guardarPDF(QFileDialog::getSaveFileName(this, "Exportar a PDF", QDir::homePath(), "Archivos PDF (*.pdf)"));
}
void MainWindow::on_imprimirPDF_clicked()
{
    on_imprimirArchivo_clicked();
}
void MainWindow::on_guardarHTML_clicked()
{
    guardarArchivo(QFileDialog::getSaveFileName(this, "Exportar a Archivo Web", QDir::homePath(), "Archivos HTML (*.html)"));
}

void MainWindow::on_actionEliminar_triggered() //DONE
{
    on_eliminarArchivo_clicked();
}
void MainWindow::on_eliminarArchivo_clicked()
{
    QFile archivo(direccionArchivo);
    if(archivo.remove()){
        ui->editorDeTexto->setText("");
        //La funcion "infoVentana" se ubica en venatasEmergentex.cpp
        infoVentana("Archivo eliminado de forma exitosa");
    }else{
        infoVentana("No se pudo encontrar el archivo");
    }
}

void MainWindow::on_salirPrograma_clicked()
{
    QMessageBox confirmar;
    confirmar.setText("\t¿Seguro de que quieres salir?\n\nTodo progreso sin guardar se perdera.");

        QPushButton *aceptar = confirmar.addButton("Aceptar", QMessageBox::AcceptRole);
    QPushButton *cancelar = confirmar.addButton("Cancelar", QMessageBox::RejectRole);
    confirmar.exec();

    if (confirmar.clickedButton() == aceptar){
        close();
    }else if(confirmar.clickedButton() == cancelar){
        //No hacer nada
    }
}
void MainWindow::on_actionSalir_triggered() //DONE
{
    on_salirPrograma_clicked();
}

void MainWindow::on_deshacer_clicked()
{
    ui->editorDeTexto->undo();
}
void MainWindow::on_rehacer_clicked()
{
    ui->editorDeTexto->redo();
}

















