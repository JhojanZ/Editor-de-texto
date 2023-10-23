#include "creararchivo.h"
#include "ui_creararchivo.h"
#include "mainwindow.h"

#include <QDebug>
#include <QString>
#include <fstream>
#include <string>
#include <filesystem>

crearArchivo::crearArchivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crearArchivo)
{
    ui->setupUi(this);
}

crearArchivo::~crearArchivo()
{
    delete ui;
}



std::string nombreArchivo="";//variable global para el nombr del archivo
void crearArchivo::on_buttonBox_accepted()
{
    std::filesystem::path directorio("Archivos");
    if (!std::filesystem::exists(directorio)) {
        if (std::filesystem::create_directory(directorio)) {
            qDebug() << "Directorio 'Archivos' creado con éxito."; //ELIMINAR
        } else {
            qDebug() << "Error al crear el directorio 'Archivos'."; //ELIMINAR
        }
    }



    QString QnombreArchivo = ui->NombreArchivo->text();
    nombreArchivo = "Archivos/"+QnombreArchivo.toStdString()+".txt";
    std::ofstream nuevoArchivo(nombreArchivo);
    qDebug() << "Archivos/"+QnombreArchivo.toStdString()+".txt";

    if(!nuevoArchivo.is_open()){
        qDebug() << "El archivo no se abrio"; //ELIMINAR
        //Reemplazar esto por un label
    }else{
        qDebug() <<"Se creo el archivo"; //ELIMINAR
        //Reemplazar esto por un label
    }
    nuevoArchivo.close();
}

