/********************************************************************************
** Form generated from reading UI file 'creararchivo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREARARCHIVO_H
#define UI_CREARARCHIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_crearArchivo
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *advertencia;
    QLineEdit *NombreArchivo;

    void setupUi(QDialog *crearArchivo)
    {
        if (crearArchivo->objectName().isEmpty())
            crearArchivo->setObjectName("crearArchivo");
        crearArchivo->resize(240, 115);
        buttonBox = new QDialogButtonBox(crearArchivo);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-20, 60, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        advertencia = new QLabel(crearArchivo);
        advertencia->setObjectName("advertencia");
        advertencia->setGeometry(QRect(50, 10, 201, 20));
        NombreArchivo = new QLineEdit(crearArchivo);
        NombreArchivo->setObjectName("NombreArchivo");
        NombreArchivo->setEnabled(true);
        NombreArchivo->setGeometry(QRect(10, 40, 221, 25));
        NombreArchivo->setClearButtonEnabled(true);

        retranslateUi(crearArchivo);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, crearArchivo, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, crearArchivo, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(crearArchivo);
    } // setupUi

    void retranslateUi(QDialog *crearArchivo)
    {
        crearArchivo->setWindowTitle(QCoreApplication::translate("crearArchivo", "Dialog", nullptr));
        advertencia->setText(QCoreApplication::translate("crearArchivo", "\302\277Crear nuevo archivo?", nullptr));
        NombreArchivo->setText(QString());
        NombreArchivo->setPlaceholderText(QCoreApplication::translate("crearArchivo", "Escribe el nombre del archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class crearArchivo: public Ui_crearArchivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARARCHIVO_H
