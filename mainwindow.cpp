#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::inputFile(){
    QString path=QFileDialog::getOpenFileName(0,"Input AVI",QString(),"*.avi");
    if(path.length()!=0)
        ui->textInput->setText(path);
}

void MainWindow::outputDir(){
    QString path=QFileDialog::getExistingDirectory(0,"Output DIR");
    if(path.length()!=0)
        ui->textOutput->setText(path);
}

void MainWindow::process(){
    QString input=ui->textInput->toPlainText();
    QString output=ui->textOutput->toPlainText();
    if(input.length()==0 || output.length()==0){
        QMessageBox::warning(0,"Error","Path Error!");
        return;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
