#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>
#include <QColor>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

   ui->textEditFinal->setText(lista.obterDadosLLSE());
   ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInserirInicio_clicked()
{
    bool ok;
    // obtém o valor digitado pelo usuário
    QString valorTexto = ui->lineEdit->text();
    int valor = valorTexto.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erro", "Valor inválido. Insira um valor inteiro.");
        return;
    }
    // insere o valor na lista e exibe os dados no QTextEdit
    lista.inserirInicio(valor);
    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));
    ui->lineEdit->clear();

}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try{
    // remove o primeiro elemento da lista membro
    ui->lineEdit->setText(QString::number(lista.retirarInicio()));
    //lista.retirarInicio();

    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));

    }catch (QString &erro) {
        // exibe mensagem de erro se a lista estiver vazia
        QMessageBox::critical(this, "Erro", "Lista está vazia");
}
}

void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try {
        // obtém o primeiro elemento da lista membro e exibe na linha de texto
        int valor = lista.acessarInicio();
        ui->lineEdit->setText(QString::number(valor));
    } catch (QString &erro) {
        // exibe mensagem de erro se a lista estiver vazia
         QMessageBox::critical(this, "Erro", "Lista está vazia");
    }
    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));
}

void MainWindow::on_pushInserirFim_clicked()
{
    bool ok;
    // obtém o valor digitado pelo usuário
    QString valorTexto = ui->lineEdit->text();
    int valor = valorTexto.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erro", "Valor inválido. Insira um valor inteiro.");
        return;
    }
    // insere o valor na lista e exibe os dados no QTextEdit
    lista.inserirFim(valor);
    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));
    ui->lineEdit->clear();

}


void MainWindow::on_pushButtonAcessarFim_clicked()
{
    try {
        // obtém o ultimo elemento da lista membro e exibe na linha de texto
        int valor = lista.acessarFim();
        ui->lineEdit->setText(QString::number(valor));
    } catch (QString &erro) {
        // exibe mensagem de erro se a lista estiver vazia
         QMessageBox::critical(this, "Erro", "Lista está vazia");
    }
    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));
}


void MainWindow::on_pushButtonRetirarFim_clicked()
{
    try{
    // remove o ultimo elemento da lista membro
    ui->lineEdit->setText(QString::number(lista.retirarFim()));
    //lista.retirarInicio();

    ui->textEditFinal->setText(lista.obterDadosLLSE());
    ui->lineEditQLE->setText(QString::number( lista.getQuantidadeElementos()));

    }catch (QString &erro) {
        // exibe mensagem de erro se a lista estiver vazia
        QMessageBox::critical(this, "Erro", "Lista está vazia ");
}
}

