#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isProcessing=false;
    isAbort=false;
    jumpVal=new QIntValidator(1,100,this);
    sizeVal=new QIntValidator(1,200,this);

    ui->textHeight->setValidator(sizeVal);
    ui->textWidth->setValidator(sizeVal);
    ui->textJump->setValidator(jumpVal);
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

    if(isProcessing){
        isAbort=true;
        return;
    }

    // controller
    QString input=ui->textInput->text();
    QString output=ui->textOutput->text();
    if(input.length()==0 || output.length()==0){
        QMessageBox::warning(0,"Error","Path Error!");
        return;
    }
    if(ui->textJump->text().length()==0)
        ui->textJump->setText("5");
    if(ui->textWidth->text().length()==0)
        ui->textWidth->setText("50");
    if(ui->textHeight->text().length()==0)
        ui->textHeight->setText("50");
    int jumpStep,width,height;
    sscanf(ui->textJump->text().toStdString().c_str(),"%d",&jumpStep);
    sscanf(ui->textHeight->text().toStdString().c_str(),"%d",&height);
    sscanf(ui->textWidth->text().toStdString().c_str(),"%d",&width);

    try{
        VP=new VideoProcessor(input.toStdString());
    }catch(...){
        QMessageBox::warning(0,"Error","Input Error!");
        return;
    }

    // model
    isProcessing=true;
    ui->btnProcess->setText("Abort");
    faceId=0;

    FGS=new FGSegmentation();

    cv::Mat frame;
    while(!((frame=VP->read()).empty())){
        if(VP->frameId%jumpStep==0){
            cv::resize(frame,frame,Size(640,480));

            FGS->processFrame(frame,ROIs);
            FD.processFrame(frame,ROIs,faces);

            for(auto &face: faces){
                cv::resize(frame(face),tmpFace,Size(width,height));
                cv::imwrite((output+QString("/%1.jpg").arg(faceId++)).toStdString(),tmpFace);
            }

            for(auto &face: faces){
                cv::rectangle(frame,face,Scalar(0,255,0),2);
            }

            // show the frame
            cv::cvtColor(frame,frame,CV_BGR2RGB);
            img=QImage((const unsigned char *)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888);
            ui->lblVideo->setPixmap(QPixmap::fromImage(img));
            ui->lblVideo->resize(ui->lblVideo->pixmap()->size());

            ui->progressBar->setValue(int(round(VP->frameId/VP->total*100)));
        }
        QCoreApplication::processEvents();
        if(isAbort) break;
    }

    delete VP;
    delete FGS;
    QMessageBox::about(0,"Finish","Finish Successfully!");
    ui->progressBar->setValue(100);
    ui->btnProcess->setText("Process");
    isProcessing=false;
    isAbort=false;
}

MainWindow::~MainWindow()
{
    delete jumpVal;
    delete sizeVal;
    delete ui;
}
