#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::aplicarFormatoAlTexto(std::function<void()> funcion, QTextCharFormat &formato) {
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    int inicio = ui->editorDeTexto->textCursor().selectionStart();
    int longitud = ui->editorDeTexto->textCursor().selectedText().length();

    if (longitud > 0) {
        cursor.setPosition(inicio);
        cursor.setPosition(inicio + longitud, QTextCursor::KeepAnchor);
    } else {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    funcion();

    cursor.mergeCharFormat(formato);
    cursor.clearSelection();
    cursor.setPosition(inicio + longitud, QTextCursor::MoveAnchor);

    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
}


void MainWindow::on_negrilla_clicked() //DONE
{

    QTextCharFormat formato = ui->editorDeTexto->textCursor().charFormat();
    auto negrilla = [&formato]() {
        formato.setFontWeight(formato.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    };
    aplicarFormatoAlTexto(negrilla, formato);
}



void MainWindow::on_subrayar_clicked()
{

    QTextCharFormat formato = ui->editorDeTexto->textCursor().charFormat();
    auto subrayado = [&formato]() {
        formato.setFontUnderline(!formato.fontUnderline());
    };
    aplicarFormatoAlTexto(subrayado, formato);
}

void MainWindow::on_cursiva_clicked()
{

    QTextCharFormat formato = ui->editorDeTexto->textCursor().charFormat();
    auto cursiva = [&formato]() {
        formato.setFontItalic(!formato.font().italic());
    };
    aplicarFormatoAlTexto(cursiva, formato);
}

void MainWindow::on_tachado_clicked()
{
    QTextCharFormat formato = ui->editorDeTexto->textCursor().charFormat();
    auto tachado = [&formato]() {
        formato.setFontStrikeOut(!formato.fontStrikeOut());
    };
    aplicarFormatoAlTexto(tachado, formato);
}


void MainWindow::on_vinetas_clicked()
{
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    cursor.insertText("• ");
    ui->editorDeTexto->setTextCursor(cursor);
}

void MainWindow::on_color_clicked()
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
            ui->editorDeTexto->insertPlainText("  ");
            cursor.setPosition(inicio+2);
            cursor.movePosition(QTextCursor::StartOfWord, QTextCursor::KeepAnchor);
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

//--------------------    Tamaños

void MainWindow::tamanoDeLetra(int nuevoTamano) {
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextCharFormat formato = cursor.charFormat();
    int inicio = (ui->editorDeTexto->textCursor().selectionStart()) + (ui->editorDeTexto->textCursor().selectedText().length());

    if (cursor.hasSelection()) {
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    } else {
        cursor.select(QTextCursor::Document);
        formato.setFontPointSize(nuevoTamano);
        cursor.mergeCharFormat(formato);
    }

    cursor.setPosition(inicio, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    ui->tamanoLetra->setValue(nuevoTamano);
    ui->editorDeTexto->setTextCursor(cursor);
    ui->editorDeTexto->setFocus();
    ui->tamanoDeLetra->setEditText(QString::number(nuevoTamano));
}

void MainWindow::on_tamanoLetra_valueChanged(int arg1)
{
    tamanoDeLetra(arg1);
}

void MainWindow::on_tamanoDeLetra_currentIndexChanged(int index)
{
    int tamano = (ui->tamanoDeLetra->itemText(index)).toInt();
    tamanoLetra = tamano;
    tamanoDeLetra(tamano);
}


void MainWindow::on_aumentarTamano_clicked()
{
    tamanoDeLetra(ui->tamanoLetra->value() + 1);
}
void MainWindow::on_disminuirTamano_clicked()
{
    tamanoDeLetra(ui->tamanoLetra->value() - 1);
}

//---------------     Aineados
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
