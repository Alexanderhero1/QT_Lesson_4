#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextEdit"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
        if (path.isEmpty())return;
        QFile file(path);
        if(file.open(QIODevice::ReadWrite))
        {
            QByteArray ba = file.readAll();
            QString text(ba);
            ui->textEdit->setPlainText(text);
        }

}



void MainWindow::on_pushButton_2_clicked()
{

    QString path = QFileDialog::getSaveFileName();
        if (path.isEmpty())return;
        QFile file(path);
        if(file.open(QIODevice::ReadWrite))
        {
            QString text = ui->textEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba,ba.length());
        }


}






