# Editor de Texto con QT 

## Descripción
Este proyecto universitario es un editor de texto simple desarrollado con el framework Qt. El editor proporciona una interfaz gráfica simple que permite a los usuarios crear, abrir, editar y guardar archivos de texto. Diseñado para ser fácil de usar, el editor aprovecha las capacidades de Qt para ofrecer todas las caracteristicas necesarias de un editor de texto.

El editor de texto desarrollado con Qt ofrece las siguientes funcionalidades principales:

<<<<<<< HEAD
- **Creación y Edición de Archivos:** Se puede crear nuevos archivos de texto con formato `.txt` y `rtf`, y editar archivos existentes de manera fácil y eficiente.
- **Manipulación del Texto:** El editor permite realizar operaciones básicas de edición, como cortar, copiar, pegar, deshacer y rehacer, para facilitar la manipulación del contenido.
- **Formato del Texto:** Tambien incluye opciones de formato del texto como ajustando el tamaño, color y estilo de fuente, así como alineando el texto las necesidades.
- **Gestión de Archivos:** Funciones como abrir, guardar, imprimir en pdf y cerrar archivos están disponibles para la necesidad del usuario.

## Tecnologias Usadas
- C++
- **Qt 6.5.3** (puedes descargarlo [aquí](https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4))
## Avance
<!-- Colocar imganes del proyecto -->

## Instrucciones de Compilación
Para compilar el proyecto, sigue estos pasos:

1. Clona el repositorio.
2. Abre el proyecto en el entorno de desarrollo Qt Creator.
3. Compila el código utilizando el compilador compatible con tu plataforma.

Estas son solo indicaciones generales; asegúrate de incluir detalles

## Explicación de funciones
El código fuente se organiza en varios archivos dentro de la misma clase `mainwindow.h` para mejorar la legibilidad y mantener una estructura modular, esta tambien contiene todas las librerias necesarias para que funcione el codigo. A continuación, se detallan las principales funciones y su distribución:
### `mainwindow.cpp`
- Este archivo contiene la implementación de la clase `MainWindow`, que inicializa la ventana principal de la aplicación.
### `funcionesArchivos.cpp`
- Este archivo alberga funciones dedicadas a la lógica del manejo de archivos, como la apertura, lectura y escritura de archivos de texto.
- La dirección del archivo se guarda en la variable global de tipo QString`direccionArchivo`.
- Ejemplo:
```
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
```
### `editarTexto.cpp`
- Aquí se encuentran funciones responsables de la manipulación del texto dentro del QTextEdit (nombrado como `editorDeTexto`) en la libreria QTextEdit. Esto incluye funciones para agregar como tamaño, color, fuentes, entre otros.
- Ejemplo:
```
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
Este proyecto está bajo la Licencia Pública General de GNU (GNU GPL) v3.0. Puedes obtener una copia de la licencia en el archivo [LICENSE](archivo_licencia) o visitando el sitio web [Licencia Pública General de GNU](https://www.gnu.org/licenses/gpl-3.0.html).
## Contacto
- **Nombre:** Jhojan Felipe Sanchez Zapata
- **Institución:** Universidad Tecnologica de Pereira
- **Programa:** Ingeniería de Sistemas y Computación 
- **Facultad:** Facultad de Ingenierías
- **Curso:** Programación II
- **Correo Electrónico:** [j.sanchez10@utp.edu.co](mailto:j.sanchez10@utp.edu.co)
- **Perfil en GitHub:** [TuUsuarioGitHub](https://github.com/TuUsuarioGitHub)


- **![Logo de la Universidad Tecnologica de Pereira](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Logo_U.T.P.png/320px-Logo_U.T.P.png)**
=======
¯\\\_(ツ)\_ /¯

(edit, actualizar esto)
>>>>>>> 5ff061f56d04dfbc6bc33a2abd83aa6dd93850a4
