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

private slots:
    void on_actionNuevo_triggered();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalir_triggered();

    void on_actionExportar_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
