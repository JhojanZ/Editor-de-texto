//Jhojan Felipe Sánchez Zapata
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
#include <QFontDatabase>
#include <QColorDialog>
#include <QKeyEvent>


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

// ----------------------------------------Funciones con Archivos  //falta aplicar comandos
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

void MainWindow::on_actionGuardar_triggered() //DONE
{
    if(direccionArchivo.isEmpty()){
        direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt);;Todos los archivos (*.*)");
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
    }else{
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

void MainWindow::on_actionEliminar_triggered() //DONE
{
    QFile archivo(direccionArchivo);
    archivo.remove();
    ui->editorDeTexto->setText("");
}

void MainWindow::on_actionSalir_triggered() //DONE
{
    QMessageBox confirmar;
    confirmar.setText("        ¿Seguro de que quieres salir?\n\nTodo progreso sin guardar se perdera.");

    QPushButton *aceptar = confirmar.addButton("Aceptar", QMessageBox::AcceptRole);
    QPushButton *cancelar = confirmar.addButton("Cancelar", QMessageBox::RejectRole);
    confirmar.exec();

    if (confirmar.clickedButton() == aceptar) {
        close();
    }
}

//----------------------------------------Funciones con Comandos

void MainWindow::keyPressEvent(QKeyEvent *evento)//DONE
{
    //Nuevo
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_U) {
        MainWindow *nuevaVentana = new MainWindow();
        nuevaVentana->show();
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento);
    }

    //Abrir
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_A) {
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
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento);
    }

    //Guardar
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_S) {
        if(direccionArchivo.isEmpty()){
            direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt);;Todos los archivos (*.*)");
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
        }else{
            QFile archivo(direccionArchivo);
            if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&archivo);
                out<<ui->editorDeTexto->toPlainText();
                archivo.close();
            } else {
                QMessageBox::critical(this, "Error", "No se pudo crear el archivo.");
            }
        }
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento); // Continúa el procesamiento de eventos normales
    }

    //Exportar
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_P) {
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
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento); // Continúa el procesamiento de eventos normales
    }

    //Eliminar
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_Delete) {
        QFile archivo(direccionArchivo);
        archivo.remove();
        ui->editorDeTexto->setText("");
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento); // Continúa el procesamiento de eventos normales
    }

    //Salir
    if (evento->modifiers() == Qt::ControlModifier && evento->key() == Qt::Key_W) {
        QMessageBox confirmar;
        confirmar.setText("        ¿Seguro de que quieres salir?\n\nTodo progreso sin guardar se perdera.");

        QPushButton *aceptar = confirmar.addButton("Aceptar", QMessageBox::AcceptRole);
        QPushButton *cancelar = confirmar.addButton("Cancelar", QMessageBox::RejectRole);
        confirmar.exec();

        if (confirmar.clickedButton() == aceptar) {
            close();
        }
        on_actionGuardar_triggered();
    } else {
        QMainWindow::keyPressEvent(evento); // Continúa el procesamiento de eventos normales
    }


    /*

    // Color (se aplica solo al escribir)
    if (evento->modifiers() == Qt::NoModifier && evento->text() != "") {
        QTextCursor cursor = ui->editorDeTexto->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.setCharFormat(colorSeleccionado); // Aplicar formato de color
        cursor.insertText(evento->text()); // Insertar el texto del evento
    } else {
        QMainWindow::keyPressEvent(evento);
    }

    */
}

// ----------------------------------------Funciones de Diseño de Texto //Falta corregir el cursor

