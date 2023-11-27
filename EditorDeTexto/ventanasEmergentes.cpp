#include "mainwindow.h"
#include "ui_mainwindow.h"

//------------------------------------------ Extra
void MainWindow::on_actionComandos_triggered()
{
    infoVentana("Lista de comandos de la aplicación:                 \n\n\n- Nuevo: Ctrl+U\n- Abrir: Ctrl+A\n- Guardar: Ctrl+S\n- Imprimir: Ctrl+P\n- Eliminar: Ctrl+Delete  o  Ctrl+Supr\n-  Salir: Ctrl+W\n");
}
void MainWindow::on_actionAcerca_del_Auto_triggered()
{
    infoVentana("Proyecto creado por:\n\nJhojan Felipe Sánchez Zapata\n\n\nFuentes de las imagenes:\n\nhttps://www.flaticon.es/iconos-gratis/texto\nTexto iconos creados por Lizel Arina - Flaticon\nAlinear al centro iconos creados por Arkinasi - Flaticon");
}
void MainWindow::on_info_clicked()
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



