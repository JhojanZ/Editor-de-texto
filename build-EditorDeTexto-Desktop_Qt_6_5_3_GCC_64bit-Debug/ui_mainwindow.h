/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionExportar;
    QAction *actionSalir;
    QAction *actionEliminar;
    QAction *actionAcerca_del_Auto;
    QAction *actionComandos;
    QWidget *centralwidget;
    QTextEdit *editorDeTexto;
    QPushButton *negrilla;
    QPushButton *subrayar;
    QPushButton *cursiva;
    QPushButton *color;
    QPushButton *tamano;
    QPushButton *alineadoJustificado;
    QPushButton *alineadoDerecha;
    QPushButton *alineadoCentrado;
    QPushButton *alineadoIzquierda;
    QSpinBox *tamanoLetra;
    QPushButton *tachado;
    QPushButton *aumentarTamano;
    QPushButton *disminuirTamano;
    QFontComboBox *fuentes;
    QFrame *line;
    QPushButton *imprimirPDF;
    QPushButton *deshacer;
    QPushButton *rehacer;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuAcerca_De;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"color: rgb(0, 0, 0);"));
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName("actionNuevo");
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName("actionAbrir");
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName("actionGuardar");
        actionExportar = new QAction(MainWindow);
        actionExportar->setObjectName("actionExportar");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        actionEliminar = new QAction(MainWindow);
        actionEliminar->setObjectName("actionEliminar");
        actionAcerca_del_Auto = new QAction(MainWindow);
        actionAcerca_del_Auto->setObjectName("actionAcerca_del_Auto");
        actionComandos = new QAction(MainWindow);
        actionComandos->setObjectName("actionComandos");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        editorDeTexto = new QTextEdit(centralwidget);
        editorDeTexto->setObjectName("editorDeTexto");
        editorDeTexto->setGeometry(QRect(100, 80, 591, 471));
        editorDeTexto->setAutoFillBackground(false);
        editorDeTexto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        negrilla = new QPushButton(centralwidget);
        negrilla->setObjectName("negrilla");
        negrilla->setGeometry(QRect(110, 10, 31, 25));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("format-text-bold");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        negrilla->setIcon(icon);
        subrayar = new QPushButton(centralwidget);
        subrayar->setObjectName("subrayar");
        subrayar->setGeometry(QRect(150, 10, 31, 25));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("format-text-underline");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        subrayar->setIcon(icon1);
        cursiva = new QPushButton(centralwidget);
        cursiva->setObjectName("cursiva");
        cursiva->setGeometry(QRect(190, 10, 31, 25));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("format-text-italic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        cursiva->setIcon(icon2);
        color = new QPushButton(centralwidget);
        color->setObjectName("color");
        color->setGeometry(QRect(590, 10, 31, 25));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("applications-graphics");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        color->setIcon(icon3);
        tamano = new QPushButton(centralwidget);
        tamano->setObjectName("tamano");
        tamano->setGeometry(QRect(280, 10, 121, 25));
        alineadoJustificado = new QPushButton(centralwidget);
        alineadoJustificado->setObjectName("alineadoJustificado");
        alineadoJustificado->setGeometry(QRect(550, 10, 31, 25));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("format-justify-fill");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        alineadoJustificado->setIcon(icon4);
        alineadoDerecha = new QPushButton(centralwidget);
        alineadoDerecha->setObjectName("alineadoDerecha");
        alineadoDerecha->setGeometry(QRect(510, 10, 31, 25));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("format-justify-right");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        alineadoDerecha->setIcon(icon5);
        alineadoCentrado = new QPushButton(centralwidget);
        alineadoCentrado->setObjectName("alineadoCentrado");
        alineadoCentrado->setGeometry(QRect(470, 10, 31, 25));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("format-justify-center");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        alineadoCentrado->setIcon(icon6);
        alineadoIzquierda = new QPushButton(centralwidget);
        alineadoIzquierda->setObjectName("alineadoIzquierda");
        alineadoIzquierda->setGeometry(QRect(430, 10, 31, 25));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("format-justify-left");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        alineadoIzquierda->setIcon(icon7);
        tamanoLetra = new QSpinBox(centralwidget);
        tamanoLetra->setObjectName("tamanoLetra");
        tamanoLetra->setGeometry(QRect(280, 40, 42, 26));
        tamanoLetra->setMinimum(1);
        tamanoLetra->setValue(12);
        tachado = new QPushButton(centralwidget);
        tachado->setObjectName("tachado");
        tachado->setGeometry(QRect(230, 10, 31, 25));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("format-text-strikethrough");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tachado->setIcon(icon8);
        aumentarTamano = new QPushButton(centralwidget);
        aumentarTamano->setObjectName("aumentarTamano");
        aumentarTamano->setGeometry(QRect(330, 40, 31, 25));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("go-up");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        aumentarTamano->setIcon(icon9);
        disminuirTamano = new QPushButton(centralwidget);
        disminuirTamano->setObjectName("disminuirTamano");
        disminuirTamano->setGeometry(QRect(370, 40, 31, 25));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("go-down");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        disminuirTamano->setIcon(icon10);
        fuentes = new QFontComboBox(centralwidget);
        fuentes->setObjectName("fuentes");
        fuentes->setGeometry(QRect(420, 40, 251, 25));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, -10, 811, 21));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);
        imprimirPDF = new QPushButton(centralwidget);
        imprimirPDF->setObjectName("imprimirPDF");
        imprimirPDF->setGeometry(QRect(630, 10, 31, 25));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("printer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        imprimirPDF->setIcon(icon11);
        deshacer = new QPushButton(centralwidget);
        deshacer->setObjectName("deshacer");
        deshacer->setGeometry(QRect(120, 40, 51, 25));
        QIcon icon12(QIcon::fromTheme(QString::fromUtf8("edit-undo")));
        deshacer->setIcon(icon12);
        rehacer = new QPushButton(centralwidget);
        rehacer->setObjectName("rehacer");
        rehacer->setGeometry(QRect(200, 40, 51, 25));
        QIcon icon13(QIcon::fromTheme(QString::fromUtf8("edit-redo")));
        rehacer->setIcon(icon13);
        MainWindow->setCentralWidget(centralwidget);
        line->raise();
        editorDeTexto->raise();
        negrilla->raise();
        subrayar->raise();
        cursiva->raise();
        color->raise();
        tamano->raise();
        alineadoJustificado->raise();
        alineadoDerecha->raise();
        alineadoCentrado->raise();
        alineadoIzquierda->raise();
        tamanoLetra->raise();
        tachado->raise();
        aumentarTamano->raise();
        disminuirTamano->raise();
        fuentes->raise();
        imprimirPDF->raise();
        deshacer->raise();
        rehacer->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuAcerca_De = new QMenu(menubar);
        menuAcerca_De->setObjectName("menuAcerca_De");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuAcerca_De->menuAction());
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionExportar);
        menuArchivo->addAction(actionEliminar);
        menuArchivo->addAction(actionSalir);
        menuAcerca_De->addAction(actionComandos);
        menuAcerca_De->addAction(actionAcerca_del_Auto);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        actionExportar->setText(QCoreApplication::translate("MainWindow", "Imprimir", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        actionAcerca_del_Auto->setText(QCoreApplication::translate("MainWindow", "Acerca del Autor", nullptr));
        actionComandos->setText(QCoreApplication::translate("MainWindow", "Comandos", nullptr));
        negrilla->setText(QString());
        subrayar->setText(QString());
        cursiva->setText(QString());
        color->setText(QString());
        tamano->setText(QCoreApplication::translate("MainWindow", "Tama\303\261o", nullptr));
        alineadoJustificado->setText(QString());
        alineadoDerecha->setText(QString());
        alineadoCentrado->setText(QString());
        alineadoIzquierda->setText(QString());
        tachado->setText(QString());
        disminuirTamano->setText(QString());
        imprimirPDF->setText(QString());
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuAcerca_De->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
