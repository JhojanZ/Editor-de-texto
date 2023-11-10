//Jhojan Felipe Sánchez Zapata
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt);;Archivos de texto enriquecido(*.rtf);;Todos los archivos (*.*)");
        if(!direccionArchivo.isEmpty()){
            guardarArchivo(direccionArchivo);
        }
    }else{
        guardarArchivo(direccionArchivo);
    }
}
void MainWindow::guardarArchivo(QString nombreArchivo){
    QFile archivo(nombreArchivo);
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream insertar(&archivo);
        insertar<<ui->editorDeTexto->toHtml();
        archivo.close();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo crear el archivo.");
    }
}

void MainWindow::on_actionExportar_triggered() //DONE
{
    guardarPDF(QFileDialog::getSaveFileName(this, "Exportar a PDF", QDir::homePath(), "Archivos PDF (*.pdf)"));
}
void MainWindow::guardarPDF(QString direccionArchivo)
{
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

//----------------------------------------Funciones con Comandos


void MainWindow::keyPressEvent(QKeyEvent *evento)//DONE
{

    /* Color (se aplica solo al escribir)
    if (evento->modifiers() == Qt::NoModifier && evento->text() != "") {
        QTextCursor cursor = ui->editorDeTexto->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.setCharFormat(colorSeleccionado); // Aplicar formato de color
        cursor.insertText(evento->text()); // Insertar el texto del evento
    } else {
        QMainWindow::keyPressEvent(evento);
    }*/

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
    alinear(Qt::AlignLeft);
}
void MainWindow::on_alineadoCentrado_clicked()
{
    alinear(Qt::AlignCenter);
}
void MainWindow::on_alineadoDerecha_clicked()
{
    alinear(Qt::AlignRight);
}
void MainWindow::on_alineadoJustificado_clicked()
{
    alinear(Qt::AlignJustify);
}
void MainWindow::alinear(Qt::AlignmentFlag modo){
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());
    if (cursor.hasSelection()) {
        QTextBlockFormat formatoDelBloque = cursor.blockFormat();
        formatoDelBloque.setAlignment(modo);
        cursor.mergeBlockFormat(formatoDelBloque);
    } else {
        QTextCursor inicioDelBloque = cursor;
        inicioDelBloque.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock);
        QTextBlockFormat formatoDelBloque = inicioDelBloque.blockFormat();
        formatoDelBloque.setAlignment(modo);
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
    guardarPDF(QFileDialog::getSaveFileName(this, "Exportar a PDF", QDir::homePath(), "Archivos PDF (*.pdf)"));
}

void MainWindow::on_guardar_clicked()
{
    //unificar señales para solo usar una funcion
    if(direccionArchivo.isEmpty()){
        direccionArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt);;Archivos de texto enriquecido(*.rtf);;Todos los archivos (*.*)");
        if(!direccionArchivo.isEmpty()){
            guardarArchivo(direccionArchivo);
        }
    }else{
        guardarArchivo(direccionArchivo);
    }
}

void MainWindow::on_deshacer_clicked()
{
    ui->editorDeTexto->undo();
}
void MainWindow::on_rehacer_clicked()
{
    ui->editorDeTexto->redo();
}

//------------------------------------------ Extra
void MainWindow::on_actionComandos_triggered() //DONE
{
    infoVentana("Lista de comandos de la aplicación:                 \n\n\n- Nuevo: Ctrl+U\n- Abrir: Ctrl+A\n- Guardar: Ctrl+S\n- Imprimir: Ctrl+P\n- Eliminar: Ctrl+Delete  o  Ctrl+Supr\n-  Salir: Ctrl+W\n");
}
void MainWindow::on_actionAcerca_del_Auto_triggered() //DONE
{
    infoVentana("Proyecto creado por:\n\nJhojan Felipe Sánchez Zapata\n\n\nFuentes de las imagenes:\n\nhttps://www.flaticon.es/iconos-gratis/texto\nTexto iconos creados por Lizel Arina - Flaticon\nAlinear al centro iconos creados por Arkinasi - Flaticon");
}
void MainWindow::infoVentana(QString mensaje){
    QMessageBox confirmar;
    confirmar.setText(mensaje);

    QPushButton *salir = confirmar.addButton("Salir", QMessageBox::AcceptRole);
    if(confirmar.clickedButton() == salir){
        //No hacer nada
    }
    confirmar.exec();
}
