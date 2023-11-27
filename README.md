# Editor de Texto con QT 


## Descripción
Este proyecto universitario es un editor de texto simple desarrollado con el framework Qt. El editor proporciona una interfaz gráfica simple que permite a los usuarios crear, abrir, editar y guardar archivos de texto. Diseñado para ser fácil de usar, el editor aprovecha las capacidades de Qt para ofrecer todas las caracteristicas necesarias de un editor de texto.

El editor de texto desarrollado con Qt ofrece las siguientes funcionalidades principales:

- **Creación y Edición de Archivos:** Se puede crear nuevos archivos de texto con formato `.txt` y `rtf`, y editar archivos existentes de manera fácil y eficiente.
- **Manipulación del Texto:** El editor permite realizar operaciones básicas de edición, como cortar, copiar, pegar, deshacer y rehacer, para facilitar la manipulación del contenido.
- **Formato del Texto:** Tambien incluye opciones de formato del texto como ajustando el tamaño, color y estilo de fuente, así como alineando el texto las necesidades.
- **Gestión de Archivos:** Funciones como abrir, guardar, imprimir en pdf y cerrar archivos están disponibles para la necesidad del usuario.

## Tecnologias Usadas
- C++
- **Qt 6.5.3** (puedes descargarlo [aquí](https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4))
## Avance   
![1captura](https://github.com/JhojanZ/Editor-de-texto/assets/135383652/dc646956-96af-4528-9aa4-6b4b1ea2b125)
![2captura](https://github.com/JhojanZ/Editor-de-texto/assets/135383652/cd858236-6810-40ba-b10d-b61b31e19adc)

## Instrucciones de Compilación
Para compilar el proyecto, sigue estos pasos:

1. Clona el repositorio.
2. Abre el proyecto en el entorno de desarrollo Qt Creator.
3. Compila el código con ayuda del enterno Qt.

## Explicación de funciones
El código fuente se organiza en varios archivos dentro de la misma clase `mainwindow.h` para mejorar la legibilidad y mantener una estructura modular, esta tambien contiene todas las librerias necesarias para que funcione el codigo. A continuación, se detallan las principales funciones y su distribución:
### `mainwindow.cpp`
- Este archivo contiene la implementación de la clase `MainWindow`, que inicializa la ventana principal de la aplicación.
### `funcionesArchivos.cpp`
- Este archivo alberga funciones dedicadas a la lógica del manejo de archivos, como la apertura, lectura y escritura de archivos de texto.
- La dirección del archivo se guarda en la variable global de tipo QString`direccionArchivo`.
- Ejemplo:
```

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
```
### `editarTexto.cpp`
- Aquí se encuentran funciones responsables de la manipulación del texto dentro del QTextEdit (nombrado como `editorDeTexto`) en la libreria QTextEdit. Esto incluye funciones para agregar como tamaño, color, fuentes, entre otros.
- Ejemplo:
```
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
```

### `ventanasEmergentes.cpp`
- Este archivo agrupa funciones que manejan la creación y gestión de ventanas emergentes, como mensajes de error o confirmación.
- Ejemplo:
```
void MainWindow::infoVentana(QString mensaje){
    QMessageBox confirmar;
    confirmar.setText(mensaje);

    QPushButton *salir = confirmar.addButton("Salir", QMessageBox::AcceptRole);
    if(confirmar.clickedButton() == salir){
        //No hacer nada
    }
    confirmar.exec();
}
```
## Licencia
Este proyecto está bajo la Licencia Pública General de GNU (GNU GPL) v3.0. Puedes obtener una copia de la licencia en el archivo [LICENSE](archivo_licencia) o visitando el sitio web [Licencia Pública General de GNU](https://github.com/JhojanZ/Editor-de-texto/blob/master/LICENSE.txt).
## Contacto
- **Nombre:** Jhojan Felipe Sanchez Zapata
- **Institución:** Universidad Tecnologica de Pereira
- **Programa:** Ingeniería de Sistemas y Computación 
- **Facultad:** Facultad de Ingenierías
- **Curso:** Programación II
- **Correo Electrónico:** [j.sanchez10@utp.edu.co](mailto:j.sanchez10@utp.edu.co)
- **Perfil en GitHub:** [JhojanZ](https://github.com/JhojanZ)

**![Logo de la Universidad Tecnologica de Pereira](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Logo_U.T.P.png/320px-Logo_U.T.P.png)**
