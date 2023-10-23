#ifndef CREARARCHIVO_H
#define CREARARCHIVO_H

#include <QDialog>

namespace Ui {
class crearArchivo;
}

class crearArchivo : public QDialog
{
    Q_OBJECT

public:
    explicit crearArchivo(QWidget *parent = nullptr);
    ~crearArchivo();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::crearArchivo *ui;
};

#endif // CREARARCHIVO_H
