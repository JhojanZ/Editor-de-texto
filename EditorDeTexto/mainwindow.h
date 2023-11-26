    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <QApplication>
#include <QString>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>
#include <QFontDatabase>
#include <QColorDialog>
#include <QKeyEvent>
#include <QImage>
#include <QStandardItemModel>


#include <QTextEdit>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class VentanaPrincipal; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void guardarArchivo(QString nombreArchivo);

    void alinear(Qt::AlignmentFlag modo);

    void infoVentana(QString mensaje);

    void guardarPDF(QString direccionArchivo);

    //void contextMenuEvent(QContextMenuEvent *event) override;

private:
    QPushButton *tipoTriggerButton;

protected:
    void keyPressEvent(QKeyEvent *evento) override;

private slots:
    //funcionesArchivos
    void on_actionNuevo_triggered();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalir_triggered();

    void on_actionExportar_triggered();

    void on_imprimirPDF_clicked();

    void on_guardar_clicked();

    //editarTexto
    void on_subrayar_clicked();

    void on_negrilla_clicked();

    void on_cursiva_clicked();

    void on_color_clicked();

    void on_tamano_clicked();

    void on_alineadoCentrado_clicked();

    void on_alineadoDerecha_clicked();

    void on_alineadoIzquierda_clicked();

    void on_alineadoJustificado_clicked();

    void on_tachado_clicked();

    void on_aumentarTamano_clicked();

    void on_disminuirTamano_clicked();

    void on_actionEliminar_triggered();

    void on_fuentes_currentFontChanged(const QFont &f);

    void on_deshacer_clicked();

    void on_rehacer_clicked();

    void on_listaBolitas_clicked();

    //ventanasEmergentes
    void on_actionComandos_triggered();

    void on_actionAcerca_del_Auto_triggered();

    void on_tamanoLetra_valueChanged(int arg1);

    void on_tamanoDeLetra_currentIndexChanged(int index);

private:
    Ui::VentanaPrincipal *ui;

    QString direccionArchivo = "";
    bool listaBolita = false;
    int tamanoLetra = 12;
};
#endif // MAINWINDOW_H