void MainWindow::on_negrilla_clicked() //DONE
{
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    if(longitud > 0){
        cursor.setPosition(inicio);
        cursor.setPosition(inicio + longitud, QTextCursor::KeepAnchor);
    }else{
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat formato = cursor.charFormat();
    if (formato.fontWeight() == QFont::Bold) {
        formato.setFontWeight(formato.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold); // Cambia negrilla
        cursor.mergeCharFormat(formato);
    } else {
        formato.setFontWeight(formato.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold); // Cambia negrilla
        cursor.setBlockCharFormat(formato);
    }
    inicio += longitud;
    cursor.mergeCharFormat(formato);
    cursor.setPosition(inicio);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

void MainWindow::on_subrayar_clicked() //DONE
{
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    if(longitud > 0){
        cursor.setPosition(inicio);
        cursor.setPosition(inicio + longitud, QTextCursor::KeepAnchor);
    }else{
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat formato = cursor.charFormat();
    if (formato.fontUnderline()) {
        formato.setFontUnderline(false);
    } else {
        formato.setFontUnderline(true);
    }
    inicio += longitud;
    cursor.mergeCharFormat(formato);
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

void MainWindow::on_cursiva_clicked() //DONE
{
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    if(longitud > 0){
        cursor.setPosition(inicio);
        cursor.setPosition(inicio + longitud, QTextCursor::KeepAnchor);
    }else{
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat formato = cursor.charFormat();
    if (formato.font().italic()) {
        formato.setFontItalic(false);
    } else {
        formato.setFontItalic(true);
    }
    inicio += longitud;
    cursor.mergeCharFormat(formato);
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

void MainWindow::on_tachado_clicked() //DONE
{
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    if(longitud > 0){
        cursor.setPosition(inicio);
        cursor.setPosition(inicio + longitud, QTextCursor::KeepAnchor);
    }else{
        cursor.select(QTextCursor::WordUnderCursor);
    }
    QTextCharFormat formato = cursor.charFormat();
    if (formato.fontStrikeOut()) {
        formato.setFontStrikeOut(false);
    } else {
        formato.setFontStrikeOut(true);
    }
    inicio += longitud;
    cursor.mergeCharFormat(formato);
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

void MainWindow::on_color_clicked()//DONE
{
    QColor color = QColorDialog::getColor(Qt::black , this, "Seleccionar color de fuente");
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    //
    if (color.isValid()) {
        colorSeleccionado = color;
        formato.setForeground(QBrush(color));
        if (cursor.hasSelection()) {
            cursor.mergeCharFormat(formato);
        } else {
            //formato.setForeground(QBrush(color));
            //cursor.mergeCharFormat(formato);
            ui->editorDeTexto->insertPlainText(" l");
            cursor.setPosition(inicio+2);
            cursor.movePosition(QTextCursor::StartOfWord, QTextCursor::KeepAnchor);
            cursor.mergeCharFormat(formato);
        }
    }
    cursor.setPosition(inicio+2, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

/*void MainWindow::on_color_clicked()
{
    //QColor color = QColorDialog::getColor(Qt::black, this, "Seleccionar color de fuente");
    QColor color = QColorDialog::getColor(Qt::black, this, "Seleccionar color de fuente");
    if (color.isValid()) {
        colorSeleccionado = color;

        // Guarda el color seleccionado sin aplicarlo inmediatamente
        formatoColor = QTextCharFormat();
        formatoColor.setForeground(QBrush(color));
    }
}
*/




//Tamaños //DONE
void MainWindow::on_tamano_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        formato.setFontPointSize(ui->tamanoLetra->value());
        cursor.mergeCharFormat(formato);
    } else {
        cursor.select(QTextCursor::Document);
        formato.setFontPointSize(ui->tamanoLetra->value());
        cursor.mergeCharFormat(formato);
    }
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}
void MainWindow::on_aumentarTamano_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int nuevoTamano = ui->tamanoLetra->value() + 1;
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextCharFormat formato = cursor.charFormat();
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    } else {
        cursor.select(QTextCursor::Document);
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    }
    ui->tamanoLetra->setValue(nuevoTamano);
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}
void MainWindow::on_disminuirTamano_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int nuevoTamano = ui->tamanoLetra->value() - 1;
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextCharFormat formato = cursor.charFormat();
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    } else {
        cursor.select(QTextCursor::Document);
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    }
    ui->tamanoLetra->setValue(nuevoTamano);
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

//Alineados //DONE
void MainWindow::on_alineadoIzquierda_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextBlockFormat formatoDelBloque = cursor.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignLeft);
        cursor.mergeBlockFormat(formatoDelBloque);
    } else {
        QTextCursor inicioDelBloque = cursor;
        inicioDelBloque.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock);
        QTextBlockFormat formatoDelBloque = inicioDelBloque.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignLeft);
        inicioDelBloque.setBlockFormat(formatoDelBloque);
        cursor.setBlockFormat(formatoDelBloque);
    }
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}
void MainWindow::on_alineadoCentrado_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextBlockFormat formatoDelBloque = cursor.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignCenter);
        cursor.mergeBlockFormat(formatoDelBloque);
    } else {
        QTextCursor inicioDelBloque = cursor;
        inicioDelBloque.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock);
        QTextBlockFormat formatoDelBloque = inicioDelBloque.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignCenter);
        inicioDelBloque.setBlockFormat(formatoDelBloque);
        cursor.setBlockFormat(formatoDelBloque);
    }
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}
void MainWindow::on_alineadoDerecha_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextBlockFormat formatoDelBloque = cursor.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(formatoDelBloque);
    } else {
        QTextCursor inicioDelBloque = cursor;
        inicioDelBloque.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock);
        QTextBlockFormat formatoDelBloque = inicioDelBloque.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignRight);
        inicioDelBloque.setBlockFormat(formatoDelBloque);
        cursor.setBlockFormat(formatoDelBloque);
    }
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}
void MainWindow::on_alineadoJustificado_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextBlockFormat formatoDelBloque = cursor.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignJustify);
        cursor.mergeBlockFormat(formatoDelBloque);
    } else {
        QTextCursor inicioDelBloque = cursor;
        inicioDelBloque.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock);
        QTextBlockFormat formatoDelBloque = inicioDelBloque.blockFormat();
        formatoDelBloque.setAlignment(Qt::AlignJustify);
        inicioDelBloque.setBlockFormat(formatoDelBloque);
        cursor.setBlockFormat(formatoDelBloque);
    }
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

void MainWindow::on_fuentes_currentFontChanged(const QFont &f)//DONE
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    formato.setFont(f);
    cursor.mergeCharFormat(formato);
    ui->editorDeTexto->setTextCursor(cursor);
}

void MainWindow::on_imprimirPDF_clicked() //DONE
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

//------------------------------------------ Extra
void MainWindow::on_actionComandos_triggered() //DONE
{
    QMessageBox confirmar;
    confirmar.setText("Lista de comandos de la aplicación:\n\n\n- Nuevo: Ctrl+U\n- Abrir: Ctrl+A\n- Guardar: Ctrl+S\n- Imprimir: Ctrl+P\n- Eliminar: Ctrl+Delete  o  Ctrl+Supr\n-  Salir: Ctrl+W\n");

    QPushButton *salir = confirmar.addButton("Salir", QMessageBox::AcceptRole);
    confirmar.exec();
}

void MainWindow::on_actionAcerca_del_Auto_triggered() //DONE
{
    QMessageBox confirmar;
    confirmar.setText("Proyecto creado por:\n\nJhojan Felipe Sánchez Zapata");

    QPushButton *salir = confirmar.addButton("Salir", QMessageBox::AcceptRole);
    confirmar.exec();
}

void MainWindow::on_deshacer_clicked()
{
    ui->editorDeTexto->undo();
}


void MainWindow::on_rehacer_clicked()
{
    ui->editorDeTexto->redo();
}

