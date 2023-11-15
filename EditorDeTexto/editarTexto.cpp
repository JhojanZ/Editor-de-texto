#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_listaBolitas_clicked()
{

    if(listaBolita == false){
        listaBolita = true;
        //int inicio = ui->editorDeTexto->textCursor().selectionStart();
        QTextCursor cursor = ui->editorDeTexto->textCursor();
        //QTextCharFormat formato = cursor.charFormat();
        ui->editorDeTexto->insertPlainText("• ");
        //cursor.setPosition(inicio, QTextCursor::MoveAnchor);
        ui->editorDeTexto->setTextCursor(cursor);
    }else{
        listaBolita = false;
    }
    qDebug() << listaBolita;
}


void MainWindow::on_color_clicked()//DONE
{
    QColor color = QColorDialog::getColor(Qt::black , this, "Seleccionar color de fuente");
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();
    if (color.isValid()) {
        formato.setForeground(color);
        if (cursor.hasSelection()) {
            cursor.mergeCharFormat(formato);
            ui->editorDeTexto->mergeCurrentCharFormat(formato);
        } else {
            //ui->editorDeTexto->insertPlainText("  ");
            //cursor.setPosition(inicio+2);
            //cursor.movePosition(QTextCursor::StartOfWord, QTextCursor::KeepAnchor);
            cursor.mergeCharFormat(formato);
            ui->editorDeTexto->mergeCurrentCharFormat(formato);
        }
    }
    inicio += longitud;
    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}

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
