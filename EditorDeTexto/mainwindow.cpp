//Jhojan Felipe Sánchez Zapata
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);


    //TO DO:
    /*
     * ARREGLAR LOS CAMBIOS DE COLOR NO INTENCIONADOS
     * ARREGLAR EL COLOR SIN SELECCION
     * IMPRIMIR LAS IMAGENES...
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_agregarImagenes_clicked()
{
    QString rutaImagen = QFileDialog::getOpenFileName(this, "Seleccionar imagen", QDir::homePath(), "Imágenes (*.png *.jpg *.bmp)");
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    if (!rutaImagen.isEmpty()) {
        QTextCursor cursor = ui->editorDeTexto->textCursor();

        // Insertar la imagen usando QTextImageFormat
        QTextImageFormat formatoImagen;
        formatoImagen.setName(rutaImagen);
        formatoImagen.setWidth(150);  // Establecer el ancho deseado, puedes ajustar esto según tus necesidades
        formatoImagen.setHeight(150);  // Establecer la altura deseada, puedes ajustar esto según tus necesidades

        cursor.insertImage(formatoImagen);

        /*
        QImage imagen(rutaImagen);
        if (!imagen.isNull()) {
            // Ajustar el tamaño deseado (por ejemplo, 100x100 píxeles)
            QSize nuevoTamano(100, 100);
            imagen = imagen.scaled(nuevoTamano, Qt::KeepAspectRatio);

            cursor.insertImage(imagen, "etiqueta_de_la_imagen");
        }*/
    }


    // Verificar si la selección es una imagen
    if (cursor.charFormat().isImageFormat()) {

        // Cargar la imagen actual en un QImage
        QImage imagen(rutaImagen);

        // Ajustar el tamaño deseado (por ejemplo, 150x150 píxeles)
        QSize nuevoTamano(150, 150);
        imagen = imagen.scaled(nuevoTamano, Qt::KeepAspectRatio);

        // Insertar la nueva imagen
        cursor.removeSelectedText();
        cursor.insertImage(imagen, rutaImagen);
    }

}


void MainWindow::on_cambiarTamanoImagen_clicked()
{
    // Obtener el cursor y seleccionar la imagen actual
    QTextCursor cursor = ui->editorDeTexto->textCursor();
    cursor.select(QTextCursor::BlockUnderCursor);

    // Verificar si la selección es una imagen
    if (cursor.charFormat().isImageFormat()) {
        // Obtener la imagen actual
        QTextImageFormat formatoImagen = cursor.charFormat().toImageFormat();
        QString nombreImagen = formatoImagen.name();

        // Cargar la imagen actual en un QImage
        QImage imagen(nombreImagen);

        // Ajustar el tamaño deseado (por ejemplo, 150x150 píxeles)
        QSize nuevoTamano(150, 150);
        imagen = imagen.scaled(nuevoTamano, Qt::KeepAspectRatio);

        // Insertar la nueva imagen
        cursor.removeSelectedText();
        cursor.insertImage(imagen, nombreImagen);
    }
}














void MainWindow::on_agregarTabla_clicked()
{
    int filas = 3;
    int columnas = 4;

    QTextCursor cursor = ui->editorDeTexto->textCursor();
    QTextTableFormat formatoTabla;
    formatoTabla.setBorder(10); // Grosor del borde

    cursor.insertTable(filas, columnas, formatoTabla);
}

/*
QTextDocument *document = new QTextDocument;

// Insertar una imagen
QTextImageFormat imageFormat;
imageFormat.setName("ruta_de_la_imagen.png");
imageFormat.setWidth(100);  // Ajusta el ancho de la imagen según sea necesario
imageFormat.setHeight(100); // Ajusta la altura de la imagen según sea necesario
QTextCursor cursor(document);
cursor.insertImage(imageFormat);

// Insertar una tabla
QTextTableFormat tableFormat;
tableFormat.setCellPadding(5);
tableFormat.setCellSpacing(0);
QTextTable *table = cursor.insertTable(3, 3, tableFormat);
for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
        QTextTableCell cell = table->cellAt(row, col);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QString("Celda %1,%2").arg(row).arg(col));
    }
}*/







