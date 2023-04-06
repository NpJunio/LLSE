#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <llse.h>

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushInserirFim_clicked();

    void on_pushButtonAcessarFim_clicked();

    void on_pushButtonRetirarFim_clicked();

private:
    Ui::MainWindow *ui;
    hj::LLSE lista;

};
#endif // MAINWINDOW_H

