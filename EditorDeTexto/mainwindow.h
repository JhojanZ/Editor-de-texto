#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *tipoTriggerButton;

protected:
    void keyPressEvent(QKeyEvent *evento) override;

private slots:
    void on_actionNuevo_triggered();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalir_triggered();

    void on_actionExportar_triggered();

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

    void on_imprimirPDF_clicked();

    void on_actionComandos_triggered();

    void on_actionAcerca_del_Auto_triggered();

private:
    Ui::MainWindow *ui;

    QString direccionArchivo = "";
    QColor colorSeleccionado;
};
#endif // MAINWINDOW_H
